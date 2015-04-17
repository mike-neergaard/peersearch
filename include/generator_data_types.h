/**
    @file generator_data_typea.h
    @brief generally useful structures for data generation
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

#ifndef generator_data_types_H
#define generator_data_types_H

#include<string>
#include <vector>

#define NORTH 1
#define EAST 2
#define SOUTH 4
#define WEST 8

typedef struct {
  double lat;
  double lng;
} s_latlong;

typedef struct {
  double age;
  s_latlong latlong;
  short int city;

  // name is indexed per region
  // The region is derived from the city
  int name;
} s_data_record;

typedef struct {
  std::string name;
  std::string roman_name;
} s_name;

typedef struct {
  std::string name;
  std::string country;
  int population;
  s_latlong latlong;
  int boundaries;
  int region;
} s_city;


//City, Country, Pop, {Lat,Long}, Direction to Coast (1=N 2=E 4=S 8=W)
enum { JAPAN, KOREA, CHINA, ENGL, INDIA, LATIN, INDONESIA, MIDEAST, THAI, TURKEY, BANGLADESH, FRANCE, PHILIPPINE, GERMANY, ITALY};

#endif
