
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

#ifndef korea_names_H
#define korea_names_H

static s_name KOREA_given_name [] { 
{"민준", "Minjun"}, 
{"주원", "Chuwŏn"}, 
{"준서", "Chunsŏ"}, 
{"시우", "Si'u"}, 
{"예준", "Yejun"}, 
{"서준", "Sŏchun"}, 
{"지후", "Chihu	"}, 
{"지훈", "Chihun"}, 
{"현우", "Hyŏnu	"}, 
{"도현", "Tohyŏn"}, 
{"서연", "Sŏyŏn	"}, 
{"서현", "Sŏhyŏn"}, 
{"민서", "Minsŏ	"}, 
{"서윤", "Sŏyun"}, 
{"지우", "Chi'u"}, 
{"지민", "Chimin"}, 
{"윤서", "Yunsŏ"}, 
{"하은", "Ha'ŭn"}, 
{"지윤", "Chiyun"}, 
{"은서", "Ǔnsŏ"} };

static s_name KOREA_surname[] = { 
{"김", "Kim"}, 
{"이", "Lee"}, 
{"박", "Park"}, 
{"최", "Choi"}, 
{"정", "Jeong"}, 
{"강", "Kang"}, 
{"조", "Cho"}, 
{"윤", "Yoon"}, 
{"장", "Jang"}, 
{"임", "Lim"}, 
{"한", "Han"}, 
{"오", "O"}, 
{"신", "Shin"}, 
{"서", "Seo"}, 
{"권", "Kwon"}, 
{"황", "Hwang"}, 
{"안", "Ahn"}, 
{"송", "Song"}, 
{"유", "Yoo"}, 
{"홍", "Hong"}, 
{"전", "Jeon"}, 
{"고", "Ko"}, 
{"문", "Mun"}, 
{"손", "Son"}, 
{"양", "Yang"}, 
{"배", "Bae"}, 
{"백", "Baek"}, 
{"조", "Jo"}, 
{"허", "Heo"}, 
{"남", "Nam"}, 
{"심", "Sim"}, 
{"유", "Yu"}, 
{"노", "No"}, 
{"하", "Ha"}, 
{"전", "Jeon"}, 
{"정", "Jeong"}, 
{"곽", "Gwak"}, 
{"성", "Seong"}, 
{"차", "Cha"}, 
{"유", "Yu"}, 
{"구", "Gu"}, 
{"우", "U"}, 
{"주", "Ju"}, 
{"임", "Im"}, 
{"나", "Na"}, 
{"신", "Sin"}, 
{"민", "Min"}, 
{"진", "Jin"}, 
{"지", "Ji"}, 
{"엄", "Eom"} }; 

class korea

{ public:
  static std::string give_name(int index) 
{
    int surnames = 50;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = KOREA_given_name[g].name + " "+KOREA_surname[s].name;
    ret_val += "("+KOREA_given_name[g].roman_name + " "+KOREA_surname[s].roman_name+")";
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (20) * (50)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};
#endif
