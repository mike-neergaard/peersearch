/**
    @file peersearch.cpp
    @brief peersearch: Test rig for searching algorithm
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
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>
#include "peersearch.h"




/// Print 100 lines to clear the screen
void clear_screen(){
  for (int i = 0; i < 10; i++) std::cerr<<"\n\n\n\n\n\n\n\n\n\n";
  return;
}

bool verify_search(double age, double lat, double lng){

  std::string str_in;

  while(1) {
    std::cerr << "Search for age "<<age<<" near ("<<lat<<", "<<lng<<")? (y/n) ";
    getline(std::cin, str_in);
    if (str_in == "y") return true;
    else if (str_in == "n") return false;
  }
}

bool prompted_bool(std::string prompt, std::string str_true, std::string str_false){
  std::string str_in;

  while(1) {
    std::cerr << prompt << " ("<<str_true<<"/"<<str_false<<") ";
    getline(std::cin, str_in);
    if (str_in == str_true) return true;
    else if (str_in == str_false) return false;
  }
}

/// Ask the user to press return before continuing
void pause(void){
  std::string in_str;
  std::cerr << "Press return to continue.   ";
  // Flush any returns from the buffer
  //std::cin.ignore(1, '\n');;
  getline(std::cin, in_str);
  return;
}

// You would think I could template this
double input_double(int &read_status){
  double ret_val;

  std::string str_in;
  getline(std::cin, str_in);

  if (str_in == "") {
    read_status = NO_INPUT;
    return 0.0;
  }

  read_status = GOOD_READ;
  // We'll accept zero in the form "0" and "0.0"
  if (str_in == "0" || str_in == "0.0") {
    return 0.0;
  } else {
    ret_val = stod(str_in);
    if (!ret_val) {
      read_status = BAD_READ;
    }
  }
  return ret_val;
}

// You would think I could template this
int input_int(int &read_status){
  int ret_val;

  std::string str_in;
  getline(std::cin, str_in);

  if (str_in == "") {
    read_status = NO_INPUT;
    return 0;
  }

  read_status = GOOD_READ;
  // We'll accept zero in the form "0" and "0.0"
  if (str_in == "0"){
    return 0;
  } else {
    ret_val = stoi(str_in);
    if (!ret_val) {
      read_status = BAD_READ;
    }
  }
  return ret_val;
}


// Another thing you would think I could template
double prompted_double(std::string prompt, double current, bool &read_OK,
                    double min, double max, std::string success, std::string failure) {

  double ret_val;

  std::cerr << prompt << "["<<min<<" to "<<max<<"]"<<" ("<<current<<"): ";
  int read_status = BAD_READ;

  while (read_status == BAD_READ) {
    ret_val = input_double(read_status);
    if (read_status==GOOD_READ) {
      if (ret_val >= min && ret_val <= max) {
        std::cerr << success << ret_val << std::endl;
        read_OK = true;
      } else {
        std::cerr << failure << ret_val << std::endl;
        read_OK = false;
      }
      pause();
    } else if (read_status == NO_INPUT) {
      // If the user didn't change anything, just ignore
      read_OK = false;
      read_status = GOOD_READ;
    }
      
  }

  return ret_val;
}

int prompted_int(std::string prompt, int current, bool &read_OK,
                    int min, int max, std::string success, std::string failure) {

  int ret_val;

  std::cerr << prompt << "["<<min<<" to "<<max<<"]"<<" ("<<current<<"): ";
  int read_status = BAD_READ;

  while (read_status == BAD_READ) {
    ret_val = input_int(read_status);
    if (read_status==GOOD_READ) {
      if (ret_val >= min && ret_val <= max) {
        std::cerr << success << ret_val << std::endl;
        read_OK = true;
      } else {
        std::cerr << failure << ret_val << std::endl;
        read_OK = false;
      }
      pause();
    } else if (read_status == NO_INPUT) {
      // If the user didn't change anything, just ignore
      read_OK = false;
      read_status = GOOD_READ;
    }
      
  }

  return ret_val;
}

/*
template<class T>
T input_val(int &read_status, bool is_int){

  T ret_val;

  std::string str_in;
  getline(std::cin, str_in);

  if (str_in == "") {
    read_status = NO_INPUT;
    return 0;
  }

  read_status = GOOD_READ;
  // We'll accept zero in the form "0"
  if (str_in == "0"){
      return 0;
  } 
  if (!is_int) {
    //We'll accept a double zero in the form "0.0"
    if (str_in == "0.0"){
      return 0;
    } 
    ret_val = stod(str_in);
  }  else {
    ret_val = stoi(str_in);
  }
  if (!ret_val) {
    read_status = BAD_READ;
  }
  return ret_val;
}

int input_int(int &read_status){
  return input_val<int>(read_status, true);
}

double input_double(int &read_status){
  return input_val<double>(read_status, false);
}


template<typename T>
T prompted_number(std::string prompt, T &current, bool &read_OK, 
                    T &min, T &max, std::string success, std::string failure,
                    bool is_int) {
//T prompted_number(std::string prompt, std::string current, bool &read_OK, 
                    //std::string min, std::string max, std::string success, 
                    //std::string failure, T min_input, T max_input,
                    //bool is_int) {
  T ret_val;

  std::cerr << prompt << " ["<< std::to_string(min) <<" to "<< std::to_string(max)
             <<"]"<<" ("<< std::to_string(current)<<"): ";
  int read_status = BAD_READ;

  while (read_status == BAD_READ) {
    if (is_int) ret_val = input_int(read_status);
    else ret_val = input_double(read_status);
    if (read_status==GOOD_READ) {
      if (ret_val >= min && ret_val <= max) {
        std::cerr << success << ret_val << std::endl;
        read_OK = true;
      } else {
        std::cerr << failure << ret_val << std::endl;
        read_OK = false;
      }
      pause();
    } else if (read_status == NO_INPUT) {
      // If the user didn't change anything, just ignore
      read_OK = false;
      read_status = GOOD_READ;
    }
      
  }

  return ret_val;
}

int prompted_int (std::string prompt, int current, bool &read_OK, 
                    int min, int max, std::string success, std::string failure) {

 std::string c = ""; c+=current;
 std::string l = ""; l+=min;
 std::string u = ""; u+=max;

 return prompted_number<int> (prompt, current, read_OK, min, max, success, failure, true);
 //return prompted_number<int> (prompt, c, read_OK, l, u, success, failure, min, max, true);
}

int prompted_double (std::string prompt, double current, bool &read_OK, 
                    double min, double max, std::string success, std::string failure) {
 
 std::string c = ""; c+=current;
 std::string l = ""; l+=min;
 std::string u = ""; u+=max;

 //return prompted_number<double> (prompt, c, read_OK, l, u, success, failure, min, max, true);
 return prompted_number<double> (prompt, current, read_OK, min, max, success, failure, false);
}
*/


/// Print the menu options
template<std::size_t SIZE>
int menu_screen(std::string Title, std::array<std::string, SIZE> &MenuEntries) {

  bool good_input = false;
  int good_read;
  int i;

  while (!good_input) {
    clear_screen();
    std::cerr << Title << std::endl;
    for (i = 0; i < Title.length(); i++) std::cerr << "=";
    std::cerr << std::endl;
    for (i = 0; i < MenuEntries.size(); i++) {
      std::cerr << i+1 <<")\t"<<MenuEntries[i]<<std::endl;
    }
    std::cerr << std::endl;
    int good_read = BAD_READ;
  
    std::cerr << "\nPlease Enter an Option: ";
    i = input_int(good_read);
    if (good_read == BAD_READ){
      continue;
    }
    if (i >= 1 && i <= MenuEntries.size()) good_input = true;
    else {
      std::cerr << i << " is not a valid option\n";
      pause();
    }
  }

  return i-1;
}

void print_help()
{
  std::cerr << 
"Usage: peersearch [-help][-dbSize <int>][-return<int>] \n"<<
"\n"<<
"    -dbSize      Number of entries to generate. Default is 33,222,111\n"<<
"    -return      Set number of results to return. Default is 10.\n"<<
"    -i           Start an interactive session\n"<<
"    -fns         Set the final node size\n"<<
std::endl;
  exit(1);
}

/// Sometimes you really need to just exit.
void die_harshly(std::string harsh_words){
  std::cerr << harsh_words << std::endl << std::endl;
}

/// A little routine that knows the difference between "0.0" and an error.
double read_float(char *number, bool &read_OK) {
  float ret_val;

  read_OK = true;
  // We'll accept zero in the form "0" and "0.0"
  if (!strcmp("0", number) ||!strcmp("0.0", number) ) {
    return  0.0;
  } else {
    ret_val = atof(number);
    if (!ret_val) {
      read_OK = false;
    }
  }
  return ret_val;
}

/// A little routine that knows the difference between "0.0" and an error.
int read_int(char *number, bool &read_OK) {
  int  ret_val;

  read_OK = true;
  // We'll accept zero in the form "0"
  if (!strcmp("0", number)) {
    return  0.0;
  } else {
    ret_val = atoi(number);
    if (!ret_val) {
      read_OK = false;
    }
  }
  return ret_val;
}

/// Look for an command line switch
int arg_position(std::string match_string, int argc, char **argv)
{
  for (int i=1; i<argc; i++) {
    //if (!std::strcmp(match_string, argv[i])) return i;
    if (!match_string.compare(argv[i])) return i;
  }

  return 0;
}

void print_about(void) {
  std::cout << "\n"<< 
  "*******************************************************************\n"<<
  "*   peersearch - a program to search a dataset for close entries  *\n"<<
  "*   Copyright 2015 Mike Neergaard                                 *\n"<<
  "*   Licensed for use under GPLv3 public license                   *\n"<<
  "*******************************************************************\n\n";

  pause();
}
 

/// Loop to generate dataset
void make_data 
         (int data_size, 
          int step_size, 
          c_record_generator &record_generator, 
          c_record_store &record_store, c_age_lat_long_searcher &search_tree){

  int i, j, index;
  s_data_record data_record;
  // Delete the old data
  record_store.clear();
  search_tree.clear();

  std::cerr << "Generating "<<data_size<<" records\n";
  // protect against out of bounds
  if (step_size < 10 || step_size > data_size) step_size = data_size;
  
  int steps = (data_size/step_size);
  int remain = data_size - steps*step_size;
  std::cerr << "\r Generated       0 records";
  int count;
  for (i = 0; i < steps; i++) {
    for (j = 0; j < step_size; j++) {
      data_record = record_generator.generate_record();
//std::cout << "count = "<<count;
      index = record_store.add(data_record);
      search_tree.add(data_record, index );
      //record_store.print_record(std::cout, index);
    }
    count = (i+1)*step_size;
    std::cerr << "\r Generated "<<count<< " of "<<data_size<<" records";
  }

  for (i = 0; i < remain; i++) {
    data_record = record_generator.generate_record();
    index = record_store.add(data_record);
    search_tree.add(data_record, index );
    //record_store.print_record(std::cout, index);
    count++;
  }

  std::cerr << "\r Generated "<<count<< " of "<<data_size<<" records\n";
  search_tree.process_data();
  pause();
}

int main(int argc, char** argv) {
  int N = 10;
  int data_size = 11222333;
  bool read_success;
  int read_status;
  int dim, i, i_val;
  std::string prompt_string;
  std::string success_string;
  std::string fail_string;
  double d_val;
  int step_size = 100000;

  int command;
  bool data_generated = false;

  double cutoff_matrix[3][2] = {{0.0, 130.0}, {-90.0,90.0}, {-180.0, 180.0}};
  double comparison_factors[3] = {0.015625, 1.0, 1.0};

  c_city_model cities;
  c_record_generator record_generator(&cities);
  c_record_store record_store(&cities);
  c_age_lat_long_searcher search_tree(cutoff_matrix, comparison_factors);


  // if requested, print help and exit
  if (arg_position("-help", argc, argv)) print_help();;

  i = arg_position("-return", argc, argv);
  // If the argument was entered and is not the _last_ argument...
  if (i && i < argc-1) {
    N = read_int(argv[i+1], read_success);
    if (!read_success) die_harshly("results argument requires a number");
    if (N < 0) die_harshly("Cannot return a negative number of results");
    if (!N) die_harshly("Cannot return zero results");
  }
  
  i = arg_position("-dbSize", argc, argv);
  if (!i) i = arg_position("-db", argc, argv);
  // If the argument was entered and is not the _last_ argument...
  if (i && i < argc-1) {
    data_size = read_int(argv[i+1], read_success);
    if (!read_success) die_harshly("results argument requires a number");
    if (data_size <= 0) die_harshly("Cannot generate a dataset of that size");
  }

   
  i = arg_position("-final_leaf_size", argc, argv);
  if (!i) i = arg_position("-fls", argc, argv);
  // If the argument was entered and is not the _last_ argument...
  if (i && i < argc-1) {
    int val = read_int(argv[i+1], read_success);
    if (!read_success) die_harshly("leaf size argument requires a number");
    if (val < 0) die_harshly("Cannot generate a leafe of size");
    search_tree.set_final_node_size(val);
  }


  i = arg_position("-i", argc, argv);
  if (!i) {
    // Hmm.  User wants data right now.
    std::cerr << 
       "\n"<<
       "********************************************************\n"<<
       "* Welcome to peersearch.  You can start an interactive *\n"<<
       "* session without generating a database first:         *\n"<<
       "* peersearch -i [options]                              *\n"<<
       "********************************************************\n\n"<<
       "Generating data -- please be patient.\n";
    make_data(data_size, step_size, record_generator, record_store, search_tree);
    data_generated = true;
  }

  while (1) {
    command = menu_screen("Main Menu", main_menu_entries);

    // Switch statement
    if (command == PRINT_ABOUT) {
      print_about();
    } else if (command == DO_SEARCH) {
      // If you actually read this code and tell me who this is, I'll
      // buy you a pastry
      if (!data_generated) {
        std::cerr<< "Please generate data first. ";pause();continue;
      }
      double age = 47, lat= 17.3941, lng=78.3950;

      bool ready;
      ready  = false;
      while (!ready) {
        d_val = prompted_double("Please enter an age", age, read_success, 0, 130,
               "Search age set to ","Cannot set search age to ");
        if(read_success) age = d_val;
        d_val = prompted_double("Please enter a latitude", lat, read_success, -90, 90,
               "Search latitude set to ", "Cannot set search latitude to ");
        if(read_success) lat = d_val;
        d_val  = prompted_double("Please enter a longitude", lng, read_success, -180, 180,
               "Search longitude set to ", "Cannot set search longitude to ");
        if(read_success) lng = d_val;
        ready = verify_search(age, lat, lng);
      }
      std::vector<int> results;
      double search_term[3] = {age, lat, lng};
      search_tree.find_matches(N, search_term, results);
      for(std::vector<int>::iterator it = results.begin(); it != results.end(); it++) {
        record_store.print_short_record(std::cout, (*it));
      }
      pause();
    } else if (command == CONFIGURE) {
      bool config_now = true;
      while(config_now) {
        int opt = menu_screen("Configuration", config_menu_entries);
        if (opt == CONFIG_RETURN_MAIN) config_now = false;
        else if (opt == SET_DATA_SIZE) {
          i_val = prompted_int("Please enter datastore size as int",data_size, 
                  read_success, 0, 100000000, "New datastore size set to ",
                  "Cannot set datastore size to ");
          if (read_success) data_size = i_val;
        } else if (opt == SET_N) {
          i_val = prompted_int("Please number of search results to return", 
                  N, read_success, 0, data_size, "New search return size set to ", 
                  "Cannot set search return size to ");
          if (read_success) N=i_val;
        } else if (opt == STEP_SIZE) {
          i_val = prompted_int( "Output progress every n generated records", step_size, 
                 read_success, 0, data_size, "New progress update frequency set to", 
                 "Cannot set update frequency to ");
          if (read_success) step_size = i_val;
        } else if (opt == SEARCH_CONFIG) {
            bool config_search = true;
// This is inside a long else_if, but I'm indenting it this way anyway,
// because it's the main search configuration code.
// It's a test rig -- if you care, you should be writing your own interface anyway.
while(config_search) {
  int opt = menu_screen("Configure Search (Please note: mostly for NEXT dataset)", 
                       search_config_menu_entries);
  if (opt == DO_COVER) {
    prompt_string = 
    "As configured, the search algorithm does ";
    if (!search_tree.get_include_cover()) prompt_string += "not ";
    prompt_string = prompt_string +              "store extra cover data to \n"+
    "improve search results. This cover data stores extra informaton in the\n"+
    "tree from neighboring regions in the space partition. This adds to the\n"+
    " preprocessing time, although it may allow for smaller final leaves\n"+
    "Should the search generate cover data?";
    search_tree.set_include_cover(prompted_bool(prompt_string, "y", "n"));
  } else if (opt == COVER_RADIUS) {
    d_val = prompted_double("What size in degrees should cover radius be?",
       search_tree.get_cover_overlap_radius(), read_success, 0, 90.0,
        "Cover radius set to ", "Cannot set cover radius to ");
    if (read_success) search_tree.set_cover_overlap_radius(d_val);
  } else if (opt == COVER_TRIM) {
    prompt_string.clear();
    prompt_string = prompt_string + 
    "The cover trim is the ratio between the data size and size of the cover data to be\n"+
    " kept with each leaf to improve search results. After the data is read in, the cover\n"+
    " is trimmed to this ratio.\n"+
    "What should this ratio be?";
    d_val = prompted_double(prompt_string,
       search_tree.get_trim_factor(), read_success, 0, 1000000,
        "Cover trim ratio set to ", "Cannot set cover trim ratio to ");
    if (read_success) search_tree.set_trim_factor(d_val);
  } else if (opt == FINAL_LEAF_SIZE) {
    prompt_string.clear();
    prompt_string = prompt_string + 
    "After all the data is read in, it is subdivided into leaves at the bottom\n"+
    "of a search tree.\n"+
    "What maximum size should the final leaves be?";
    i_val = prompted_int(prompt_string,
       search_tree.get_final_node_size(), read_success, 1, 1<<30,
        "Maximum leaf size set to ", 
        "Cannot set maximum leaf size set to ");
    if (read_success) search_tree.set_final_node_size(i);
  } else if (opt == PROCESSING_LEAF_SIZE) {
    prompt_string.clear();
    prompt_string = prompt_string + 
    "While the data is read in, the search class can start making the tree.\n"
    "This saves on EXTREMELY long splits in the final data processing phase.\n"+
    "On the other hand, the larger the working leaves are, the flatter the \n"+
    "ultimate tree will be, and the more useful the cover data can be\n"+
    "What maximum size should the working leaves be?";
    i_val = prompted_int(prompt_string,
         search_tree.get_processing_node_size(), read_success, 1, 1<<30,
         "Maximum leaf size during reading set to ",
         "Cannot set maximum leaf size during reading to ");
    if (read_success) search_tree.set_processing_node_size(i_val);
  } else if (opt == DIST_COMP_FACTOR) {
    std::cerr << 
    "Different dimensions can be compared differently. The search algorithm applies\n"<<
    "a scale to each dimension to determine how it will be scaled for the search results\n";
    prompt_string = "Please enter a dimension to scale (1=age, 2 = latitude, 3 = longitude) ";

    read_status = NO_INPUT;
    while(read_status != GOOD_READ) {
      std::cerr << prompt_string;
      dim = input_int(read_status);
      if (dim < 1 || dim > 3) read_success = false;
    }

    prompt_string = "Please enter a scaling factor for ";
    std::string temp_string;
    success_string = "Set ";
    fail_string = "Cannot set ";
    if (dim == 1 ) {
      temp_string = "age ";
    } else if (dim == 2 ) {
      temp_string = "latitude ";
    } else {
      temp_string =  "longitude ";
    }
    success_string += temp_string + "scaling factor set to ";
    fail_string += "scaling factor to ";
    prompt_string += temp_string;
    d_val = prompted_double(prompt_string,
         search_tree.get_dist_scaling_factor(dim-1), read_success, 0.0, 1000000.0,
         success_string, fail_string);

    if (read_success) search_tree.set_dist_scaling_factor(dim-1, d_val);

  } else if (opt == LIMIT_RETURN_SET) {
    prompt_string = 
    "As configured, the search algorithm does ";
    if (search_tree.get_limit_return_set()) prompt_string += "not ";
    prompt_string = prompt_string +              "erase search return values"+
    "in the return set as new, better results are found. It is not clear whether "+
    "this is faster.\n";
    prompt_string += "Should the search throw away results on the fly?";
    search_tree.set_limit_return_set(prompted_bool(prompt_string, "y", "n"));
  } else if (opt == CUT_OFFS) {
    std::cerr << 
    "The search algorithm sets limits on space to be searched.\n"<<
    "You can modify these limits.\n";
    prompt_string = "Please enter a dimension (1=age, 2 = latitude, 3 = longitude) ";

    read_status = NO_INPUT;
    while(read_status != GOOD_READ) {
      std::cerr << prompt_string;
      dim = input_int(read_status);
      if (dim < 1 || dim > 3) read_status = BAD_READ;
    }


    prompt_string = "Setting the ";
    success_string = "";

    std::string temp_string;
    
    if (prompted_bool("Would you prefer to set the upper or lower limit?", "u","l")) {
      temp_string = "upper ";
      i = 1;
    } else {
      temp_string = "lower ";
      i = 0;
    }

    double lower_bound, upper_bound;
    if (dim == 1 ) {
      prompt_string += temp_string+"age ";
      success_string += temp_string+"age limit to ";
      // Methusalah was old enough
      lower_bound = 0.0;
      upper_bound = 969.0;
    } else if (dim == 2 ) {
      prompt_string += "latitude";
      success_string += "latitude limit to ";
      lower_bound = -90.0;
      upper_bound = 90.0;
    } else {
      prompt_string += "longitude";
      success_string += "longitude limit to ";
      lower_bound = -180.0;
      upper_bound = 180.0;
    }
    fail_string = "Cannot set "+success_string;
    success_string  = "Set "+success_string;
    d_val = prompted_double(prompt_string,
         search_tree.get_cutoff(dim-1, i), read_success, lower_bound, upper_bound,
         success_string, fail_string);
    if (read_success) search_tree.set_cutoff(dim-1, i, d_val);

  } else if (opt == SEARCH_RETURN_CONFIG || command == EXIT) {
    config_search = false;
  } //endif
} //end while
        } // endif
      
      } // end while
          
    } else if (command == NEW_DATA) {
      make_data(data_size, step_size, record_generator, record_store, search_tree);
      data_generated = true;
      pause();
    } else if (command == MAIN_EXIT || command == EXIT) {
      std::cerr << "Thank you for using peersearch!\n";
      return 0;
    }
  }

  return 0;
}
    
