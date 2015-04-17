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

#ifndef china_names_H
#define china_names_H

static s_name CHINA_given_name [50] { 
{"伟", "Wěi"}, 
{"伟", "Wěi"}, 
{"芳", "Fāng"}, 
{"伟", "Wěi"}, 
{"秀英", "Xiùyīng"}, 
{"秀英", "Xiùyīng"}, 
{"娜", "Nà"}, 
{"秀英", "Xiùyīng"}, 
{"伟", "Wěi"}, 
{"敏", "Mǐn"}, 
{"静", "Jìng"}, 
{"丽", "Lì"}, 
{"静", "Jìng"}, 
{"丽", "Lì"}, 
{"强", "Qiáng"}, 
{"静", "Jìng"}, 
{"敏", "Mǐn"}, 
{"敏", "Mǐn"}, 
{"磊", "Lěi"}, 
{"军", "Jūn"}, 
{"洋", "Yáng"}, 
{"勇", "Yǒng"}, 
{"勇", "Yǒng"}, 
{"艳", "Yàn"}, 
{"杰", "Jié"}, 
{"磊", "Lěi"}, 
{"强", "Qiáng"}, 
{"军", "Jūn"}, 
{"杰", "Jié"}, 
{"娟", "Juān"}, 
{"艳", "Yàn"}, 
{"涛", "Tāo"}, 
{"涛", "Tāo"}, 
{"明", "Míng"}, 
{"艳", "Yàn"}, 
{"超", "Chāo"}, 
{"勇", "Yǒng"}, 
{"娟", "Juān"}, 
{"杰", "Jié"}, 
{"秀兰", "Xiùlán"}, 
{"霞", "Xiá"}, 
{"敏", "Mǐn"}, 
{"军", "Jūn"}, 
{"丽", "Lì"}, 
{"强", "Qiáng"}, 
{"平", "Píng"}, 
{"刚", "Gāng"}, 
{"杰", "Jié"}, 
{"桂英", "Guìyīng"}, 
{"芳", "Fāng"} }; 

static s_name CHINA_surname[20] = { 
{"王", "Wáng"}, 
{"李", "Lǐ"}, 
{"張", "Zhāng"}, 
{"劉", "Liú"}, 
{"陳", "Chén"}, 
{"楊", "Yáng"}, 
{"黃", "Huáng"}, 
{"趙", "Zhào"}, 
{"吳", "Wú"}, 
{"周", "Zhōu"}, 
{"徐", "Xú"}, 
{"孫", "Sūn"}, 
{"馬", "Mǎ"}, 
{"朱", "Zhū"}, 
{"胡", "Hú"}, 
{"郭", "Guō"}, 
{"何", "Hé"}, 
{"高", "Gāo"}, 
{"林", "Lín"}, 
{"羅", "Luó"}}; 



/// This class gives us the names
class china {
public:
  static std::string give_name(int index) 
{
    int surnames = 20;
    std::string ret_val;
    int s, g;
//std::cerr << "(Lo, I have been asked to give a name) ";
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = CHINA_given_name[g].name + " "+CHINA_surname[s].name
              + "  ("+CHINA_given_name[g].roman_name + " " + CHINA_surname[s].roman_name+")";
    return ret_val;
  }


  static int select_name(double p) 
{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (50*20)*p;
//std::cerr << "Selecting a name, which will be "<<give_name(ret_val)<<"\n";
//std::cerr << "Returning "<<ret_val << std::endl;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};

#endif
