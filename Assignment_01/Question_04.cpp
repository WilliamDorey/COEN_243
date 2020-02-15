/*
 * Filename:   Question_04.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 1 of COEN 243 Winter 2020 Group K
 *             Takes a numerical input of less than 7 digits from a
 *             user, adds all of the digits together, and finds the
 *             multiples that can form the sum of the digits
 *
 */
#include <iostream>
using namespace std;

int main() {
  //Delcaring Variables
  int input;
  int remainder;
  int total;
  int i;

  //Prompt for a numerical value
  std::cout << "Enter a number that is at most 7 digits > ";
  std::cin >> input;

  //If the value is too long, print a message insted of continuing
  if (input > 9999999) {
    std::cout << "TOO MANY DIGITS!" << '\n';
  } else {
    //Obtain the value of each single digit, add it to the total,
    //and remove it from the original number
    total = input / 1000000;
    remainder = input % 1000000;
    total = total + ( remainder / 100000 );
    remainder = remainder % 100000;
    total = total + ( remainder / 10000 );
    remainder = remainder % 10000;
    total = total + ( remainder / 1000 );
    remainder = remainder % 1000;
    total = total + ( remainder / 100 );
    remainder = remainder % 100;
    total = total + ( remainder / 10 );
    remainder = remainder % 10;
    total = total + remainder;

    //Display the sum of each individual digit combined
    std::cout << "Sum of the digits of " << input << " is: " << total << '\n';
    std::cout << "The divisors of 36 are as follows:" << '\n';

    //Find and display the multiples that can form the previous sum
    for( i = 1; i <= total; i++){
      if ( total % i == 0 ) {
        std::cout << i << " ";
      }
    }
  }
  //End of funtcion
  return 0;
}
