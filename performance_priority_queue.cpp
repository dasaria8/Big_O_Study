#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

// defined in performance.cpp
void usage();

//WORKS
//already sorted
template <class T>
void queue_sort(std::priority_queue<T,std::vector<T>, std::greater<T> > &pq, std::ostream &ostr, int &output_count) {
  while (!pq.empty()) {
    ostr << pq.top() << endl;
    pq.pop();
  }
}

//Doesn't print in the order they are in the input. Prints in sorted order
//impossible to do without another data structure;
template <class T>
void queue_remove_duplicates(std::priority_queue<T,std::vector<T>, std::greater<T> > &pq, std::ostream &ostr, int &output_count) { 
    //already sorted so we can keep track of the prev element and the current. If it is the same, then just pop it. If it is different then we print it
    //set them to the first element
    T prev_element = pq.top();
    T current_element;
    pq.pop();
    while(!pq.empty()){
      current_element = pq.top();
      if(prev_element == current_element){
        prev_element = current_element;
        pq.pop();
      }
      else{
        ostr << prev_element << endl;
        prev_element = current_element;
        pq.pop();
      }
    }
}


//WORKS
template <class T>
void queue_mode(std::priority_queue<T,std::vector<T>, std::greater<T> > &pq, std::ostream &ostr, int &output_count) {
    int mode_count = 0;
    int current_count = 0;
    T current_element;
    T mode;
    //set everything to the first element
    mode = pq.top();
    current_element = pq.top();
    current_count = 1;
    mode_count = 1;
    pq.pop();
    while (!pq.empty()) {
      //check if it is the same element as the one before and add 1 to the current count
      if(pq.top() == current_element){
        current_count++;
        pq.pop();
      }
      //if it is not equal to the current_element, then set the mode, current_count, mode_count, and new current element
      else{
        //if it is the new mode, then set the current_count to the mode_count and the element to the mode
        if(current_count > mode_count){
          mode_count = current_count;
          mode = current_element;
          //set the new current_element
          current_element = pq.top();
          current_count = 1;
          pq.pop();
        }
        else{
          //set the new current_element
          current_element = pq.top();
          current_count = 1;
          pq.pop();
        }
      }
      
    }
    ostr << mode << endl;
    output_count = 1;
}


int queue_abs(int value){
  int new_value = value *((value>0) - (value<0));
  return new_value;
}

// note: closest_pair is only available for integer data (not string data)
void queue_closest_pair(std::priority_queue<int,std::vector<int>, std::greater<int> > &pq, std::ostream &ostr, int &output_count) {
    assert (pq.size() >= 2);
    //loop through theMap
    long min_difference = 1000000000000000;
    int final_first;
    int final_second;
    int prev_element;
    int current_element;
    //set everything to the first element
    prev_element = pq.top();
    pq.pop();
    while (!pq.empty()) {
      current_element = pq.top();
      //check if it is the same element as the one before
      if(prev_element == current_element){
        prev_element = current_element;
        pq.pop();
      }
      //if it is not equal to the current_element, then find the difference and compare it to min_difference and set the prev to the current
      else{
        //if the difference is smaller then set min_difference and final_first and final_second
        if(queue_abs(current_element - prev_element) < min_difference){
          min_difference = queue_abs(current_element - prev_element);
          final_first = prev_element;
          final_second = current_element;
          //reset previous element
          prev_element = current_element;
          pq.pop();
        }
        else{
          //set the new current_element
          prev_element = current_element;
          pq.pop();
        }
      }
      
    }
    if(final_first > final_second){
      ostr << final_second << endl;
      ostr << final_first << endl;
      output_count = 2;
    }
    else{
      ostr << final_first << endl;
      ostr << final_second << endl;
      output_count = 2;
    }
    
}

//WORKS
//couts the first inputted number of elements in a sorted list
template <class T>
void queue_first_sorted(std::priority_queue<T,std::vector<T>, std::greater<T> > &pq, std::ostream &ostr, int &output_count, int optional_arg) {
    assert((int)pq.size() >= optional_arg);
    output_count = optional_arg;
    int i = 0;
    while (!pq.empty() && i < optional_arg) {
      ostr << pq.top() << endl;
      pq.pop();
      i++;
    }
}

void priority_queue_test(const std::string &operation, const std::string &type,
                         std::istream &istr, std::ostream &ostr,
                         int &input_count, int &output_count, int optional_arg) {

  // HINT: For the string element type, declare your priority_queue like this:

  // std::priority_queue<std::string,std::vector<std::string> > pq;
  // (this will make a "max" priority queue, with big values at the top)

  // OR
  
  // std::priority_queue<std::string,std::vector<std::string>, std::greater<std::string> > pq;
  // (this will make a "min" priority queue, with big values at the bottom)

  if (type == "string") {
    //load input file values into the table
      std::priority_queue<std::string,std::vector<std::string>, std::greater<std::string> > pq;
      std::string s;
      input_count = 0;
      while (istr >> s) {
          //use emplace to insert
          pq.emplace(s);
          input_count++;
      }
      
      //anything that needs to be printed in the order of the input is not possible
      //anything that needs to keep track of the original structure is not possible
      if      (operation == "sort")              { queue_sort(pq, ostr, output_count); }
      else if (operation == "remove_duplicates") { cout << "it is not feasible/sensible to use operation with this data structure" << endl; } //queue_remove_duplicates(pq, ostr, output_count)
      else if (operation == "mode")              { queue_mode              (pq,ostr,output_count); }
      // "closest_pair" not available for strings
      else if (operation == "first_sorted")      { queue_first_sorted(pq,ostr,output_count,optional_arg); }
      else if (operation == "longest_substring") { cout << "it is not feasible/sensible to use operation with this data structure" << endl;  }
      else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
      
  }

  else {
    assert (type == "integer");
      std::priority_queue<int,std::vector<int>, std::greater<int> > pq;
      int s;
      input_count = 0;
      while (istr >> s) {
        pq.emplace(s);
        input_count++;
      }
      //anything that needs to be printed in the order of the input is not possible
      //anything that needs to keep track of the original structure is not possible
      if      (operation == "sort")              { queue_sort(pq, ostr, output_count); }
      else if (operation == "remove_duplicates") { cout << "it is not feasible/sensible to use operation with this data structure" << endl;}//queue_remove_duplicates(pq, ostr, output_count);
      else if (operation == "mode")              { queue_mode              (pq,ostr,output_count); }
      else if (operation == "closest_pair")      { queue_closest_pair      (pq,ostr,output_count); }
      else if (operation == "first_sorted")      { queue_first_sorted(pq,ostr,output_count,optional_arg); }
      // "longest_substring" not available for integers
      else { std::cerr << "Error: Unknown operation: " << operation << std::endl; usage(); exit(0); }
      
  }
}
