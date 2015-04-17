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

#ifndef germany_names_H
#define germany_names_H

static s_name GERMANY_given_name[119]{
{"","Alexander"},
{"","Andreas"},
{"","Benjamin"},
{"","Bernd"},
{"","Christian"},
{"","Daniel"},
{"","David"},
{"","Dennis"},
{"","Dieter"},
{"","Dirk"},
{"","Dominik"},
{"","Eric"},
{"","Felix"},
{"","Florian"},
{"","Frank"},
{"","Jan"},
{"","Jens"},
{"","Jonas"},
{"","Jörg"},
{"","Jürgen"},
{"","Kevin"},
{"","Klaus"},
{"","Kristian "},
{"","Leon"},
{"","Lukas"},
{"","Marcel"},
{"","Marco"},
{"","Mario"},
{"","Markus"},
{"","Martin"},
{"","Mathias"},
{"","Max"},
{"","Maximilian"},
{"","Michael"},
{"","Maik"},
{"","Niklas"},
{"","Patrick"},
{"","Paul"},
{"","Peter"},
{"","Philipp"},
{"","Ralf"},
{"","René"},
{"","Robert"},
{"","Sebastian"},
{"","Stefan"},
{"","Steffen"},
{"","Sven"},
{"","Thomas"},
{"","Thorsten"},
{"","Tim"},
{"","Tobias"},
{"","Tom"},
{"","Ulrich"},
{"","Uwe"},
{"","Wolfgang"},
{"","Andrea"},
{"","Angelika"},
{"", "Anja"},
{"", "Anke"},
{"", "Anna"},
{"", "Annett"},
{"", "Antje"},
{"", "Barbara"},
{"", "Birgit"},
{"", "Brigitte"},
{"", "Christin"},
{"", "Christina"},
{"", "Claudia"},
{"", "Daniela"},
{"", "Diana"},
{"", "Doreen"},
{"", "Franziska"},
{"", "Gabriele"},
{"", "Heike"},
{"", "Ines"},
{"", "Jana"},
{"", "Janina"},
{"", "Jennifer"},
{"", "Jessika"},
{"", "Julia"},
{"", "Juliane"},
{"", "Karin"},
{"", "Karolin"},
{"", "Katharina"},
{"", "Katrin"},
{"", "Katja"},
{"", "Kerstin"},
{"", "Klaudia "},
{"", "Kristin "},
{"", "Laura"},
{"", "Lea"},
{"", "Lena"},
{"", "Lisa"},
{"", "Mandy"},
{"", "Manuela"},
{"", "Maria"},
{"", "Marie"},
{"", "Marina"},
{"", "Martina"},
{"", "Melanie"},
{"", "Monika"},
{"", "Nadine"},
{"", "Nicole"},
{"", "Petra"},
{"", "Sabine"},
{"", "Sabrina"},
{"", "Sandra"},
{"", "Sara"},
{"", "Silke"},
{"", "Simone"},
{"", "Sophia"},
{"", "Stefanie"},
{"", "Susanne"},
{"", "Tanja"},
{"", "Ulrike"},
{"", "Ursula"},
{"", "Uta"},
{"", "Vanessa"},
{"", "Yvonne"} };

static s_name GERMANY_surname[50] { 
{"","Müller"}, 
{"","Schmidt"}, 
{"","Schneider"}, 
{"","Fischer"}, 
{"","Weber"}, 
{"","Meyer"}, 
{"","Wagner"}, 
{"","Becker"}, 
{"","Schulz"}, 
{"","Hoffmann"}, 
{"","Schäfer"}, 
{"","Koch"}, 
{"","Bauer"}, 
{"","Richter"}, 
{"","Klein"}, 
{"","Wolf"}, 
{"","Schröder"}, 
{"","Neumann"}, 
{"","Schwarz"}, 
{"","Zimmermann"}, 
{"","Braun"}, 
{"","Krüger"}, 
{"","Hofmann"}, 
{"","Hartmann"}, 
{"","Lange"}, 
{"","Schmitt"}, 
{"","Werner"}, 
{"","Schmitz"}, 
{"","Krause"}, 
{"","Meier"}, 
{"","Lehmann"}, 
{"","Schmid"}, 
{"","Schulze"}, 
{"","Maier"}, 
{"","Köhler"}, 
{"","Herrmann"}, 
{"","König"}, 
{"","Walter"}, 
{"","Mayer"}, 
{"","Huber"}, 
{"","Kaiser"}, 
{"","Fuchs"}, 
{"","Peters"}, 
{"","Lang"}, 
{"","Scholz"}, 
{"","Möller"}, 
{"","Weiß"}, 
{"","Jung"}, 
{"","Hahn"}, 
{"","Schubert"}};

/// This class gives us the names
class germany 
{ public:
  static std::string give_name(int index) {
    int surnames = 50;
    std::string ret_val;
    int s, g;
    s = index % surnames;
    g = (int) index/surnames;
    ret_val = GERMANY_given_name[g].roman_name + " "+GERMANY_surname[s].roman_name;
    return ret_val;
  }


  static int select_name(double p) {
    // Takes a double uniformly distributed in [0,1)
    // enforce boundaries
    if (p < 0) return 0;
    if (p >= 1) return 42;

  int ret_val = (int) (50*119)*p;

    // In theory, (int) p*x*y will never actually be x*y,
    return ret_val;
  }
};

#endif
