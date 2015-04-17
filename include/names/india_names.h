
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

#ifndef india_names_H
#define india_names_H

static s_name INDIA_given_name[52] = { 
{"", "Aarav"}, 
{"", "Vivaan"}, 
{"", "Aditya"}, 
{"", "Aaditya"}, 
{"", "Vihaan"}, 
{"", "Arjun"}, 
{"", "Reyansh"}, 
{"", "Muhammad"}, 
{"", "Sai"}, 
{"", "Arnav"}, 
{"", "Ayaan"}, 
{"", "Krishna"}, 
{"", "Ishaan"}, 
{"", "Shaurya"}, 
{"", "Atharv"}, 
{"", "Advik"}, 
{"", "Pranav"}, 
{"", "Advaith"}, 
{"", "Aryan"}, 
{"", "Dhruv"}, 
{"", "Kabir"}, 
{"", "Ritvik"}, 
{"", "Aarush"}, 
{"", "Kayaan"}, 
{"", "Darsh"}, 
{"", "Veer"}, 
{"", "Saanvi"}, 
{"", "Aanya"}, 
{"", "Aadhya"}, 
{"", "Aaradhya"}, 
{"", "Ananya"}, 
{"", "Pari"}, 
{"", "Anika"}, 
{"", "Navya"}, 
{"", "Angel"}, 
{"", "Diya"}, 
{"", "Avani"}, 
{"", "Myra"}, 
{"", "Maira"}, 
{"", "Sara"}, 
{"", "Ira"}, 
{"", "Aahana"}, 
{"", "Anvi"}, 
{"", "Prisha"}, 
{"", "Riya"}, 
{"", "Aarohi"}, 
{"", "Anaya"}, 
{"", "Akshara"}, 
{"", "Eva"}, 
{"", "Shanaya"}, 
{"", "Kyra"}, 
{"", "Siya"}};

static s_name INDIA_surname[5] = { 
{"","Devi"}, 
{"","Singh"}, 
{"","Kumar"}, 
{"","Das"}, 
{"","Kau"} };

/// This class gives us the names
class india { 
public:
  static std::string give_name(int index) {
    int surnames = 5;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = INDIA_given_name[g].roman_name + " "+INDIA_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (52) * (5)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
