
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

#ifndef italy_names_H
#define italy_names_H

static s_name ITALY_given_name[] {
{"", "Giovanni"},
{"", "Antonio"},
{"", "Piero"},
{"", "Francesco"},
{"", "Iacopo"},
{"", "Bartolomeo"},
{"", "Niccolo"},
{"", "Domenico"},
{"", "Lorenzo"},
{"", "Andrea"},
{"", "Michele"},
{"", "Tommaso"},
{"", "Matteo"},
{"", "Filippo"},
{"", "Bernardo"},
{"", "Pagolo"},
{"", "Simone"},
{"", "Nanni"},
{"", "Cristofano"},
{"", "Zanobi"},
{"", "Agnolo"},
{"", "Leonardo"},
{"", "Luca"},
{"", "Bartolo"},
{"", "Benedetto"},
{"", "Stefano"},
{"", "Marco"},
{"", "Lodovico"},
{"", "Guido"},
{"", "Salvestro"},
{"", "Niccolaio"},
{"", "Maso"},
{"", "Biagio"},
{"", "Martino"},
{"", "Sandro"},
{"", "Cecco"},
{"", "Donato"},
{"", "Neri"},
{"", "Giorgio"},
{"", "Taddeo"},
{"", "Meo"},
{"", "Carlo"},
{"", "Frosino"},
{"", "Agostino"},
{"", "Luigi"},
{"", "Guasparre"},
{"", "Papi"},
{"", "Gherardo"},
{"", "Nardo"},
{"", "Nofri"},
{"", "Bastiano"},
{"", "Berto"},
{"", "Pippo"},
{"", "Santi"},
{"", "Arrigo"},
{"", "Guglielmo"},
{"", "Mariotto"},
{"", "Giusto"},
{"", "Mariano"},
{"", "Vanni"},
{"", "Dino"},
{"", "Goro"},
{"", "Betto"},
{"", "Ugolino"},
{"", "Battista"},
{"", "Lapo"},
{"", "Rinaldo"},
{"", "Baldo"},
{"", "Rinieri"},
{"", "Roberto"},
{"", "Buono"},
{"", "Cipriano"},
{"", "Geri"},
{"", "Guccio"},
{"", "Romolo"},
{"", "Baldassarr"},
{"", "Cambio"},
{"", "Lazzero"},
{"", "Lotto"},
{"", "Bernaba"},
{"", "Cenni"},
{"", "Chimento"},
{"", "Corso"},
{"", "Girolamo"},
{"", "Miniato"},
{"", "Salvadore"},
{"", "Alessandro"},
{"", "Amerigo"},
{"", "Bindo"},
{"", "Duccio"},
{"", "Alberto"},
{"", "Alesso"},
{"", "Ambrogio"},
{"", "Bettino"},
{"", "Gabbriello"},
{"", "Marchionne"},
{"", "Nencio"},
{"", "Bianco"},
{"", "Bonacorso"},
{"", "Bruno"},
{"", "Daniello"},
{"", "Federigo"},
{"", "Lando"},
{"", "Manetto"},
{"", "Pace"},
{"", "Riccardo"},
{"", "Cino"},
{"", "Corrado"},
{"", "Lippo"},
{"", "Niccola"},
{"", "Puccio"},
{"", "Ridolfo"},
{"", "Vieri"},
{"", "Anichino"} };

static s_name ITALY_surname[22] { 
{"","Rossi"}, 
{"","Russo"}, 
{"","Ferrar"}, 
{"","Esposito"}, 
{"","Bianchi"}, 
{"","Romano"}, 
{"","Colombo"}, 
{"","Ricci"}, 
{"","Marino"}, 
{"","Greco"}, 
{"","Bruno"}, 
{"","Gallo"}, 
{"","Conti"}, 
{"","De Luca"}, 
{"","Costa"}, 
{"","Giordano"}, 
{"","Mancini"}, 
{"","Rizzo"}, 
{"","Lombardi"}, 
{"","Moretti"}, 
{"","Sante"}, 
{"","Ravelli"} };


/// This class gives us the names
class italy

{ public:
  static std::string give_name(int index) 
{
    int surnames = 22;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = ITALY_given_name[g].roman_name + " "+ITALY_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (22) * (114)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
