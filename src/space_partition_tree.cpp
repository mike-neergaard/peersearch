/**
    @file space_partition_tree.cpp
    @brief implements a space partition tree for fast search
    @author Mike Neergaard <mike.neergaard@gmail.com>
    @version 1.0

    @section LICENSE
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Copyright (C) 2015  Mike Neergaard

*/

#include <iostream>
#include <vector>
#include "space_partition_tree.h"


c_bsp::c_bsp(double input_cutoff[S_DIM][2], double input_dist_scaling_factors[S_DIM]){

  int i,j;

  // Set up some defaults
  // experimentally generated for a specific case
  // Not guaranteed optimal for any case
  include_cover = false;
  limit_return_set = true;;
  final_node_size = (1<<12);
  processing_node_size = (1<<20);
  cover_overlap_radius = 0.016;
  trim_factor = 10;


  root.records = new std::set<record_ptr>;

  // Root doesn't need to extend its cover, but these
  // sets should exist - later code will expect it
  for (i = 0; i < S_DIM; i++){

    // I try to carry on no matter what.  But really, this is very very wrong
    if ( input_dist_scaling_factors[i] < 0) {
      std::string complaint = "Attmpted to set a negative distance comparison factor on dimension ";
      complaint += i;
      complaint += "in c_bsp constructor";
      throw std::out_of_range(complaint);
    }

    dist_scaling_factor[i] = input_dist_scaling_factors[i];

    for (j = 0; j < 2; j++){
      root.cover[i][j] = new std::set<record_ptr>;;
      cutoff[i][j] = input_cutoff[i][j];
    }
  }
  // Set the cover overlap distance to about 1km
  reset();
}

c_bsp::~c_bsp() {
  clear();
}

void c_bsp::reset(){
  // Stuff to reset at the beginning of every data read
  root.L = NULL;
  root.R = NULL;
  root.T = 0.0;
  int i,j;
  for (i = 0; i < S_DIM; i++){
    for (j = 0; j < 2; j++) {
      root.cutoff[i][j] = cutoff[i][j]*dist_scaling_factor[i];
    }
  }
  

  find_long_dim(root);

  data_done = false;
  split_counter = 0;
  data_size = 0;
  node_split_size = processing_node_size;
  max_leaf_size = total_leaf_size = leaf_count = 0;
  
}

void c_bsp::clear(){
  std::cerr << "Clearing space partition tree... ";
  clear(root);
  reset();
  std::cerr << "Done.\n";
}

void c_bsp::clear(bsp_node node) {
  if (node.L == NULL) {
    // We're at a leaf
    // clear the map
    (*node.records).clear();
    // free the space
    return;

  } else {
    clear(*node.L);
    node.L = NULL;
    
    clear(*node.R);
    node.R = NULL;
  }
}
  
void c_bsp::process_data(void) {
  data_done = true;
  std::cerr << "Please wait while we prepare this dataset for first use.\n";
  std::cerr << "data_size: "<<data_size<<std::endl;
  std::cerr << "final_node_size: "<< final_node_size << std::endl;
  node_split_size = final_node_size;
  split_search(root);
  std::cerr << "\nDone.\n";
  find_leaf_size(root);
  std::cerr << "Average leaf size: "<< ((double) total_leaf_size)/leaf_count;
  std::cerr << "\nMaximum leaf size: "<< max_leaf_size<<std::endl;
}



///If we are refining our split, we need to find our way down to the data
void c_bsp::split_search(bsp_node &parent) {
  if (parent.L == NULL) {
    // Good news, we found the data
    if ( (*parent.records).size() > node_split_size) {
      split(parent);
    }
  } else {
    split_search(*(parent.L));
    split_search(*(parent.R));
  }
}

void c_bsp::find_leaf_size(bsp_node &parent) {
  if (parent.L == NULL) {
    int leaf_size = (*parent.records).size() ;
    if (leaf_size > max_leaf_size) max_leaf_size = leaf_size;
    total_leaf_size += leaf_size;
    leaf_count++;
  } else {
    find_leaf_size(*(parent.L));
    find_leaf_size(*(parent.R));
  }
}
  
    

/// If a leaf has grown too large, it needs to be split!
void c_bsp::split(bsp_node &parent){

  int i,j;
  int total_size, left_split_size;

  split_counter++;
  if (1) {
  //if (data_done) {
    j = data_size / final_node_size;
    i = 0;
    while (j>>i) i++;
    j = 1<<i;
    std::cerr << "\r                                                                        ";
    std::cerr << "\rSplit count: "<<split_counter<<" of about "<< j-1<<".... ";
  }

//std::cerr << "\nSplit "<<(*parent.records).size();
  bsp_node *R = new bsp_node;
  bsp_node *L = new bsp_node;
  parent.L = L;
  parent.R = R;
  int p_long_dim = parent.long_dim;
  L->records = new std::set<record_ptr>;
  R->records = new std::set<record_ptr>;

  R->R = L->R = R->L = L->L = NULL;

  for (i = 0; i < S_DIM; i++) {
    for (j = MIN; j <= MAX; j++) {
      R->cutoff[i][j] = parent.cutoff[i][j];
      L->cutoff[i][j] = parent.cutoff[i][j];
    }
  }

  // We need to find the split point, so we'll
  // iterate through the first half of the set
  total_size = (*parent.records).size();
  left_split_size = total_size>>1;
  

  std::set<record_ptr>::iterator it = (*parent.records).begin();
  for (i = 0; i < left_split_size; i++) {
    ++it;
  }
  record_ptr r = (*it);
  parent.T = (*it).dat[parent.long_dim];
  L->cutoff[p_long_dim][MAX] = parent.T;
  R->cutoff[p_long_dim][MIN] = parent.T;


  // Find the long dimensions, along which we will later split
  find_long_dim(*L);
  find_long_dim(*R);
   

  // copy records from the node to the children
  it = (*parent.records).begin();


  // This will hold R's cover data for this split
  if(include_cover) R->cover[parent.long_dim][BELOW] = new std::set<record_ptr>;

  //First the left child
  for (i = 0; i < left_split_size; i++) {
    insert_record((*it), L);
    // Generate the new cover data for this split
    if (include_cover && (parent.T - (*it).dat[p_long_dim] < cover_overlap_radius)) {
      (*R->cover[parent.long_dim][BELOW]).insert((*it));
    }
    ++it;
  }

  std::cerr << "L";
  // This will hold L's cover data for this split
  if (include_cover) L->cover[parent.long_dim][ABOVE] = new std::set<record_ptr>;

  // Then the right
  for(i = left_split_size; i < total_size; i++) {
    insert_record((*it), R);
    // Generate the new cover data for this split
    if (include_cover && ((*it).dat[p_long_dim] - parent.T < cover_overlap_radius) ){
      (*L->cover[parent.long_dim][ABOVE]).insert((*it));
    }
    ++it;
  }
  if (include_cover) handle_cover_split(parent);
  std::cerr<<"R";

//std::cerr << " into "<<(*L->records).size();
//std::cerr << " + "<<(*R->records).size()<<std::endl;

  // free up memory
  (*parent.records).clear();


  // Do recursive split
  if ( (*L->records).size() > node_split_size) {
    split(*L);
  } else if (data_done) {
    //This is a final node
    trim_cover(*L);
  }
  if ( (*R->records).size() > node_split_size) {
    split(*R);
  } else if (data_done) {
    //This is a final node
    trim_cover(*R);
  }
  
  return;
}

int c_bsp::trim_size(){
  // You can keep node_split_size/trim_factor cover points,
  // split between 6 faces
  return (node_split_size / 6.0) / trim_factor;
}

void c_bsp::trim_cover(bsp_node &N) {

  if (!include_cover) return;
  int max_trim = trim_size();
  int i,j ;

  // bad things happen when you try to erase from
  // an empty set
  if (max_trim < 0) max_trim = 0;

  std::set<record_ptr>::iterator it;
  for (i = 0; i < S_DIM; i++) {
    for (j = 0; j < 2; j++) {
      // erase the largest elements until we come down to size
      while( (*N.cover[i][j]).size() > max_trim){
         (*N.cover[i][j]).erase( --(*N.cover[i][j]).end() );
      }
    }
  }
}

void c_bsp::handle_cover_split(bsp_node &P){
// We are splitting the data, which means that the covering data must also be
// split
  int i,j;

  std::set<record_ptr>::iterator it;
  for (i = 0; i < S_DIM; i++) {
    if (i != P.long_dim) {
      for (j = 0; j < 2; j++) {
        P.L->cover[i][j] = new std::set<record_ptr>;
        P.R->cover[i][j] = new std::set<record_ptr>;
        for (it = (*P.cover[i][j]).begin(); it!=(*P.cover[i][j]).end(); it++){
          if ((*it).dat[P.long_dim] < P.T) {
            (*P.L->cover[i][j]).insert(*it);
          } else {
            (*P.R->cover[i][j]).insert(*it);
          } 
        }
        // P has transferred all knowledge. It is done with this cover data
        (*P.cover[i][j]).clear(); 
      }
    } else {
       // We already generated covering data for split
       // We have to copy the below cover data to L and the above cover to R
        P.L->cover[i][BELOW] = new std::set<record_ptr>;
        P.R->cover[i][ABOVE] = new std::set<record_ptr>;
        for (it = (*P.cover[i][BELOW]).begin(); it!=(*P.cover[i][BELOW]).end(); it++){
            (*P.L->cover[i][BELOW]).insert(*it);
        }
        // clean up memory
        (*P.cover[i][BELOW]).clear(); 
        for (it = (*P.cover[i][ABOVE]).begin(); it!=(*P.cover[i][ABOVE]).end(); it++){
            (*P.L->cover[i][ABOVE]).insert(*it);
        }
        // clean up memory
        (*P.cover[i][ABOVE]).clear(); 
    }
        
  } // endfor

}
    
void c_bsp::insert_record(record_ptr r, bsp_node *N){
  r.sort_by(N->long_dim);
  (*N->records).insert(r);
}

void c_bsp::find_long_dim(bsp_node &N) {
  double val;
  double max = N.cutoff[0][MAX] - N.cutoff[0][MIN];
  N.long_dim = 0;

  for (int i = 0; i < S_DIM; i++) {
    val = N.cutoff[0][MAX] - N.cutoff[0][MIN];
    if (val > max) {
      max = val;
      N.long_dim = i;
    }
  }
   
}
    
    
/// Add an new entry to the tree
void c_bsp::add_record(record_ptr &r) {
  // Adding record from outside
  // If we're starting a new dataset, we need to get rid
  // of the old tree
  if (data_done) {
    clear();
  }

  for (int i = 0; i < S_DIM; i++) {
    r.dat[i] = r.dat[i]*dist_scaling_factor[i];
    if (r.dat[i] < root.cutoff[i][MIN]) r.dat[i] = root.cutoff[i][MIN];
    else if (r.dat[i] > root.cutoff[i][MAX]) r.dat[i] = root.cutoff[i][MAX];
  }

  data_size++;
  add_record(r, root);

}


///Adding a record into the tree
void c_bsp::add_record(record_ptr &r, bsp_node &node) {

  if (node.L == NULL){
    //std::cout << "No child -- adding to this leaf\n";
    // No children means this is a leaf

    // Different sorts, depending on dimension
    r.sort_by(node.long_dim);
    (*node.records).insert(r);

    //std::cout << "Records in this leaf: "<< (*node.records).size() <<std::endl;
    if ((*node.records).size() > node_split_size) {
std::cerr<<std::endl;
      split(node);
std::cerr<<std::endl;
    }
  } else if (r.dat[node.long_dim] < node.T) {
    add_record(r, *node.L);
  } else {
    add_record(r, *node.R);
  }

  return;
}

void c_bsp::find_matches(int N, double dat[S_DIM], std::vector<int> &matches_return) {
  //std::cout << "In find_matches with datasize "<<data_size<<std::endl;
  int i,j;


  
  if (!data_done) process_data();
  for (i = 0; i < S_DIM; i++) {
    // Can't search outside cutoff area
    if (dat[i] < cutoff[i][MIN]) dat[i] = cutoff[i][MIN];
    // Is it ok to allow dat[i] = cutoff[i][MAX]? Think it's ok....
    if (dat[i] > cutoff[i][MAX]) dat[i] = cutoff[i][MAX];
  }

  bsp_node node = root;
  while (node.L != NULL) {
    if (dat[node.long_dim] < node.T) node = *(node.L);
    else (node = *(node.R));
  }

  std::set<record_by_dist> nearby_records;
  std::set<record_ptr>::iterator it;

// This is the space partition data
  for (it=(*node.records).begin();it != (*node.records).end(); it++) {
    record_by_dist r((*it), dat);
    nearby_records.insert(r);
    if (limit_return_set && nearby_records.size() > N) {
         nearby_records.erase( --nearby_records.end() );
    }
  }

  if (include_cover) {
  // Read in the cover data
    for (i = 0; i < S_DIM; i++) {
      for (j = 0; j < 2; j++) {
        for (it= (*node.cover[i][j]).begin() ; it!= (*node.cover[i][j]).begin() ; it++) {
          record_by_dist r((*it), dat);
          nearby_records.insert(r);
          if (limit_return_set && nearby_records.size() > N) {
            nearby_records.erase( --nearby_records.end() );
          }
        }
      }
    }
  }

  std::set<record_by_dist>::iterator jt;
  jt = nearby_records.begin();
  for (int i = 0; i < N; i++) {
    matches_return.push_back((*jt).index);
    jt++;
  }
} 
  
  
