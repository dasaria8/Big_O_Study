#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
//vector hash table that a set for the index
#include <unordered_map>
//vector hash table that a set for the index
using namespace std;

// defined in performance.cpp
void usage();

//helper for remove_duplicates
template <class Key, class T>
void hash_find_index_value(const unordered_map<Key, T> ht, int index, std::ostream &ostr){
  for (int i = 0; i < ht.bucket_count(); i++) {
    auto it1 = ht.begin(i);
    while(it1 != ht.end(i)){
      if(it1->second == index){
        ostr << it1->first << endl;
        return;
      }
      it1++;
    }
  }
}
//Have to do the input in here or else you can't get the correct output
void hash_remove_duplicates(istream &istr ,ostream &ostr, const string &type, int &output_count){
  if(type == "string"){
    //index inserted, string value so that it prints in order it was inputted
    unordered_map<string, int> ht;
    std::string s;
    int input_count = 0;
    while (istr >> s) {
      if(ht.count(s) != 0){
        continue;
      }
      else{
        ht[s] = input_count;
        input_count++;
      }
    }
    for(int i = 0; i<ht.size(); i++){
      hash_find_index_value(ht, i, ostr);
    }
  }
  else{
    assert(type == "integer");
    //index inserted, string value so that it prints in order it was inputted
    unordered_map<int, int> ht;
    int s;
    int input_count = 0;
    while (istr >> s) {
      if(ht.count(s) != 0){
        continue;
      }
      else{
        ht[s] = input_count;
        input_count++;
      }
    }
    for(int i = 0; i<ht.size(); i++){
      hash_find_index_value(ht, i, ostr);
    }
  }
}

//WORKS
template <class Key, class T>
void hash_mode(const std::unordered_map<Key, T> &table,  std::ostream &ostr, int &output_count) {
  //unsigned SIZE = table.bucket_count();
  int mode_count = 0;
  Key mode;
  for (int i = 0; i < table.bucket_count(); i++) {
    auto it1 = table.begin(i);
    while(it1 != table.end(i)){
      if(it1->second > mode_count){
        mode_count = it1->second;
        mode = it1->first;
      }
      it1++;
    }
  }
  ostr << mode << endl;
  output_count = 1;
}

//help with closest pair
int hash_abs(int value){
  int new_value = value *((value>0) - (value<0));
  return new_value;
}
//WORKS
// note: closest_pair is only available for integer data (not string data)
void hash_closest_pair(const std::unordered_map<int, int> &table,  std::ostream &ostr, int &output_count) {
  //check if the table actually has more than 2 values
  int total_elements = 0;
  for (int i=0; i<table.bucket_count(); i++) {
    total_elements += table.bucket_size(i);
  }
  assert (total_elements >= 2);

  //loop through table
  long min_difference = 1000000000000000;
  int final_first;
  int final_second;
  for (int i = 0; i < table.bucket_count(); i++) {
    auto it1 = table.begin(i);
    while(it1 != table.end(i)){
      //loop through it again to make every combination
      for (int j = 0; j < table.bucket_count(); j++) {
        auto it2 = table.begin(j);
        while(it2 != table.end(j)){
          //make sure they are not the same number 
          if(it1->first != it2->first){
            //getting the next smallest difference and setting the output values to the pair
            if(hash_abs(it1->first - it2->first) < min_difference){
              min_difference = hash_abs(it1->first - it2->first);
              final_first = it1->first;
              final_second = it2->first;
            }
          }
          it2++;
        }
      }
      it1++;
    }
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


string hash_longest_substring_help(string string1, string string2){
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

//WORKS
// note: longest_substring is only available for string data (not integer data)
//loop throuhg thelisttor using longest_substring_help()
void hash_longest_substring(std::unordered_map<string, int> &table, std::ostream &ostr, int &output_count) {
  //
  // ASSIGNMENT: YOU NEED TO COMPLETE THIS FUNCTION
  //
  unordered_map<string, int> sub_table;
  //loop through unordered_map and make the substrings for each combination
  for (int i = 0; i < table.bucket_count(); i++) {
    auto it1 = table.begin(i);
    while(it1 != table.end(i)){
      //loop through it again to make every combination
      for (int j = 0; j < table.bucket_count(); j++) {
        auto it2 = table.begin(j);
        while(it2 != table.end(j)){
          if(it1->first != it2->first){
            string current = hash_longest_substring_help(it1->first, it2->first);
            //inserting the substring of each combination into the unordere_map sub_table
            sub_table[current]++;
          }
          it2++;
        }
      }
      it1++;
    }
  }

  //find longest substring in the unordered_map
  int max_length = 0;
  string longest_sub;
  for (int i = 0; i < sub_table.bucket_count(); i++) {
    auto it1 = sub_table.begin(i);
    while(it1 != sub_table.end(i)){
      if(it1->first.length() > max_length){
        max_length = it1->first.length();
        longest_sub = it1->first;
      }
      it1++;
    }
  }
  ostr << longest_sub << endl;
  output_count = 1;
}

void hash_table_test(const std::string &operation, const std::string &type,
                     std::istream &istr, std::ostream &ostr,
                     int &input_count, int &output_count, int optional_arg) {

  	// HINT: For the string element type, declare your hash table like this:
  	// std::unordered_set<std::string> ht;
  	// OR 
  	// std::unordered_map<std::string,int> ht;
  if(operation == "remove_duplicates"){hash_remove_duplicates(istr, ostr, type, output_count);}
  else{
  	if (type == "string") {
  		//load input file values into the table
  	    unordered_map<string, int> ht;
  	    std::string s;
  	    input_count = 0;
  	    while (istr >> s) {
  	      ht[s]++;
  	      input_count++;
  	    }
  	    if      (operation == "sort")              { cout << "it is not feasible/sensible to use operation with this data structure" << endl; }
  	    else if (operation == "mode")              { hash_mode              (ht,ostr,output_count); }
  	    // "closest_pair" not available for strings
  	    else if (operation == "first_sorted")      { cout << "it is not feasible/sensible to use operation with this data structure" << endl; }
  	    else if (operation == "longest_substring") { hash_longest_substring (ht,ostr,output_count); }
  	    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
        
  	}

  	else {
  		assert (type == "integer");
  	    unordered_map<int, int> ht;
  	    int s;
  	    input_count = 0;
  	    while (istr >> s) {
  	      ht[s]++;
  	      input_count++;
  	    }
  	    if      (operation == "sort")              { cout << "it is not feasible/sensible to use operation with this data structure" << endl; }
  	    else if (operation == "mode")              { hash_mode              (ht,ostr,output_count); }
  	    else if (operation == "closest_pair")      { hash_closest_pair      (ht,ostr,output_count); }
  	    else if (operation == "first_sorted")      { cout << "it is not feasible/sensible to use operation with this data structure" << endl; }
  	    // "longest_substring" not available for integers
  	    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  	}
  }
  
}
