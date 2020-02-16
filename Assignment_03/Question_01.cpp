/*
 * Filename:   Question_01.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 3 of COEN 243 Winter 2020 Group K
 *             Store an amount of grades based on a user input, tracking
 *             the highest and lowest grades, the average, the median and
 *             how many grades fall into the defined letter grade ranges
 */

 /*
Objectives:
    max
    min
    average
    median
    grade distribution
 */
#include <iostream>
using namespace std;

//Functions
void maxArray(int arr[], int x);
void minArray(int arr[], int x);
float averageArray(int arr[], int x);
//int medianArray(int arr[], int x);
//int* distArray(int arr[], int x);

int main() {
  //Variables
  int n,i;
  float avg;

  std::cout << "How many grades do you wish to enter? >";
  std::cin >> n;
  int grades[n];
  for ( i = 0; i < n; i++) {
    std::cout << "Please enter grade " << i+1 << " >";
    std::cin >> grades[i];
  }
  maxArray(grades, n);
  minArray(grades, n);

  avg = averageArray(grades, n);
  std::cout << "\nThe average of the grades is " << avg << '\n';

  return 0;
}

//Function to obtain the 5 highest values from an array
void maxArray(int arr[], int x){
  int max[5];
  int a;
  for( a = 0; a < x; a++ ){
    if (arr[a] > max[0]) {
      max[4] = max[3];
      max[3] = max[2];
      max[2] = max[1];
      max[1] = max[0];
      max[0] = arr[a];
    } else if (arr[a] > max[1]) {
      max[4] = max[3];
      max[3] = max[2];
      max[2] = max[1];
      max[1] = arr[a];
    } else if (arr[a] > max[2]) {
      max[4] = max[3];
      max[3] = max[2];
      max[2] = arr[a];
    } else if (arr[a] > max[3]) {
      max[4] = max[3];
      max[3] = arr[a];
    } else if (arr[a] > max[4]) {
      max[4] = arr[a];
    }
  }
  std::cout << "\nThe 5 highest grades are" << '\n';
  for ( a = 0; a < 5; a++) {
    std::cout << max[a] << '\t';
  }
}
//Function to obtain the 5 lowwest values from an array
void minArray(int arr[], int x){
  int min[5];
  int a;
  for( a = 0; a < x; a++ ){
    if (arr[a] < min[0]) {
      min[4] = min[3];
      min[3] = min[2];
      min[2] = min[1];
      min[1] = min[0];
      min[0] = arr[a];
    } else if (arr[a] < min[1]) {
      min[4] = min[3];
      min[3] = min[2];
      min[2] = min[1];
      min[1] = arr[a];
    } else if (arr[a] < min[2]) {
      min[4] = min[3];
      min[3] = min[2];
      min[2] = arr[a];
    } else if (arr[a] < min[3]) {
      min[4] = min[3];
      min[3] = arr[a];
    } else if (arr[a] < min[4]) {
      min[4] = arr[a];
    }
  }
  std::cout << "\nThe 5 lowwest grades are" << '\n';
  for ( a = 0; a < 5; a++) {
    std::cout << min[a] << '\t';
  }

}
//Function to obtain the average of an array
float averageArray(int arr[], int x){
  float out;
  int count;
  out = 0;
  for( count = 0; count < x ; count ++ )
    out = out + arr[count];
  out = out / x;
  return out;
}
