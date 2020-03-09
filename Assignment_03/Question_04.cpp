/*
* Filename:   Question_04.cpp
* Authors:    William Dorey & David Bitar
* StudentIDs: 40133598        40122868
* Description:For assignment 3 of COEN 243 Winter 2020 Group K
*
*
*/
#include <iostream>
#include <vector>
using namespace std;

//Main function
int main() {
  vector<signed int> original(10);

  return 0;
}

/*Objective Breakdown:
PART A - Create and organize

create a vector for 100 000 SIGNED integers
fill vector with 100 000 signed integers up to computer data range
randomely select 1000 values
find the data range
User input 'N'
Divide range into N sections
organize the smaples into the partition range that they should be in
organize the remaining values from the 100 000


PART B - Search and add

User input 'I'
Find partion that would contain value I
Search partition for value I
If value is not found, add it to the partition
Ask the user if they want to continue?
	yes - Repeat PART B
	no  - Exit
*/
