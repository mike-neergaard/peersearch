/**
    @file age_lat_long_searcher.h
    @brief the searcher class that glues the data together with c_bsp
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

#ifndef age_lat_long_searcher_H
#define age_lat_long_searcher_H

#include "space_partition_tree.h"
#include "generator_data_types.h"

class c_age_lat_long_searcher : public c_bsp {
public:
  using c_bsp::c_bsp;
  void add(s_data_record &, int);
};

#endif
