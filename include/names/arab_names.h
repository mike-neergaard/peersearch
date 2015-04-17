/**
    @arab_names.h
    @contains arabic names to select at random
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

#ifndef arab_names_h
#define  arab_names_h

#include <iostream>

//Iran and Egypt are getting short shrift here.  Can't find a good list of common names
// in Arabic, Farsi, or Pashtu, so a list of actors will have to do...
// That's ok, it's the character set we really want.

static s_name arab_names[110] = {
{" ثار الحكيم ",""}, 
{" أجفان الأمير ",""} , 
{" إجلال حسني ",""},
 {" إجلال خالد ",""},
 {" إجلال زكي ",""} , 
{" إحسان الجزايرلي ",""} , 
{" إحسان القلعاوي ",""} , 
{" إحسان شريف ",""} , 
{" أحلام الجريتلي ",""} , 
{" أحلام حلمي ",""} , 
{" أحلام خالد ",""} , 
{" أحلام رشدي ",""} , 
{" أحلام عبد الله ",""} , 
{" أحلام مرسي ",""} , 
{" إخلاص حسني ",""} , 
{" أزهار شريف ",""} , 
{" أستر شطاح ",""} , 
{" إسعاد يونس "," " } , 
{" أسماء عيد ",""} , 
{" اسمهان ",""} , 
{" آسيا داغر ",""} , 
{" إعتدال حسن ",""} , 
{" إعتدال شاهين ",""} , 
{" إكرام عزو ",""} , 
{" ألفت عمر ",""} , 
{" ألفت إمام ",""} , 
{" إلهام إبراهيم ",""} , 
{" إلهام بديع ",""} , 
{" إلهام حسين ",""} , 
{" إلهام الراسي ",""} , 
{" إلهام زايد ",""} , 
{" إلهام زكي ",""} , 
{" إلهام شاهين ",""} , 
{" إلهام شريف ",""} , 
{" إلهام عبد الفتاح ","" } , 
{" إلهام فايد ",""} , 
{" إلهام مبروك ",""} , 
{" إلهام محمد ",""} , 
{" إلهام المهندس ",""},
 {" أمال أبو شفة ",""},
 {" آمال الحجار ",""},
 {" آمال حسن ",""},
 {" آمال حسني ",""},
 {" آمال حلمي ",""},
 {" آمال حمدي ",""},
 {" آمال دياب ",""},
 {" آمال رمزي ",""},
 {" آمال زايد ",""},
 {" آمال الزهيري ",""},
 {" آمال زينهم ",""},
 {" آمال سالم ",""},
 {" آمال سامي ",""},
 {" آمال سعيد ",""},
 {" آمال السيد ",""},
 {" آمال شريف ",""},
 {" آمال الشناوي ",""},
 {" آمال شوكت ",""},
 {" آمال صادق ",""},
 {" آمال الصعيدي ",""},
 {" آمال صفطة ",""},
 {" آمال عبدالمنعم ",""},
 {" آمال العجوز ",""},
 {" آمال العربي ",""},
 {" آمال العزازي ",""},
 {" آمال عزت ",""},
 {" آمال عفيش ",""},
 {" آمال فتحي ",""},
 {" آمال فريد ",""},
 {" آمال فهمي ",""},
 {" آمال ماهر ",""},
 {" آمال مراد ",""},
 {" آمال وحيد ",""},
 {" آمال يسري ",""},
 {" آمال يوسف ",""},
 {" آماليا عوض ",""},
 {" أماني خيري ",""},
 {" أمل إبراهيم ",""},
 {" أمل توفيق ",""},
 {" أمل حامد ",""},
{" أمل رزق ",""}, 
{" أمل رشدي ",""}, 
{" أمل الصاوي ",""}, 
{" أميرة أنطون ",""}, 
{" أميرة أيمن ",""}, 
{" أميرة البدراوي ",""}, 
{" أميرة بهي الدين ",""}, 
{" أميرة جمال ",""}, 
{" أميرة جواد ",""}, 
{" أميرة حمدي ",""}, 
{" أميرة حنفي ",""}, 
{" أميرة شريف ",""}, 
{" أميرة زيادة ",""}, 
{" أميرة عامر ",""}, 
{" أميرة العايدي ",""}, 
{" أميرة عبد الرحمن ",""}, 
{" أميرة عبد العزيز ",""}, 
{" أميرة عبد القادر ",""}, 
{" أميرة عبدالمنعم ",""}, 
{" أميرة عفيفي ",""}, 
{" أميرة فتحي أحمد ",""}, 
{" أميرة فريد ",""}, 
{" أميرة فؤاد ",""}, 
{" أميرة مهران ",""}, 
{" أميرة نور ",""}, 
{" أميرة هاني ",""}, 
{" أميمة سليم ",""}, 
{" أمينة ",""}, 
{" أمينة البارودي ",""}, 
{" أمينة رزق ",""}, 
{" أمينة سليم ",""} };

/// This class gives us the names
class arabic {
public:
  static std::string give_name(int val) {
//std::cerr << "(Lo, I have been asked to give a name) ";
    return arab_names[val].name;
  }
  static short int select_name(double p) {
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    int ret_val;

    if (p < 0) return 0;
    if (p >= 1) return 109;


    // In theory, (int) p*110 will never actually be 110,
    ret_val = (int) 110*p;
    if (ret_val == 110) ret_val = 109;
//std::cerr << "Selecting a name, which will be "<<give_name(ret_val)<<"\n";
//std::cerr << "Returning "<<ret_val << std::endl;
    return ret_val;
  }
};

#endif
