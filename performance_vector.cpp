#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// defined in performance.cpp
void usage();


template <class T>
void vector_sort(std::vector<T> &vec, std::ostream &ostr, int &output_count) {
  // use the vector sort algorithm
  sort(vec.begin(),vec.end());
  output_count = vec.size();
  for (int i = 0; i < output_count; i++)
    ostr << vec[i] << "\n";
}


template <class T>
void vector_remove_duplicates(const std::vector<T> &vec, std::ostream &ostr, int &output_count) { 
  // don't reorder the elements, just do all pairwise comparisons
  output_count = 0;
  for (int i = 0; i < (int)vec.size(); i++) {
    bool dup = false;
    for (int j = 0; j < i; j++) {
      if (vec[i] == vec[j]) {
        dup = true;
        break;
      }
    }
    // if it has not already been added to the output list
    if (!dup) {
      ostr << vec[i] << "\n";
      output_count++;
    }
  }
}


template <class T>
void vector_mode(std::vector<T> &vec, std::ostream &ostr, int &output_count) {
  // use the vector sort algorithm
  sort(vec.begin(),vec.end());
  int current_count = 1;
  T mode;
  int mode_count = 0;
  // keep track of two iterators into the structure
  typename std::vector<T>::iterator current = vec.begin();
  ++current;
  typename std::vector<T>::iterator previous = vec.begin();
  for (; current != vec.end(); ++current, ++previous) {
    if (*current == *previous) {
      // if they are the same element increment the count
      current_count++;
    } else if (current_count >= mode_count) {
      // found a new mode!
      mode = *previous;
      mode_count = current_count;
      current_count = 1;
    } else {
      current_count = 1;
    }
  }
  if (current_count >= mode_count) {
    // last entry is a new mode!
    mode = *previous;
    mode_count = current_count;
  }
  // save the mode to the output vector
  output_count = 1;
  ostr << mode << "\n";
}


// note: closest_pair is only available for integer data (not string data)
void vector_closest_pair(std::vector<int> &vec, std::ostream &ostr, int &output_count) {
  assert (vec.size() >= 2);
  // use the vector sort algorithm
  sort(vec.begin(),vec.end());
  output_count = 2;
  int best;
  int best_index = -1;
  // the two elements with closest value must be next to each other in sorted order
  for (unsigned int i = 0; i < vec.size()-1; i++) {
    int diff = vec[i+1]-vec[i];
    if(diff != 0){
      if (best_index == -1 || diff < best) {
        best = diff;
        best_index = i;
      }
    }
  }
  // print the two elements
  output_count = 2;
  ostr << vec[best_index] << "\n";
  ostr << vec[best_index+1] << "\n";
}


template <class T>
void vector_first_sorted(std::vector<T> &vec, std::ostream &ostr, int &output_count, int optional_arg) {
  assert (optional_arg >= 1);
  assert ((int)vec.size() >= optional_arg);
  // use the vector sort algorithm
  sort(vec.begin(),vec.end());
  output_count = optional_arg;
  for (int i = 0; i < output_count; i++) {
    ostr << vec[i] << "\n";
  }
}
string vector_longest_substring_help(string string1, string string2){
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
void vector_longest_substring(std::vector<std::string> &vec, std::ostream &ostr, int &output_count) {
  //
  // ASSIGNMENT: YOU NEED TO COMPLETE THIS FUNCTION
  //
  vector<string> sub_str_vec;
  for(int i = 0; i<vec.size(); i++){
    for(int j = 0; j<vec.size(); j++){
      //in case we need to check if it is the same word rather than just the same index
      if(vec[j] == vec[i]){
        continue;
      }
      else{
        string current = vector_longest_substring_help(vec[i], vec[j]);
        sub_str_vec.push_back(current);
      }
    }
  }
  //find biggest substring in the vector
  int max = 0;
  string max_sub;
  for(int i = 0; i<sub_str_vec.size(); i++){
    if (sub_str_vec[i].length() > max){
      max = sub_str_vec[i].length();
      max_sub = sub_str_vec[i];
    }
  }
  ostr << max_sub << endl;
  output_count = 1;
}


void vector_test(const std::string &operation, const std::string &type,
                 std::istream &istr, std::ostream &ostr,
                 int &input_count, int &output_count, int optional_arg) {
  if (type == "string") {
    // load the data into a vector of strings
    std::vector<std::string> vec;
    std::string s;
    input_count = 0;
    while (istr >> s) {
      vec.push_back(s);
      input_count++;
    }
    if      (operation == "sort")              { vector_sort              (vec,ostr,output_count); }
    else if (operation == "remove_duplicates") { vector_remove_duplicates (vec,ostr,output_count); }
    else if (operation == "mode")              { vector_mode              (vec,ostr,output_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { vector_first_sorted      (vec,ostr,output_count,optional_arg); }
    else if (operation == "longest_substring") { vector_longest_substring (vec,ostr,output_count);/*vector_longest_substring_help("antenna", "antelope", ostr);*/ }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");
    // load the data into a vector of integers
    std::vector<int> vec;
    int v;
    input_count = 0;
    while (istr >> v) {
      vec.push_back(v);
      input_count++;
    }
    if      (operation == "sort")              { vector_sort              (vec,ostr,output_count); }
    else if (operation == "remove_duplicates") { vector_remove_duplicates (vec,ostr,output_count); }
    else if (operation == "mode")              { vector_mode              (vec,ostr,output_count); }
    else if (operation == "closest_pair")      { vector_closest_pair      (vec,ostr,output_count); }
    else if (operation == "first_sorted")      { vector_first_sorted      (vec,ostr,output_count,optional_arg); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }
}