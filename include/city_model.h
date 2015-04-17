/**
    @file city_model.h
    @a class that tracks the cities 
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

#ifndef city_model_H
#define city_model_H

#include <random>
#include <chrono>
#include "generator_data_types.h"

// We are hard-wiring the cities.
// When we start reading in from files, that will be
// the time to use vectors, variable sizes, and whatnot
#define NUM_CITIES 34
//City, Country, Pop, {Lat,Long}, Direction to Coast (1=N 2=E 4=S 8=W)
static s_city city_list[NUM_CITIES] = {
  {"Tokyo",		"Japan", 	36923000, {35.6895000, 139.6917100}, 2, JAPAN},
  {"Seoul",		"South Korea", 	25258000, {37.5660000, 126.9784000}, 8, KOREA},
  {"Shanghai", 		"China", 	24750000, {31.2222200, 121.4580600}, 2, CHINA},
  {"New York", 		"United States",23484225, {40.7142700, -74.0059700}, 2, ENGL},
  {"Delhi", 		"India", 	21753486, {28.6538100, 77.2289700}, 0, INDIA},
  {"Mexico City",	"Mexico", 	21178959, {19.428470,  -99.1276600}, 0, LATIN},
  {"Beijing", 		"China", 	21148000, {39.9075000, 116.3972300}, 0, CHINA},
  {"Mumbai", 		"India", 	20998395, {19.0728300, 72.8826100}, 8, INDIA},
  {"São Paulo", 	"Brazil", 	20935204, {-23.5475000,-46.6361100}, 4 , LATIN},
  {"Jakarta", 		"Indonesia", 	20000000, {-6.2146200, 106.8451300}, 1 , INDONESIA},
  {"Osaka/Kobe/Kyoto", 	"Japan", 	19342000, {34.6937400, 135.5021800}, 8, JAPAN},
  {"Cairo", 		"Egypt", 	16292269, {30.0626300, 31.2496700}, 0, MIDEAST},
  {"Kolkata", 		"India", 	14617882, {22.5626300, 88.3630400}, 0, INDIA},
  {"Bangkok", 		"Thailand", 	14565547, {13.7539800, 100.5014400}, 4, THAI},
  {"İstanbul", 		"Turkey", 	14307018, {41.0138400, 28.9496600}, 5, TURKEY},
  {"London", 		"United Kingdom",13879757,{51.5085300, -0.1257400}, 2, ENGL},
  {"Los Angeles", 	"United States",13131431, {34.0522300, -118.2436800}, 8, ENGL},
  {"Buenos Aires", 	"Argentina",	13074000, {-34.6131500,-58.3772300}, 2, LATIN},
  {"Dhaka", 		"Bangladesh", 	12797394, {23.7104000, 90.4074400}, 0 , BANGLADESH},
  {"Paris", 		"France", 	11978363, {48.8534100, 2.3488000}, 0, FRANCE},
  {"Rio de Janeiro",	"Brazil", 	11973505, {-22.9027800,-43.2075000}, 6, LATIN},
  {"Manila", 		"Philippines", 	11855975, {14.6042000, 120.9822000}, 8, PHILIPPINE},
  {"Rhine-Ruhr", 	"Germany", 	11470000, {51.4565700, 7.0122800}, 0, GERMANY},
  {"Lima", 		"Peru", 	 9735587, {-12.0431800,-77.0282400}, 8, LATIN},
  {"Chicago", 		"United States", 9537289, {41.8500300, -87.6500500}, 2, ENGL},
  {"Bogotá", 		"Columbia", 	 9512407, { 4.6097100, -74.0817500}, 0, LATIN},
  {"Nagoya", 		"Japan", 	 9107000, {35.1814700, 136.9064100}, 4, JAPAN },
  {"Chennai", 		"India", 	 8917749, {13.0878400, 80.2784700}, 2 , INDIA},
  {"Bangalore", 	"India", 	 8728906, {12.9719400, 77.5936900}, 0, INDIA},
  {"Tehran", 		"Iran", 	 8293140, {35.6943900, 51.4215100}, 0, MIDEAST},
  {"Milan", 		"Italy", 	 8123020, {45.4642700, 9.1895100}, 0, ITALY },
  {"Hyderabad", 	"India", 	 7749334, {17.3840500, 78.4563600}, 0, INDIA},
  {"Pune", 		"India", 	 7541946, {18.5195700, 73.8553500}, 0 , INDIA},
  {"Hong Kong", 	"Hong Kong", 	 7234800, {22.2855200, 114.1576900}, 14, CHINA}
};


class c_city_model {
public:
  int select_city(double p) {
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return NUM_CITIES-1;

    for (int i = 0; i < NUM_CITIES; i++) 
      if (p < cdf[i]) return i;

    // We really shouldn't get to this point, but
    // it's good to have defined behavior if the
    // cdf is screwed up somehow, although throwing
    // errors would be better. 
    return NUM_CITIES-1;
  }

  s_city lookup(short int n) {return city_list[n];};
  c_city_model() {
    make_cdf();
  };
private:

  double cdf[NUM_CITIES];

  void make_cdf() {
    int i;
    double total = 0;
    for (i = 0; i < NUM_CITIES; i++) {
      total += (double) city_list[i].population;
    } 

    cdf[0] = ((double) city_list[0].population) / total;
    for (i = 1; i < NUM_CITIES; i++) {
      cdf[i] = cdf[i-1]+((double) city_list[i-1].population) / total;
    } 

    // Eliminate roundoff error at the upper limit
    cdf[NUM_CITIES-1] = 1.0;
  }

};

#endif
