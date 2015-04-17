/**
    @file search_data_types.h
    @brief generally useful structures for data search
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

#ifndef search_data_types_H
#define search_data_types_H

#define S_DIM 3

//enum {AGE, LAT, LNG};
enum {MIN, MAX};
enum {BELOW, ABOVE};



class record_ptr{
public:
  int index;
  double dat[S_DIM];
  void sort_by(int val) {sort_dim = val;}
  bool operator<(const record_ptr a)const {return dat[sort_dim] < a.dat[sort_dim];};
private:
  int sort_dim;
};

class record_by_dist {
public:
  record_by_dist(record_ptr r, double dat[S_DIM]){
     index = r.index;
     dist =  0;
     // taxicab distance
     for (int i = 0; i < S_DIM; i++) {
     	dist +=  (dat[i] > r.dat[i] ? dat[i] - r.dat[i] : r.dat[i] - dat[i]);
     }
            
  }

  bool operator<(const record_by_dist a)const{ return dist<a.dist;};
  double dist;
  int index;
};


typedef struct  bsp_node{
  bsp_node* L;
  bsp_node* R;
  double T;
  int long_dim;

  // partition boundaries
  double cutoff[S_DIM][2];
  std::set<record_ptr>* cover[S_DIM][2];

  // I can't believe I made this work
  // This set will be sorted in whatever dimension we like at the moment
  std::set<record_ptr> *records;
} bsp_node;


  
#endif
