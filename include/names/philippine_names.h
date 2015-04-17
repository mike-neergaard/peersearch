
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

#ifndef philippine_names_H
#define philippine_names_H


static s_name PHILIPPINE_given_name[40] {
{"", "John Paul"},
{"", "John Mark"},
{"", "John Lloyd"},
{"", "John Michael"},
{"", "John Carlo"},
{"", "Mark Anthony"},
{"", "John Rey"},
{"", "John Benedict"},
{"", "John Patrick"},
{"", "John Vincent"},
{"", "Mary Joy"},
{"", "Mary Grace"},
{"", "Jessa Mae"},
{"", "Mary Rose"},
{"", "Angel Mae"},
{"", "Christine Joy"},
{"", "Mary Jane"},
{"", "Trisha Mae"},
{"", "Rose Ann"},
{"", "Mary Ann"},
{"", "Jerome"},
{"", "Adrian"},
{"", "Jayson"},
{"", "Daniel"},
{"", "Nicole"},
{"", "Jasmine"},
{"", "Michelle"},
{"", "Joshua"},
{"", "Christian"},
{"", "Angelo"},
{"", "John"},
{"", "Angelica"},
{"", "Nicole"},
{"", "Justine"},
{"", "Angol"},
{"", "Kyla"},
{"", "Erica"},
{"", "Jessa"},
{"", "Kimberly"},
{"", "Marvin"} };


static s_name PHILIPPINE_surname[] = { {"", "Santos"}, {"", "Reyes"}, {"", "Cruz"}, {"", "Bautista"}, {"", "Ocampo"}, {"", "del Rosario"}, {"", "Gonzales"}, {"", "Aquino"}, {"", "Ramos"}, {"", "Garcia"}, {"", "Lopez"}, {"", "dela Cruz"}, {"", "Mendoza"}, {"", "Pascual"}, {"", "Castillo"}, {"", "Villanueva"}, {"", "Diaz"}, {"", "Rivera"}, {"", "Navarro"}, {"", "Mercado"}, {"", "Morales"}, {"", "Fernández"}, {"", "Marquez"}, {"", "Rodriguez"}, {"", "Sanchez"}, {"", "De León"} };


/// This class gives us the names
class philippine
{ public:
  static std::string give_name(int index) {
    int surnames = 25;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = PHILIPPINE_given_name[g].roman_name + " "+PHILIPPINE_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) {
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) ( 40) * (25)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
