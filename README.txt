HOMEWORK 10:  PERFORMANCE & BIG O NOTATION


NAME:  < Arthik Dasari >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< cplusplus.com, mentors in office hours queue>

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 30 >



COMPLEXITY ANALYSIS
n = number of elements in the input
f = requested number of values in output (first sorted only)
l = maximum length of any string element

Neatly fill in the table below with the Big O Notation for running time.

------------------------------------------------------------------------------
|          |          | remove   |          | closest  | first f  | longest  |
|          | sort     | dups     | mode     | pair     | sorted   | substr   | 
------------------------------------------------------------------------------
|          |          |          |          |          |          |          |
| vector   | O(nlogn) |  O(n^2)  | O(nlogn) | O(nlogn) |O(nlogn+f)| O(l^3n^2)|
------------------------------------------------------------------------------
|          |          |          |          |          |          |          |
| list     | O(nlogn) |  O(n^2)  | O(nlogn) | O(nlogn) |O(nlogn+f)| O(l^3n^2)|
------------------------------------------------------------------------------
|          |          |          |          |          |          |          |
| bst      | O(nlogn) |  O(n^2)  | O(nlogn) | O(nlogn) |O(nlogn+f)| O(l^3n^2)|
------------------------------------------------------------------------------
|          |          |          |          |          |          |          |
| pq       | O(nlogn) |    X     | O(nlogn) | O(nlogn) |O(nlogn+f)|     X    |
------------------------------------------------------------------------------
|          |          |          |          |          |          |          |
| hash     |    X     |  O(n^2)  |   O(n)   | O(nlogn) |     X    | O(l^3n^2)|
------------------------------------------------------------------------------



RESULTS
For each data type and each operation, run several sufficiently large
tests and collect the operation time output by the program. Organize
these timing measurements in your README.txt file and estimate the
coefficients for the dominant term of your Big ‘O’ Notation.

< insert your performance measurements and coefficient estimates >
K x Big(O) = Time
note: use the highest value to find the most accurate k-value. As the number of data increases, the k-value gets more accurate.
process: find the most accurate k-value, use that k-value to calculate the expected time for the smaller number of values, compare them and see which ones are too different, write which ones stand out in the essay.
Vector:
sort:
	10,000 length 5 strings: 0.0134 sec
	expected: 0.0106 sec
	100,000 length 5 strings: 0.1325 sec
	accruate k = 2.65x10^-7
remove duplicates:
	5,000 length 3 strings: 0.7899 sec
	expected: 0.6125 sec
	20,000 length 3 strings: 9.7912 sec
	accruate k = 2.45x10^-8
mode:
	10,000 length 4 strings: 0.0124 sec
	expected: 0.00944 sec
	500,000 length 4 strings: 0.6729 sec
	accruate k = 2.36x10^-7
closest pair:
	10,000 8 digit integers: 0.0089 sec
	expected: 0.0069 sec
	500,000 8 digit integers: 0.4950 sec
	accruate k = 1.737x10^-7
first f sorted:
	10,0000 length 4 strings: 0.0081 sec
	expected: 0.046 sec
	100,0000 length 4 strings: 0.5519 sec
	accruate k = 9.198x10^-8
longest substring:
	1,000 length 20 strings: 10.3509 sec
	accruate k = 1.29x10^-9

List:
sort: 
	10,000 length 5 strings: 0.0174 sec
	expected: 0.0171 sec
	500,000 length 5 strings: 1.2235 sec
	accruate k = 4.29x10^-7
*remove duplicates:
	5,000 length 3 strings: 1.3407 sec
	expected: 0.27 sec
	50,000 length 3 strings: 26.9956 sec
	accruate k = 1.08x10^-8
mode:
	10,000 length 4 strings: 0.0182 sec
	expected: 0.0158 sec
	500,000 length 4 strings: 1.1267 sec
	accruate k = 3.95x10^-7
closest pair:
	10,000 8 digit integers: 0.0176 sec
	expected: 0.0151 sec
	500,000 8 digit integers: 1.0779 sec
	accruate k = 3.78x10^-7
*first f sorted:
	10,0000 length 4 strings: 0.0162 sec
	expected: 1.06 sec
	100,0000 length 4 strings: 1.0581 sec
	accruate k = 2.12x10^-6
longest substring:
	500 length 20 strings: 2.5446 sec
	expected: 2.7 sec
	1,000 length 20 strings: 10.8394 sec
	accruate k = 1.35x10^-9

BST: 
sort: 
	10,000 length 5 strings: 0.0286 sec
	expected: 0.0255 sec
	500,000 length 5 strings: 1.8204 sec
	accruate k = 6.388x10^-7
remove duplicates:
	5,000 length 3 strings: 3.6848 sec
	expected: 3.275 sec
	10,000 length 3 strings: 13.1085 sec
	accruate k = 1.31x10^-7
mode:
	10,000 length 4 strings: 0.0121 sec
	expected: 0.0164 sec
	500,000 length 4 strings: 1.1704 sec
	accruate k = 4.1x10^-7
closest pair:
	10,000 8 digit integers: 7.2369 sec
	accruate k = 1.8x10^-4
first f sorted:
	10,0000 length 4 strings: 0.0123 sec
	expected: 0.1105 sec
	100,0000 length 4 strings: 1.3263 sec
	accruate k = 2.21x10^-7
longest substring:
	500 length 20 strings: 2.5784 sec
	expected: 2.6 sec
	1,000 length 20 strings: 10.5421 sec
	accurate k = 1.3x10^-9

Priority Queue:
sort:
	10,000 length 5 strings: 0.0518 sec
	expected: 0.021 sec
	500,000 length 5 strings: 1.5268 sec
	accruate k = 5.358x10^-7
remove duplicates:
	not possible
mode:
	10,000 length 4 strings: 0.0150 sec
	expected: 0.018 sec
	500,000 length 4 strings: 1.3155 sec
	accruate k = 4.6x10^-7
closest pair:
	10,000 8 digit integers: 0.0126 sec
	expected: 0.0118 sec
	500,000 8 digit integers: 0.8428 sec
	accruate k = 2.956x10^-7
first f sorted:
	10,0000 length 4 strings: 0.0092 sec
	expected: 0.02085 sec
	100,0000 length 4 strings: 0.2504 sec
	accruate k = 4.17x10^-8
longest substring:
	not possible

Hash_table:
sort: 
	not possible
remove duplicates:
	5,000 length 3 strings: 5.2071 sec
	expected: 4.35 sec
	10,000 length 3 strings: 17.4265 sec
	accruate k = 1.74x10^-7
mode:
	10,000 length 4 strings: 0.0079 sec
	expected: 0.011 sec
	500,000 length 4 strings: 0.5870 sec
	accruate k = 1.174x10^-6
closest pair:
	10,000 8 digit integers: 24.7730 sec
	accruate k = 6.19x10^-4
*first f sorted:
	not possible
longest substring:
	500 length 20 strings: 2.7532 sec
	expected: 2.62 sec
	1,000 length 20 strings: 10.4733 sec
	accurate k = 1.31x10^-9


DISCUSSION
Do these measurements and the overall performance match your predicted
Big ‘O‘ Notation for the data type and operation? Did you update your
initial answers for the Big ‘O‘ Notation of any cell in the table?

Compare the relative coefficients for different data types that have
the same Big ‘O’ Notation for a specific operation. Do these match
your intuition? Are you surprised by any of the results? Will these
results impact your data structure choices for future programming
projects?

Use well-written, complete sentences.  Approximately 250-500 words.  


< insert your discussion of the results, including your answers to the
above questions >

I used the equation K x Big O = Time. I used that equation to find the k-value which is the coefficient for the dominant term of my Big O. I then used that value to find the expected time and compared it with the experimental time. There were a couple operations where the time stood out. It was like the big O was wrong for it but when I looked at my code, it seemed like the big O was correct. I did get only an 8/10 on the big O for submitty so that could be the case why some of them stood out. 

The times that varied from the expected time was the time for the list "first f sorted" and list "remove duplicates". For the list "first f sorted" I used the equation to find the most accurate k-value and used that k-value on the smaller input to find the expected time. The time that my code took to run it was 0.0162 sec even through the expected time was 1.06 sec. For the list "remove duplicates" I used the equation to find the most accurate k-value and used that k-value on the smaller input to find the expected time. The time that my code took to run it was 1.3407 sec even through the expected time was 0.27 sec.

I completely forgot that input is also included in the time so I had to change most of the cells in the table.

These results will definitely impact my choices for future programming projects because I now know which data structures can and can't do certain operations. If I need to do a certain one of these operations, I know which one takes the least amount of memory and time. This will not be as important with a project that has a small amount of input data. However, if it is a massive amount of data input, the most important part of the project will be which structure I choose that can do the operation in the shortest amount of time while also being memory efficient.



MISC. COMMENTS TO GRADER:  
Optional, please be concise!
