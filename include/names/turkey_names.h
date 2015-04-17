
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

#ifndef turkey_names_H
#define turkey_names_H

static s_name TURKEY_given_name[] = {
{"", "Talya"},
{"", "Zeynep"},
{"", "Ela"},
{"", "Duru"},
{"", "Yaren"},
{"", "Ceren"},
{"", "Ece"},
{"", "Melis"},
{"", "Naz"},
{"", "Su"},
{"", "Berra"},
{"", "Ecem"},
{"", "Sena"},
{"", "İrem"},
{"", "Azra"},
{"", "Dilay"},
{"", "İdil"},
{"", "Eylül"},
{"", "İpek"},
{"", "Nazlı"},
{"", "Yağmur"},
{"", "Derin"},
{"", "Ilgın"},
{"", "Havin"},
{"", "Nilsu"},
{"", "Kayra"},
{"", "Begüm"},
{"", "İlkin"},
{"", "Tuana"},
{"", "Beril"},
{"", "İlgi"},
{"", "Simay"},
{"", "Pelin"},
{"", "Beren"},
{"", "Mira"},
{"", "Yazmira"},
{"", "Selin"},
{"", "Simge"},
{"", "Rana"},
{"", "Şimal"},
{"", "Damla"},
{"", "Melike"},
{"", "Pınar"},
{"", "Başak"},
{"", "Özüm"},
{"", "Elçin"},
{"", "Minel"},
{"", "Arzum"},
{"", "Emir"},
{"", "Cem"},
{"", "Ege"},
{"", "Çağan"},
{"", "Sarp"},
{"", "Kerem"},
{"", "Deniz"},
{"", "Yağız"},
{"", "Yiğit"},
{"", "Emre"},
{"", "Kağan"},
{"", "Mert"},
{"", "Görkem"},
{"", "Burak"},
{"", "Meriç"},
{"", "Berke"},
{"", "Kutay"},
{"", "Tuna"},
{"", "Baran"},
{"", "Efe"},
{"", "Onur"},
{"", "Doruk"},
{"", "Bartu"},
{"", "Emirhan"},
{"", "Alp"},
{"", "Arhan"},
{"", "Bora"},
{"", "Canberk"},
{"", "Rüzgar"},
{"", "Derin"},
{"", "Toprak"},
{"", "Arın"},
{"", "Aşkın"},
{"", "Çınar"},
{"", "Armağan"},
{"", "Derin"},
{"", "Koray"},
{"", "Barlas"},
{"", "Ada"},
{"", "Atakan"},
{"", "Berk"},
{"", "Ali"},
{"", "Polat"},
{"", "Göktürk"},
{"", "Serhan"},
{"", "Ege"},
{"", "Utku"},
{"", "Berkay"},
{"", "Güney"} };

static s_name TURKEY_surname[] = { {"", "Yılmaz"}, {"", "Kaya"}, {"", "Demir"}, {"", "Şahin"}, {"", "Çelik"}, {"", "Yıldız"}, {"", "Yıldırım"}, {"", "Öztürk"}, {"", "Aydın"}, {"", "Özdemir"}, {"", "Arslan"}, {"", "Doğan"}, {"", "Kılıç"}, {"", "Aslan"}, {"", "Çetin"}, {"", "Kara"}, {"", "Koç"}, {"", "Kurt"}, {"", "Özkan"}, {"", "Şimşek"} };


/// This class gives us the names
class turkey
{ public:
  static std::string give_name(int index) {
    int surnames = 20;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = TURKEY_given_name[g].roman_name + " "+TURKEY_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) {
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (97) * (   20)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
