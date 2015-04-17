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

#ifndef engl_names_H
#define  engl_names_H

static s_name ENGL_given_name[100] { 
{"", "James"}, 
{"", "Mary"}, 
{"", "John"}, 
{"", "Patricia"}, 
{"", "Robert"}, 
{"", "Jennifer"}, 
{"", "Michael"}, 
{"", "Elizabeth"}, 
{"", "William"}, 
{"", "Linda"}, 
{"", "David"}, 
{"", "Barbara"}, 
{"", "Richard"}, 
{"", "Susan"}, 
{"", "Joseph"}, 
{"", "Margaret"}, 
{"", "Charles"}, 
{"", "Jessica"}, 
{"", "Thomas"}, 
{"", "Dorothy"}, 
{"", "Christopher"}, 
{"", "Sarah"}, 
{"", "Daniel"}, 
{"", "Karen"}, 
{"", "Matthew"}, 
{"", "Nancy"}, 
{"", "Donald"}, 
{"", "Betty"}, 
{"", "Anthony"}, 
{"", "Lisa"}, 
{"", "Paul"}, 
{"", "Sandra"}, 
{"", "Mark"}, 
{"", "Helen"}, 
{"", "George"}, 
{"", "Ashley"}, 
{"", "Steven"}, 
{"", "Donna"}, 
{"", "Kenneth"}, 
{"", "Kimberly"}, 
{"", "Andrew"}, 
{"", "Carol"}, 
{"", "Edward"}, 
{"", "Michelle"}, 
{"", "Joshua"}, 
{"", "Emily"}, 
{"", "Brian"}, 
{"", "Amanda"}, 
{"", "Kevin"}, 
{"", "Melissa"}, 
{"", "Ronald"}, 
{"", "Deborah"}, 
{"", "Timothy"}, 
{"", "Laura"}, 
{"", "Jason"}, 
{"", "Stephanie"}, 
{"", "Jeffrey"}, 
{"", "Rebecca"}, 
{"", "Gary"}, 
{"", "Sharon"}, 
{"", "Ryan"}, 
{"", "Cynthia"}, 
{"", "Nicholas"}, 
{"", "Kathleen"}, 
{"", "Eric"}, 
{"", "Ruth"}, 
{"", "Jacob"}, 
{"", "Anna"}, 
{"", "Stephen"}, 
{"", "Shirley"}, 
{"", "Jonathan"}, 
{"", "Amy"}, 
{"", "Larry"}, 
{"", "Angela"}, 
{"", "Frank"}, 
{"", "Virginia"}, 
{"", "Scott"}, 
{"", "Brenda"}, 
{"", "Justin"}, 
{"", "Pamela"}, 
{"", "Brandon"}, 
{"", "Catherine"}, 
{"", "Raymond"}, 
{"", "Katherine"}, 
{"", "Gregory"}, 
{"", "Nicole"}, 
{"", "Samuel"}, 
{"", "Christine"}, 
{"", "Benjamin"}, 
{"", "Janet"}, 
{"", "Patrick"}, 
{"", "Debra"}, 
{"", "Jack"}, 
{"", "Samantha"}, 
{"", "Dennis"}, 
{"", "Carolyn"}, 
{"", "Jerry"}, 
{"", "Rachel"}, 
{"", "Alexander"}, 
{"", "Heather"} };


static s_name ENGL_surname[] = { 
{"","Smith"}, 
{"","Jones"}, 
{"","Taylor"}, 
{"","Williams"}, 
{"","Brown"}, 
{"","Davies"}, 
{"","Evans"}, 
{"","Wilson"}, 
{"","Thomas"}, 
{"","Roberts"}, 
{"","Johnson"}, 
{"","Lewis"}, 
{"","Walker"}, 
{"","Robinson"}, 
{"","Wood"}, 
{"","Thompson"}, 
{"","White"}, 
{"","Watson"}, 
{"","Jackson"}, 
{"","Wright"}, 
{"","Green"}, 
{"","Harris"}, 
{"","Cooper"}, 
{"","King"}, 
{"","Lee"}, 
{"","Martin"}, 
{"","Clarke"}, 
{"","James"}, 
{"","Morgan"}, 
{"","Hughes"}, 
{"","Edwards"}, 
{"","Hill"}, 
{"","Moore"}, 
{"","Clark"}, 
{"","Harrison"}, 
{"","Scott"}, 
{"","Young"}, 
{"","Morris"}, 
{"","Hall"}, 
{"","Ward"}, 
{"","Turner"}, 
{"","Carter"}, 
{"","Phillips"}, 
{"","Mitchell"}, 
{"","Patel"}, 
{"","Adams"}, 
{"","Campbell"}, 
{"","Anderson"}, 
{"","Allen"}, 
{"","Cook"}};

/// This class gives us the names
class engl {
public:
  static std::string give_name(int index) 

{
    int surnames = 50;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = ENGL_given_name[g].roman_name + " "+ENGL_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) 

{
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (50*100)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};

#endif
