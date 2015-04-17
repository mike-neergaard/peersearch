/**
    @file record_generator.h
    @brief class headers to generate a single random record
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

#ifndef record_generator_H
#define record_generator_H

#include <random>
#include "generator_data_types.h"
#include "city_model.h"


class c_record_generator {
public:
  c_record_generator();
  c_record_generator(unsigned seed);
  c_record_generator(c_city_model *x);
  void set_city_model(c_city_model *x);
  s_data_record generate_record(void);

private:
  s_data_record data_record;
  std::mt19937_64 rand_generator;
  void initialize();

  int get_random_name(int);

  c_city_model *cities;

  std::weibull_distribution<double> age_distribution;
  std::normal_distribution<double> population_distribution;
  // No coastal distribution, because we're truncating the normal curve
  std::uniform_real_distribution<double> isthmus_distribution;
  std::uniform_real_distribution<double> zero_one;

  // Select an age according to age distribution
  double get_random_age(void);

  // Select a city according to size distribution
  int get_random_city() {return cities->select_city(zero_one(rand_generator));};

  // Lookup city index
  s_city lookup_city(int i) {return cities->lookup(i);};

  // Select a lat-long at from the current city's population distribution
  s_latlong get_random_coords();
  
};

#endif 
