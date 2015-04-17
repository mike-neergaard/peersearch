/**
    @file peersearch.h
    @brief data and definitions for the main peersearch engine
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

#ifndef peersearch_H
#define peersearch_H

#include <vector>
#include <array>
#include "record_generator.h"
#include "record_store.h"
#include "space_partition_tree.h"
#include "age_lat_long_searcher.h"



// In case you have to crash out of menus
// I don't use it, but it seems possibly handy
#define EXIT 99999

// This is not terrible for storing menu options, is it?
// Could be better.  Could link enum to strings so they don't
// get out of synch. 
enum {PRINT_ABOUT, DO_SEARCH, CONFIGURE, NEW_DATA, MAIN_EXIT};
std::array<std::string, 5> main_menu_entries ={ "About", "Enter Search", "Configure", 
"Generate New Dataset", "Exit"};

enum {SET_DATA_SIZE, SET_N, STEP_SIZE, SEARCH_CONFIG, CONFIG_RETURN_MAIN};
std::array<std::string,5> config_menu_entries = { "Dataset size", 
"Results to Return", "Set Progress Update Frequency", "Search Configuration", "Return to Main Menu"};


enum { DO_COVER, COVER_RADIUS, COVER_TRIM, FINAL_LEAF_SIZE, 
PROCESSING_LEAF_SIZE, DIST_COMP_FACTOR, LIMIT_RETURN_SET, CUT_OFFS,
SEARCH_RETURN_CONFIG};

std::array<std::string, 9> search_config_menu_entries = {
 "Include cover data", "Cover overlap radius", "Cover trim", "Final Leaf Size", 
"Processing Leaf Size", "Distanace Comparisons", "Limit Return Set", "Limit Search Area",
"Return to Configuration Menu"};

enum{NO_INPUT, GOOD_READ, BAD_READ};

#endif
