/**
    @record_store.cpp 
    @implement class that contains the records
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
#include <iomanip>
#include <map>
#include "record_store.h"
#include "name_model.h"


c_record_store::c_record_store(){
  data_record.clear(); 
  cities = NULL;
}

c_record_store::c_record_store(c_city_model *x){
  data_record.clear(); 
  cities = x;
}

void c_record_store::set_cities(c_city_model *x) {
  cities = x;
}

s_data_record c_record_store::retrieve(int i) {
  return data_record.find(i)->second;
}

/// Add a record
// If we ever deleted records we would need a better key scheme
int c_record_store::add(s_data_record x) {
     int i = data_record.size();
     data_record.insert(std::pair<int,s_data_record>(i,x));
     return i;
}

void c_record_store::print_short_record(std::ostream &outstream, int i){
  s_city city = cities->lookup(data_record[i].city);
  s_data_record t = data_record.find(i)->second;

  outstream<<get_name(t.name, city.region)<<":"<<std::endl;

  outstream << (int)(t.age+0.5)<<", "<<
    std::fixed << std::setprecision(5) << t.latlong.lat << ", "<<t.latlong.lng;

  outstream<< ", "<<city.name<<", "<<city.country;
  outstream << std::endl;
}

std::string  c_record_store::get_name(int name_index, int region) {
  //std::cerr << "I am about to look up a name: "<<name_index<<std::endl;
  if (region == MIDEAST) {
    return arabic::give_name(name_index);
  } else if (region == JAPAN) {
    return japan::give_name(name_index);
  } else if (region == KOREA) {
    return korea::give_name(name_index);
  } else if (region == CHINA) {
    return china::give_name(name_index);
  } else if (region == ENGL) {
    return engl::give_name(name_index);
  } else if (region == INDIA) {
    return india::give_name(name_index);
  } else if (region == LATIN) {
    return latin::give_name(name_index);
  } else if (region == INDONESIA) {
    return indonesia::give_name(name_index);
  } else if (region == THAI) {
    return thai::give_name(name_index);
  } else if (region == TURKEY) {
    return turkey::give_name(name_index);
  } else if (region == BANGLADESH) {
    return bangladesh::give_name(name_index);
  } else if (region == FRANCE) {
    return france::give_name(name_index);
  } else if (region == PHILIPPINE) {
    return philippine::give_name(name_index);
  } else if (region == GERMANY) {
    return germany::give_name(name_index);
  } else if (region == ITALY) {
    return italy::give_name(name_index);
  }
  return "No name found";
}

void c_record_store::print_record(std::ostream &outstream, int i){

  s_city city = cities->lookup(data_record[i].city);
   
  s_data_record t = data_record.find(i)->second;
  outstream<<get_name(t.name, city.region)<<std::endl;
  outstream << 
    "Age: "<< (int)(t.age+0.5)<<std::endl<<
    std::fixed << std::setprecision(5) <<
    "Location: ("<<t.latlong.lat<<", "<<t.latlong.lng<<")\n";

  outstream<< city.name<<", "<<city.country<<std::endl;
  outstream << std::endl;
}

