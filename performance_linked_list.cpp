#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
using namespace std;
// defined in performance.cpp
void usage();

template <class T>
void list_sort(std::list<T> &thelist, std::ostream &ostr, int &output_count) {
  // use the list sort algorithm
  thelist.sort();
  output_count = thelist.size();
  typename std::list<T>::iterator it = thelist.begin();
  while(it != thelist.end()){
    ostr << *it << "\n";
    it++;
  }
}

//FIX THIS LATER
template <class T>
void list_remove_duplicates(const std::list<T> &thelist, std::ostream &ostr, int &output_count) { 
  // don't reorder the elements, just do all pairwise comparisons
  list<T> copyList;
  output_count = 0;
  typename std::list<T>::const_iterator it1 = thelist.begin();
  //typename std::list<T>::iterator it2 = thelist.begin();
  while(it1 != thelist.end()){
    copyList.push_back(*it1);
    it1++;
  }
  copyList.sort();
  copyList.unique();

  //printing: should go back to not being sorted
  typename list<T>::const_iterator original_it = thelist.begin();
  typename list<T>::iterator copy_it = copyList.begin();
  while(original_it != thelist.end()){
  	copy_it = copyList.begin();
  	while(copy_it != copyList.end()){
  		if(*original_it == *copy_it){
  			ostr << *original_it << endl;
  			copyList.remove(*copy_it);
  			break;
  		}
  		copy_it++;
  	}
  	original_it++;
  }
}

template <class T>
void list_mode(std::list<T> &thelist, std::ostream &ostr, int &output_count) {
  // use the thelisttor sort algorithm
  thelist.sort();
  T number = *thelist.begin();
  T mode = number;
  int count = 1;
  int countMode = 1;
  typename std::list<T>::const_iterator it1 = thelist.begin();
  //start from the second element
  it1++;
  while(it1 != thelist.end()){
    //check if the next number is the same as the current number and add 1 to the count of that number
    if (*it1 == number){
      count++;
    }
    else{
      //we have to set the mode to the new number 
      if (count > countMode){
        countMode = count;
        mode = number;
      }
      //reset the number to the next number thats different and set that count back to zero but we stored the old one in countMode above
      count = 1;
      number = *it1;
    }
    it1++;
  }
  output_count = 1;
  ostr << mode << "\n";
}

//returns the list with no duplicatres and is sorted
template <class T>
list<T> remove_duplicates_and_sort(std::list<T> &thelist) { 
  // don't reorder the elements, just do all pairwise comparison
  thelist.sort();
  thelist.unique();
  return thelist;
}
// note: closest_pair is only available for integer data (not string data)
void list_closest_pair(std::list<int> &thelist, std::ostream &ostr, int &output_count) {
  assert (thelist.size() >= 2);
  // use the list sort algorithm
  remove_duplicates_and_sort(thelist);
  std::list<int>::iterator it1 = thelist.begin();
  std::list<int>::iterator it2 = thelist.begin();
  it2++;
  // Compare differences of adjacent pairs to find the minimum difference.
  int minDiff = *it2 - *it1;
  it1 = thelist.begin();
  it1++;
  it1++;
  it2 = it1;
  it2--;
  while(it1 != thelist.end()){
    minDiff = min(minDiff, *it1 - *it2);
    it1++;
    it2++;
  }
  //loop through list and print any pair with difference as minDiff.
  it1 = thelist.begin();
  it1++;
  it2 = it1;
  it2--;
  while(it1 != thelist.end()){
    if ((*it1 - *it2) == minDiff){
      ostr << *it2 << endl;
      ostr << *it1 << endl;

      output_count = 2;
      return;
    }
    it1++;
    it2++;
  }
}
//couts the first inputted number of elements in a sorted list
template <class T>
void list_first_sorted(std::list<T> &thelist, std::ostream &ostr, int &output_count, int optional_arg) {
  assert (optional_arg >= 1);
  assert ((int)thelist.size() >= optional_arg);
  // use the list sort algorithm
  thelist.sort();
  output_count = optional_arg;
  typename std::list<T>::iterator it1 = thelist.begin();
  typename std::list<T>::iterator it2 = thelist.begin();
  //we are going to make it2 the limit for how far we want to print
  //basically the same thing as the thelisttor_first_sorted() but with iterators
  for(int i = 0; i<output_count; i++){
    it2++;
  }
  while(it1 != it2){
    ostr << *it1 << endl;
    it1++;
  }
}
//returns the longest substring between 2 strings
string list_longest_substring_help(string string1, string string2){
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
void list_longest_substring(std::list<std::string> &thelist, std::ostream &ostr, int &output_count) {
  //
  // ASSIGNMENT: YOU NEED TO COMPLETE THIS FUNCTION
  //
  list<string> sub_str_thelist;
  std::list<string>::iterator it1 = thelist.begin();
  std::list<string>::iterator it2 = thelist.begin();
  while(it1 != thelist.end()){
    it2  = thelist.begin();
    while(it2 != thelist.end()){
    	if(*it1 != *it2){
        	string current = list_longest_substring_help(*it1, *it2);
	        sub_str_thelist.push_back(current);
      	}
	    it2++;
    }
    it1++;
  }
  //find biggest substring in the thelist
  int max = 0;
  string max_sub;
  it1 = sub_str_thelist.begin();
  while(it1 != sub_str_thelist.end()){
    if (it1->length() > max){
      max = it1->length();
      max_sub = *it1;
    }
    it1++;
  }
  ostr << max_sub << endl;
  output_count = 1;
}
void list_test(const std::string &operation, const std::string &type,
                 std::istream &istr, std::ostream &ostr,
                 int &input_count, int &output_count, int optional_arg) {

  	// HINT: For the string element type, declare your list like this:
  	// std::list<std::string> lst;
  if (type == "string") {
    // load the data into a list of strings
    std::list<std::string> lst;
    std::string s;
    input_count = 0;
    while (istr >> s) {
      lst.push_back(s);
      input_count++;
    }
    if      (operation == "sort")              { list_sort              (lst,ostr,output_count); }
    else if (operation == "remove_duplicates") { list_remove_duplicates (lst,ostr,output_count); }
    else if (operation == "mode")              { list_mode              (lst,ostr,output_count); }
    // "closest_pair" not available for strings
    else if (operation == "first_sorted")      { list_first_sorted      (lst,ostr,output_count,optional_arg); }
    else if (operation == "longest_substring") { list_longest_substring (lst,ostr,output_count); }
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  else {
    assert (type == "integer");
    // load the data into a vector of integers
    std::list<int> lst;
    int v;
    input_count = 0;
    while (istr >> v) {
      lst.push_back(v);
      input_count++;
    }
    if      (operation == "sort")              { list_sort              (lst,ostr,output_count); }
    else if (operation == "remove_duplicates") { list_remove_duplicates (lst,ostr,output_count); }
    else if (operation == "mode")              { list_mode              (lst,ostr,output_count); }
    else if (operation == "closest_pair")      { list_closest_pair      (lst,ostr,output_count); }
    else if (operation == "first_sorted")      { list_first_sorted      (lst,ostr,output_count,optional_arg); }
    // "longest_substring" not available for integers
    else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
  }

  //std::cerr << "Error: DATA STRUCTURE NOT IMPLEMENTED" << std::endl;
  //exit(0);
}
