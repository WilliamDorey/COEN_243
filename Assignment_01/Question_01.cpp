/*
 * Filename:   Question_01.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 1 of COEN 243 Winter 2020 Group K
 *             Takes 2 numerical inputs and performs basic algebraic operations
 */

#include <iostream>
using namespace std;

int main() {
  //Declaring variables
  double input0;
  double input1;
  double output;

  //Prompt for 2 numerical inputs
  std::cout << "Enter the first number > ";
  std::cin >> input0;

  std::cout << "Enter the second number > ";
  std::cin >> input1;


  std::cout << '\n' << "The results are:" << '\n';
  //Calculating and displaying results
  output = input0 + input1;
  std::cout << "Sum: \t\t" << output << '\n';

  output = input0 - input1;
  if ( output < 0 ) {
    output = output * -1;
  }
  std::cout << "Difference:\t" << output << '\n';

  output = input0 * input1;
  std::cout << "Product:\t" << output << '\n';

  //If the second number is a 0, division is impossible so a message is displayed instead
  std::cout << "Division:\t";
  if ( input1 != 0 ) {
    output = input0 / input1;
    std::cout << output << '\n';
  } else {
    std::cout << "CAN NOT BE CALCULATED BECAUSE OF THE VALUE 0 OF THE SECOND NUMBER" << '\n';
  }
  //End of function
  return 0;
}
