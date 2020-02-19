/*
 * Filename:   Question_03.cpp
 * Authors:    William Dorey & David Bitar
 * StudentIDs: 40133598        40122868
 * Description:For assignment 3 of COEN 243 Winter 2020 Group K
 *             Takes a user input to create a square matrix, then user inputs
 *             to fill in the matrix
 */
#include <iostream>
#include <array>
using namespace std;

//Main function
int main(){
  //Local variables
  int x;
  int sum {0};
  int i,j;
  //Prompt user for matrix size, then to fill matrix
  std::cout << "Matrix size>";
  std::cin >> x;
  int matrix[x][x];
  for( i = 0; i < x; i++){
    for( j = 0; j < x; j++){
      std::cout << "Enter a value for location ["<< i << "," << j <<"] >";
      std::cin >> matrix[i][j];
    }
  }

  //Display matrix (works best for lowwer values inside the matrix)
  std::cout << "Here is the matrix:" << '\n';
  for( i = 0; i < x; i++){
    for( j = 0; j < x; j++){
      std::cout << matrix[i][j] << '\t';
    }
    std::cout << '\n';
  }

  //Add togethor all of the values along the diagonals of the matrix
  for(i = 0; i < x; i++){
    sum = sum + matrix[i][i] + matrix[x-1-i][i];
  }
  //If there is a central spot in the matrix, subtract it to account for it
  //being added twice to the sum
  if( x % 2 == 1){
    sum = sum - matrix[x/2][x/2];
  }

  //Display the result
  std::cout << "The sum of the diagonals is " << sum << '\n';

  //End of program
  return 0;
}
