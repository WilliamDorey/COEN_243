/*
 * Filename:   Question_01.cpp
 * Authors:    William Dorey & David Bitar
 * StudentIDs: 40133598        40122868
 * Description:For assignment 3 of COEN 243 Winter 2020 Group K
 *             Store an amount of grades based on a user input, tracking
 *             the highest and lowest grades, the average, the median and
 *             how many grades fall into the defined letter grade ranges
 */

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

//Declaraition of functions
void maxArray(int arr[], int x);
void minArray(int arr[], int x);
float averageArray(int arr[], int x);
float medianArray(int arr[], int x);
int gradeA(int arr[], int x);
int gradeB(int arr[], int x);
int gradeC(int arr[], int x);
int gradeD(int arr[], int x);
int gradeF(int arr[], int x);

//Main function
int main() {
  //Variables
  int n,i;

  //Prompt user to determine how many input values there will be
  //and make an array of that size
  std::cout << "How many grades do you wish to enter? >";
  std::cin >> n;
  int grades[n];

  //Prompt user for each grade value to fill the array
  for ( i = 0; i < n; i++) {
    std::cout << "Please enter grade " << i+1 << " >";
    std::cin >> grades[i];
  }
  //Use functions to find and display the lowwest and highest 5 values
  maxArray(grades, n);
  minArray(grades, n);

  //Use a function to find the average of all the grades
  std::cout << "\n\nThe average of the grades is " << averageArray(grades, n) << '\n';
  //Use a function to find the median of the array
  std::cout << "\nThe median grade is " << medianArray(grades, n) << '\n';
  //Use functions to determine how many grades correspond to each latter grade
  std::cout << "\nGrade Distribution:" << '\n';
  std::cout << "A: " << gradeA(grades, n) << '\n';
  std::cout << "B: " << gradeB(grades, n) << '\n';
  std::cout << "C: " << gradeC(grades, n) << '\n';
  std::cout << "D: " << gradeD(grades, n) << '\n';
  std::cout << "F: " << gradeF(grades, n) << '\n';

  //End of execution
  return 0;
}

//Function to obtain the 5 highest values from an array
void maxArray(int arr[], int x){
  //Local Variables
  int max[5];
  int a;
  for( a = 0; a < x; a++ ){
    //Check if the value is greater than any of the currently largest values
    //If true, shift the ansers down a spot in the array, and then replace
    //the current value with the new one for that spot
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
  //Display the results
  std::cout << "\nThe 5 highest grades are" << '\n';
  for ( a = 0; a < 5; a++) {
    std::cout << max[a] << '\t';
  }
}

//Function to obtain the 5 lowwest values from an array
void minArray(int arr[], int x){
  //Local variables
  int min[5];
  int a;
  //Check if the value is greater than any of the currently lowwest values
  //If true, shift the ansers down a spot in the array, and then replace
  //the current value with the new one for that spot
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
  //Display the results
  std::cout << "\nThe 5 lowwest grades are" << '\n';
  for ( a = 0; a < 5; a++) {
    std::cout << min[a] << '\t';
  }
}

//Function to obtain the average of an array
float averageArray(int arr[], int x){
  //Local variables
  float out;
  int count;

  out = 0;
  for( count = 0; count < x ; count ++ )
    //add togethor all the values inside the array
    out = out + arr[count];
  //Divide the total to get the average, then return that value
  out = out / x;
  return out;
}

//Function to find the median in an array after sorting
float medianArray(int arr[], int x){
  //Local variable
  float median;
  //Function from <algorithm> that will sort the designated array
  sort(arr, arr+x);
  //Checking if the arr is an odd size or even size
  if( x % 2 == 1){
    //If the array is an odd size, the mdian is the middle most number
    median = arr[ x/2 ];
  }
  else{
    //If the array is an even size, the median is the average of the
    //two middle-most values in the array
    median = ( arr[ x/2 ] + arr[ x/2 + 1 ])/2;
  }
  //Return the median value that was found
  return median;
}

//Functions to count how many grades would fit into each of the letter grades
//All functions check each value in the array and increment their respective
//counters if the value is inside the range of the letter grade, then return
//the counter value
int gradeA(int arr[],int x){
  int i;
  int count = 0;
  for ( i = 0; i < x; i++) {
    if(arr[i] > 80)
      count ++;
  }
  return count;
}
int gradeB(int arr[],int x){
  int i;
  int count = 0;
  for ( i = 0; i < x; i++) {
    if(arr[i] > 70 && arr[i] <= 80)
      count ++;
  }
  return count;
}
int gradeC(int arr[],int x){
  int i;
  int count = 0;
  for ( i = 0; i < x; i++) {
    if(arr[i] > 55 && arr[i] <= 70)
      count ++;
  }
  return count;
}
int gradeD(int arr[],int x){
  int i;
  int count = 0;
  for ( i = 0; i < x; i++) {
    if(arr[i] > 40 && arr[i] <= 55)
      count ++;
  }
  return count;
}
int gradeF(int arr[],int x){
  int i;
  int count = 0;
  for ( i = 0; i < x; i++) {
    if(arr[i] <= 40)
      count ++;
  }
  return count;
}
