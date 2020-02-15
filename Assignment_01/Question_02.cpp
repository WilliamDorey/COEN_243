/*
 * Filename:   Question_02.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 1 of COEN 243 Winter 2020 Group K
 *             Takes a numerical input and displays a corresponding message
 *             containing the equivilent letter grade
 */
#include <iostream>
using namespace std;

int main() {
  //Declaring variables
  int grade;

  //Prompt for a single numerical input
  std::cout << "Enter a numerical grade > ";
  std::cin >> grade;

  //Displays the corresponding output for the input
  if ( grade < 40 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is F" << '\n';
  } else if ( 40 <= grade && grade < 45 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is D-" << '\n';
  } else if ( 45 <= grade && grade < 50 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is D" << '\n';
  } else if ( 50 <= grade && grade < 55 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is D+" << '\n';
  } else if ( 55 <= grade && grade < 60 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is C-" << '\n';
  } else if ( 60 <= grade && grade < 65 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is C" << '\n';
  } else if ( 65 <= grade && grade < 69 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is C+" << '\n';
  } else if ( 69 <= grade && grade < 72 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is B-" << '\n';
  } else if ( 72 <= grade && grade < 77 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is B" << '\n';
  } else if ( 77 <= grade && grade < 80 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is B+" << '\n';
  } else if ( 80 <= grade && grade < 85 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is A-" << '\n';
  } else if ( 85 <= grade && grade < 90 ) {
    std::cout << "The sorresponding letter grade of " << grade << " is A" << '\n';
  } else {
    std::cout << "The sorresponding letter grade of " << grade << " is A+" << '\n';
  }

  //End of function
  return 0;
}
