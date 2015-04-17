/**
    @file space_partition_tree.h
    @brief partitions the lat/long/age space for efficient search
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

#ifndef space_partition_tree_H
#define space_partition_tree_H

#include <set>
#include <vector>
//#include <iostream>
#include "search_data_types.h"

/**
  This class searches space of S_DIM dimensions,which is currently hardwired to 3
  in the search_data_types.h header file.
  
  From a programming point of view, it would be possible to go through and change 
  S_DIM to a variable.  At a later time, that might be neat, but since the class
  is written such that the dimension absolutely must set at instantiation time and 
  never changed throughout the life of the instantiation, it's fine with me to 
  require a re-compile .

*/

class c_bsp {
public:
  explicit c_bsp(double[S_DIM][2], double[S_DIM]);
  ~c_bsp();

  void find_matches(int, double[S_DIM], std::vector<int> &);

  void clear();

  void process_data();

  // Do we generate covering data
  bool get_include_cover(void) {return include_cover;};
  void set_include_cover(bool val) {include_cover = val;};

  // What data is eligible to be covering data
  double get_cover_overlap_radius(void) {return cover_overlap_radius;};
  void set_cover_overlap_radius(double val) {cover_overlap_radius = val;};
  
  // How much covering data to retain at the end
  double get_trim_factor(void) {return trim_factor;};
  void set_trim_factor(double val) {trim_factor = val;};

  // Node size for final search tree
  int  get_final_node_size(void){return final_node_size;};
  void set_final_node_size(int val){final_node_size = val;};

  // Max node size while reading
  int  get_processing_node_size(void){return processing_node_size;};
  void set_processing_node_size(int val){processing_node_size = val;};


  //Should put throws and catches for out-of-bounds queries
  double  get_dist_scaling_factor(int i) {
    return dist_scaling_factor[i];};
  void set_dist_scaling_factor(int i, double val) {
    if (i < 0 || i >= S_DIM) return;
    if (val >= 0.0) dist_scaling_factor[i] = val;
  };
 
  //Erase search results we know we won't return while we're looking for more??
  bool get_limit_return_set(void) {return limit_return_set;};
  void set_limit_return_set(bool val) {limit_return_set = val;};

  //Should put throws and catches for out-of-bounds queries
  int get_cutoff(int dim, int side) {return cutoff[dim][side];}
  void set_cutoff(int dim, int side, double val) {
    if (dim < 0 || dim >= S_DIM) return;
    if ((side == MIN) && (val <= cutoff[dim][MAX])) {
      cutoff[dim][side] = val;
    } else if ((side == MAX) && (val <= cutoff[dim][MIN])) {
      cutoff[dim][side] = val;
    }
  }


protected:
  void add_record(record_ptr &);

private:
  void reset();
  void clear(bsp_node);
  void split(bsp_node&);
  void handle_cover_split(bsp_node &);
  void split_search(bsp_node&);
  void find_long_dim(bsp_node &);
  void add_record(record_ptr &, bsp_node &);
  void insert_record(record_ptr , bsp_node *);
  void find_leaf_size(bsp_node &);
  void trim_cover(bsp_node &);
  int trim_size();
  int get_data_size(void) {return data_size;};


  // search tree
  bsp_node root;

  // Internal variables
  int max_leaf_size, total_leaf_size, leaf_count;
  bool data_done;
  int split_counter;
  int data_size;
  int node_split_size;

  // Data characteristics
  double cutoff[S_DIM][2];

  // Search Configuration Parameters
  double dist_scaling_factor[S_DIM];
  double trim_factor;
  int final_node_size;
  int processing_node_size;
  double cover_overlap_radius;
  bool limit_return_set;
  bool include_cover;;

};

#endif
