/*
 * Filename:   Question_03.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 1 of COEN 243 Winter 2020 Group K
 *             Displays the equivilent values of Fahrenheit and Kelvin for 0
 *             to 20 Celsius
 */
#include <iostream>
using namespace std;

int main() {
  //Declaring variables
  double C;
  double F;
  double K;

  //Title banner
  std::cout << "Celsius\tFahrenheit Kelvin" << '\n';

  //Repeat the following block of code 20 times, incremnting the value 'C'
  for (C = 1; C <= 20; C++) {
    //Calculate the values of Kelvine and Fahrenheit
    K = C + 273.15;
    F = ( C * 9 / 5 ) + 32;
    //Print the values under their repective coloumns
    std::cout << C << '\t' << F << "\t   " << K << '\n';
  }

  //End of function
  return 0;
}
