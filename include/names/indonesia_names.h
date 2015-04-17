
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

#ifndef indonesia_names_H
#define indonesia_names_H

static s_name INDONESIA_surname[] = { 
{"", "Agusalim"}, 
{"", "Atmadja"}, 
{"", "Atmadjaja"}, 
{"", "Budiaman"}, 
{"", "Budiman"}, 
{"", "Budiono"}, 
{"", "Cahyadi"}, 
{"", "Chandra"}, 
{"", "Darmadi"}, 
{"", "Darmali"}, 
{"", "Dharmawijaya"}, 
{"", "Gunardi"}, 
{"", "Gunawan"}, 
{"", "Hadiman"}, 
{"", "Halim"}, 
{"", "Hardja"}, 
{"", "Hartanto"}, 
{"", "Hartono"}, 
{"", "Hermanto"}, 
{"", "Hermawan"}, 
{"", "Indradjaja "}, 
{"", "Irawan"}, 
{"", "Iskandar"}, 
{"", "Jayadi"}, 
{"", "Johan"}, 
{"", "Kartawijaya"}, 
{"", "Kurnia"}, 
{"", "Kurniawan"}, 
{"", "Kusnadi"}, 
{"", "Kusuma"}, 
{"", "Kusumo"}, 
{"", "Lesmana"}, 
{"", "Lesmono"} }; 

static s_name INDONESIA_given_name[] = { 
{"", "Ade"}, 
{"", "Ade"}, 
{"", "Adi"}, 
{"", "Devi"}, 
{"", "Agus"}, 
{"", "Dewi"}, 
{"", "Ari"}, 
{"", "arleen"}, 
{"", "Bambang"}, 
{"", "Fanny"}, 
{"", "Benny"}, 
{"", "Farida"}, 
{"", "Budi"}, 
{"", "Glenna"}, 
{"", "Deddy"}, 
{"", "Harjanti"}, 
{"", "Djaja"}, 
{"", "Hartanti"}, 
{"", "Doddy"}, 
{"", "Ida"}, 
{"", "Hadi"}, 
{"", "Inge"}, 
{"", "Hadian"}, 
{"", "Lanny"}, 
{"", "Hamdani"}, 
{"", "Leony"}, 
{"", "Handoko"}, 
{"", "Liana"}, 
{"", "Hartono"}, 
{"", "Liani"}, 
{"", "Hendra"}, 
{"", "Ratna"}, 
{"", "Hendri"}, 
{"", "Shinta"}, 
{"", "Hengki"}, 
{"", "Siska"}, 
{"", "Herman"}, 
{"", "Sri"}, 
{"", "Indra"}, 
{"", "Sucianty"}, 
{"", "Irwan"}, 
{"", "Susanti"}, 
{"", "Ivan"}, 
{"", "Utami"}, 
{"", "Iwan"}, 
{"", "Vera"}, 
{"", "Johan"}, 
{"", "Verawati"}, 
{"", "Ridwan"}, 
{"", "Veronika"}, 
{"", "Sonny"}, 
{"", "Widya"}, 
{"", "Sudirman"}, 
{"", "Widyawati"}, 
{"", "Sudomo"}, 
{"", "Yanti"}, 
{"", "Sugiarto"}, 
{"", "Yenny"}, 
{"", "Suharto"}, 
{"", "Yulia"}, 
{"", "Suhendra"}, 
{"", "Yuliana"}, 
{"", "Sukarno"}, 
{"", "Yuliani"}, 
{"", "Suparman"} };

/// This class gives us the names
class indonesia

{ public:
  static std::string give_name(int index) 
{
    int surnames = 33;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = INDONESIA_given_name[g].roman_name + " "+INDONESIA_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (33) * (65)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
