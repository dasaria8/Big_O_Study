#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;


// defined in performance.cpp
void usage();
//WORKS
template <class Key, class T>
void tree_sort(const std::map<Key, T> &theMap, std::ostream &ostr, int &output_count) {
  	//just print them sorted and according to their count
  	output_count = 0;
  	auto it1 = theMap.begin();
	while(it1 != theMap.end()){
		for(int i = 0; i < it1->second; i++){
			ostr << it1->first << endl;
			output_count++;
		}
		it1++;
	}
}

//helper for remove_duplicates
template <class Key, class T>
void tree_find_index_value(const map<Key, T> mp, int index, std::ostream &ostr){
  typename map<Key, T>::const_iterator it = mp.begin();
  while(it != mp.end()){
  	if(it->second == index){
  		ostr << it->first << endl;
  		return;
  	}
  	it++;
  }
}
//have to do the input in here to print the output in the correct order instead of sorted order
void tree_remove_duplicates(istream &istr ,ostream &ostr, const string &type, int &output_count){
  if(type == "string"){
    //index inserted, string value so that it prints in order it was inputted
    map<string, int> mp;
    std::string s;
    int input_count = 0;
    while (istr >> s) {
      if(mp.count(s) != 0){
        continue;
      }
      else{
        mp[s] = input_count;
        input_count++;
      }
    }
    for(int i = 0; i<mp.size(); i++){
      tree_find_index_value(mp, i, ostr);
    }
  }
  else{
    assert(type == "integer");
    //index inserted, string value so that it prints in order it was inputted
    map<int, int> mp;
    int s;
    int input_count = 0;
    while (istr >> s) {
      if(mp.count(s) != 0){
        continue;
      }
      else{
        mp[s] = input_count;
        input_count++;
      }
    }
    for(int i = 0; i<mp.size(); i++){
      tree_find_index_value(mp, i, ostr);
    }
  }
}

//WORKS
template <class Key, class T>
void tree_mode(const std::map<Key, T> &theMap, std::ostream &ostr, int &output_count) {
  	int mode_count = 0;
  	Key mode;
   	auto it1 = theMap.begin();
    while(it1 != theMap.end()){
      if(it1->second > mode_count){
        mode_count = it1->second;
        mode = it1->first;
      }
      it1++;
    }
  	ostr << mode << endl;
  	output_count = 1;
}

int tree_abs(int value){
  int new_value = value *((value>0) - (value<0));
  return new_value;
}
//WORKS
// note: closest_pair is only available for integer data (not string data)
void tree_closest_pair(const std::map<int, int> &theMap, std::ostream &ostr, int &output_count) {
  	assert (theMap.size() >= 2);
  	//loop through theMap
  	long min_difference = 1000000000000000;
  	int final_first;
  	int final_second;
  	auto it1 = theMap.begin();
    while(it1 != theMap.end()){
      	//loop through it again to make every combination
        auto it2 = theMap.begin();
        while(it2 != theMap.end()){
          	//make sure they are not the same number 
          	if(it1->first != it2->first){
            	//getting the next smallest difference and setting the output values to the pair
            	if(tree_abs(it1->first - it2->first) < min_difference){
              		min_difference = tree_abs(it1->first - it2->first);
              		final_first = it1->first;
              		final_second = it2->first;
            	}
          	}
          	it2++;
        }
      	it1++;
    }
  	if(final_first > final_second){
    	ostr << final_second << endl;
    	ostr << final_first << endl;
  	}
  	else{
    	ostr << final_first << endl;
    	ostr << final_second << endl;
  	}
}
//WORKS
//prints the first inputted number of elements in a sorted list
template <class Key, class T>
void tree_first_sorted(const std::map<Key, T> &theMap, std::ostream &ostr, int &output_count, int optional_arg) {
  	assert (optional_arg >= 1);
  	assert ((int)theMap.size() >= optional_arg);
  
  	//have the optional argument as the count
  	output_count = 0;
  	auto it1 = theMap.begin();
	while(it1 != theMap.end()){
		for(int i = 0; i < it1->second; i++){
			ostr << it1->first << endl;
			output_count++;
			//go up to the optional argument
			if(output_count == optional_arg){
				return;
			}
		}
		it1++;
	}
}

//returns the longest substring between 2 strings
string tree_longest_substring_help(string string1, string string2){
    int len1 = string1.length();
    int len2 = string2.length();
    int max_length = 0;
    int end = string1.length();
    //each spot in the 2D array stores the length of the substring
    int char_grid[len1+1][len2+1];
    //make whole array 0
    for(int i = 0; i < sizeof(char_grid)/sizeof(char_grid[0]); i++){
      for(int j = 0; j < sizeof(char_grid)/(sizeof(int)*(sizeof(char_grid)/sizeof(char_grid[0]))); j++){
        char_grid[i][j] = 0;
      }
    }
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            //matches
            if (string1[i-1] == string2[j-1]){
                char_grid[i][j] = char_grid[i-1][j-1]+1;
                //redo maxlen and the end
                if (char_grid[i][j] > max_length)
                {
                    max_length = char_grid[i][j];
                    end = i;
                }
            }
        }
    }
    int start_sub = end - max_length;
    string longest = string1.substr(start_sub, max_length);
    return longest;
}
// note: longest_substring is only available for string data (not integer data)
//loop throuhg thelisttor using longest_substring_help()
//WORKS
void tree_longest_substring(const std::map<string, int> &theMap, std::ostream &ostr, int &output_count) {
  	//
  	// ASSIGNMENT: YOU NEED TO COMPLETE THIS FUNCTION
  	//
  	string longest_sub;
  	int max_length = 0;
  	auto it1 = theMap.begin();
    while(it1 != theMap.end()){
      	//loop through it again to make every combination
        auto it2 = theMap.begin();
        while(it2 != theMap.end()){
          	//make sure they are not the same number 
          	if(it1->first != it2->first){
            	//make substirng and add it to the new map
            	string current = tree_longest_substring_help(it1->first, it2->first);
            	if(current.size() > max_length){
            		max_length = current.size();
            		longest_sub = current;
            	}
          	}
          	it2++;
        }
      	it1++;
    }
    ostr << longest_sub << endl;
}


void bst_test(const std::string &operation, const std::string &type,
              std::istream &istr, std::ostream &ostr,
              int &input_count, int &output_count, int optional_arg) {

	// HINT: For the string element type, declare your binary search tree (BST) like this:
	// std::set<std::string> st;
	// OR 
	// std::map<std::string,int> mp;

	if(operation == "remove_duplicates"){
		tree_remove_duplicates(istr, ostr, type, output_count);
	}
	else{
		if (type == "string") {
			//load input file values into the table
		    map<string, int> mp;
		    //<index, value>
		    //map<int, string> mp2; only use to print the correct output for remove_duplicates
		  
		    std::string s;
		    input_count = 0;
		    while (istr >> s) {
		    	//mp2.insert(pair<int,string>(input_count,s));
		      	mp[s]++;
		      	input_count++;
		    }
	      
		    if      (operation == "sort")              { tree_sort(mp, ostr, output_count); }
		    else if (operation == "mode")              { tree_mode              (mp,ostr,output_count); }
		    // "closest_pair" not available for strings
		    else if (operation == "first_sorted")      { tree_first_sorted(mp,ostr,output_count,optional_arg); }
		    else if (operation == "longest_substring") { tree_longest_substring (mp,ostr,output_count); }
		    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
	      
		}

		else {
			assert (type == "integer");
		    map<int, int> mp;
		    //this holds the <index, value>
		    //map<int, int> mp2; only use to print the correct output for remove_duplicates
		    int s;
		    input_count = 0;
		    while (istr >> s) {
		      mp[s]++;
		      input_count++;
		    }
		    if      (operation == "sort")              { tree_sort(mp, ostr, output_count); }
		    else if (operation == "mode")              { tree_mode              (mp,ostr,output_count); }
		    else if (operation == "closest_pair")      { tree_closest_pair      (mp,ostr,output_count); }
		    else if (operation == "first_sorted")      { tree_first_sorted(mp,ostr,output_count,optional_arg); }
		    // "longest_substring" not available for integers
		    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
		}
	}
}
