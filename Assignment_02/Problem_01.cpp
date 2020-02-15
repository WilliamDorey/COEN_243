/*
 * Filename:   Problem_01.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 2 of COEN 243 Winter 2020 Group K
 *             Takes 2 numerical inputs to define the size of a matrix, then asks
 *             for user input for each space defined inside the matrix, calculating
 *             the smallest value, largest value, total sum and average of all
 *             input values
 */
#include <iostream>
using namespace std;

int main() {
  int x,y; //Dimension variables
  int a,b; //Counter variables
  int temp;//Input variable
  double sum,min,max;//Statistic variables
  float avg;//average is a float so that decimals are possible

  //Asks user for the dimensions of the matrix
  std::cout << "Enter the horizontal value of a matrix >";
  std::cin >> x;
  std::cout << "Enter the vertical value of a matrix   >";
  std::cin >> y;
  std::cout << "The matrix will have the dimensions: [" << x << ',' << y << "]\n";

  //Continuously ask the user for values until all spaces in the matrix have been filled
  for (a = 0; a < x; a++) {
    for (b = 0; b < y; b++) {
      //Prompt the user to enter a value for the specific location in the matrix
      std::cout << "Enter the value for [" << a << ',' << b <<"] >";
      std::cin >> temp;
      //If this is the first entry, all the stats will be set to this entry
      if (a==0&&b==0) {
        min=max=avg=temp;
        sum=0;
      }
      //If the latest entry is bigger or smaller than the current min/max, replace the value
      if ( temp < min) {
        min = temp;
      } else if (temp > max) {
        max = temp;
      }
      //Display the min and max values
      std::cout << "min: " << min << "\tmax: " << max << '\n';
      //Add the latest value to the total sum and then use that value to calculate the average
      sum = sum + temp;
      avg = sum/((a*y)+b+1);
      //Display the sum and average
      std::cout << "sum: " << sum << "\tavg: " << avg << '\n';
    }
  }

  return 0;
}
