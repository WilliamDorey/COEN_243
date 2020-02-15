/*
 * Filename:   Question_05.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 1 of COEN 243 Winter 2020 Group K
 *             Takes 3 numerical inputs from a user, then displays
 *             them in ascending order
 */
#include <iostream>
using namespace std;

int main() {
  //Declaring Variables
  int val0;
  int val1;
  int val2;

  //Prompt for 3 numerical values
  std::cout << "Enter the first value  > ";
  std::cin >> val0;
  std::cout << "Enter the second value > ";
  std::cin >> val1;
  std::cout << "Enter the third value  > ";
  std::cin >> val2;

  //If val0 is the smallest, execute the following block of code
  if ( val0 <= val1 && val0 <= val2) {
    std::cout << val0 << ", ";
    if ( val1 < val2 ) {
      std::cout << val1 << ", " << val2 << '\n';
    } else {
      std::cout << val2 << ", " << val1 << '\n';
    }
  //If val0 is the biggest, execute the following block of code
  } else if (val0 >= val1 && val0 >= val2){
    if ( val1 < val2 ) {
      std::cout << val1 << ", " << val2 << ", " << val0 << '\n';
    } else {
      std::cout << val2 << ", " << val1 << ", " << val0 << '\n';
    }
  //If val0 is the middle value, check which othe value is smaller
  } else {
    if ( val1 < val2 ) {
      std::cout << val1 << ", " << val0 << ", " << val2 << '\n';
    } else {
      std::cout << val2 << ", " << val0 << ", " << val1 << '\n';
    }
  }

  //End of function
  return 0;
}
