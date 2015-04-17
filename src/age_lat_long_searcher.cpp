/**
    @file space_partition_tree.cpp
    @brief searches on the basis of age, lat, and long
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

#include "age_lat_long_searcher.h"


void c_age_lat_long_searcher::add(s_data_record &record, int index){

// This is the glue method that reads a specific format in and 
// extracts the dimensions we will use for search, placing them
// in a dat[] array, and applying scaling

  record_ptr r;
  r.index = index;
  r.dat[0] = record.age;
  r.dat[1] = record.latlong.lat;
  r.dat[2] = record.latlong.lng;
  
  add_record(r);
}

