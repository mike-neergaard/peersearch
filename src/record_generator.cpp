/**
    @file record_generator.cpp
    @brief class to generate a single random record
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

#include "record_generator.h"
#include "name_model.h"


c_record_generator::c_record_generator(unsigned seed): 
  rand_generator( seed ),
  age_distribution(1.32,32.9),
  population_distribution (0, 0.6),
  isthmus_distribution(0.1), 
  zero_one(0,1)
{
  initialize();
}

c_record_generator::c_record_generator(void):
  rand_generator( std::chrono::system_clock::now().time_since_epoch().count()),
  age_distribution(1.32,32.9),
  population_distribution (0, 0.6),
  isthmus_distribution(0.1), 
  zero_one(0,1)
{
  initialize();
}

c_record_generator::c_record_generator(c_city_model *x):
  rand_generator( std::chrono::system_clock::now().time_since_epoch().count()),
  age_distribution(1.32,32.9),
  population_distribution (0, 0.6),
  isthmus_distribution(0.1), 
  zero_one(0,1)
{
  cities = x;
  initialize();
}

void c_record_generator::initialize(void) {
 // General initialize everything stuff goes here
 ;
}


int c_record_generator::get_random_name(int region){
  if (region == MIDEAST) {
    return arabic::select_name(zero_one(rand_generator));
  } else if (region == JAPAN) {
    return japan::select_name(zero_one(rand_generator));
  } else if (region == KOREA) {
    return korea::select_name(zero_one(rand_generator));
  } else if (region == CHINA) {
    return china::select_name(zero_one(rand_generator));
  } else if (region == ENGL) {
    return engl::select_name(zero_one(rand_generator));
  } else if (region == INDIA) {
    return india::select_name(zero_one(rand_generator));
  } else if (region == LATIN) {
    return latin::select_name(zero_one(rand_generator));
  } else if (region == INDONESIA) {
    return indonesia::select_name(zero_one(rand_generator));
  } else if (region == MIDEAST) {
    return arabic::select_name(zero_one(rand_generator));
  } else if (region == THAI) {
    return thai::select_name(zero_one(rand_generator));
  } else if (region == TURKEY) {
    return turkey::select_name(zero_one(rand_generator));
  } else if (region == BANGLADESH) {
    return bangladesh::select_name(zero_one(rand_generator));
  } else if (region == FRANCE) {
    return france::select_name(zero_one(rand_generator));
  } else if (region == PHILIPPINE) {
    return philippine::select_name(zero_one(rand_generator));
  } else if (region == GERMANY) {
    return germany::select_name(zero_one(rand_generator));
  } else if (region == ITALY) {
    return italy::select_name(zero_one(rand_generator));
  }
  // We shouldn't get to here.  Put in a throw if here's time
  std::cerr << "We fell out of the region case statement"<<std::endl;
  return 3;
}

  
double c_record_generator::get_random_age(void){
  double sampled_age = age_distribution(rand_generator);
  // reject ages over 120
  while (sampled_age > 120) sampled_age = age_distribution(rand_generator);
  return sampled_age;
}

s_data_record c_record_generator::generate_record(void){
  s_data_record ret_val;
 
  ret_val.age = get_random_age();

  double rand_lat = population_distribution(rand_generator);
  double rand_long = population_distribution(rand_generator);

  ret_val.city = get_random_city();
  s_city city = lookup_city(ret_val.city);

  ret_val.name = get_random_name(city.region);

  if (city.boundaries & (NORTH^SOUTH)){
    // There is at least one coast to the N or S
    if (city.boundaries == SOUTH) {
      // There's a coast to the South
      // Draw from a one-sided positive distribution
      if (rand_lat < 0) rand_lat = -rand_lat;
    } else if (city.boundaries == NORTH) {
      // There's a coast to the North
      // Draw from a one-sided negative distribution
      if (rand_lat > 0) rand_lat = -rand_lat;
    } else {
      // Isthmus!
      // Draw from a narrow two-sided distribution
      rand_lat = isthmus_distribution(rand_generator);
    }
  }
    
  if (city.boundaries & (EAST^WEST)){
    // There is at least one coast to the E or W
    if (city.boundaries == WEST) {
      // There's a coast to the West
      // Draw from a one-sided positive distribution
      if (rand_long < 0) rand_long = -rand_long;
    } else if (city.boundaries == EAST) {
      // There's a coast to the East
      // Draw from a one-sided negative distribution
      if (rand_long > 0) rand_long = -rand_long;
    } else {
      // Isthmus!
      // Draw from a narrow two-sided distribution
      rand_long = isthmus_distribution(rand_generator);
    }
  }
    
  rand_lat += city.latlong.lat;

  //latitude is in the range [-90,90]
  if (rand_lat > 90.0) {
    // We crossed over the North Pole?  Really??
    rand_lat = 90.0 - (rand_lat - 90.0);
    // We flipped east and west as well (+180 degrees), 
    // which also means we went the wrong way from 
    // this somewhat theoretical coast passing through the pole.
    rand_long = -rand_long + 180; 
  } else if (rand_lat < -90.0) {
    // We crossed over the South Pole. Ok...
    rand_lat = -90.0 - (rand_lat + 90.0);
    // We flipped east and west as well
    rand_long = -rand_long + 180; 
  }

  rand_long += city.latlong.lng;

  // longitude is in the range [-180, 180)
  while(rand_long >= 180) rand_long -= 180;
  while(rand_long < -180) rand_long += 180;
  ret_val.latlong.lat = rand_lat;
  ret_val.latlong.lng = rand_long;

  return ret_val;

}
