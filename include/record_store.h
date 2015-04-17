/**
    @record_store.h 
    @brief class that contains records
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

#ifndef record_store_H
#define record_store_H

#include <iostream>
#include <map>
#include "generator_data_types.h"
#include "city_model.h"


/// This class contains all of the records
class c_record_store {
public:
  c_record_store();
  c_record_store(c_city_model *x);
  void set_cities(c_city_model *x);

  s_data_record retrieve(int i);

  // Add a record, autogen key
  // If we ever deleted records we would need a better key scheme
  int add(s_data_record); 

  void print_short_record(std::ostream &outstream, int i);
  void print_record(std::ostream &outstream, int i);
  void clear(void) {data_record.clear();};

private:
  std::map<int, s_data_record> data_record;
  c_city_model *cities;
  std::string get_name(int, int);
  
};

#endif
