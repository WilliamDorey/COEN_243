/*
 * Filename:   Problem_02.cpp
 * Author:     William Dorey
 * StudentID:  40133598
 * Description:For assignment 2 of COEN 243 Winter 2020 Group K
 *             Builds houses for users using basic ASCII characters using
 *             dimesnions supplied by the user
 */
#include <iostream>
#include <string>
using namespace std;

//declaration of the function to build the house
void build_house(int x, int y);

int main() {
  string name;//String to hold the user's name
  string option;//String that determines if the user would like to build a house
  int height,width;//Dimension varibles for the house
  int fail;//count for exit condition (when user inputs wrong width 3 times)
  int count;//Counter to keep track of how many houses are built each execution
  count = 0;

  //Prompt the user for their name
  std::cout << "What is your name? ";
  std::cin  >> name;

  //Greet the user using their name
  std::cout << "Well " << name << ", welcome to the house drawing program." << '\n';

  //while the user's width input is correct
  while(1){
    //Ask the user if they want to build a house
    //Valid input is 'yes' or 'no'
    std::cout << "Do you want me to draw a simple house for you? (yes/no) ";
    std::cin  >> option;
    if(option == "yes"){
      //If input == yes, the user has chosen to build a house
      //Ask the user what height the house needs to be
      //Their input must be greater than or equal to 1
      do{
        std::cout << "Enter the height of the house you want >";
        std::cin  >> height;
        if(height < 0){
          std::cout << "Sorry, height needs to be a positive number" << '\n';
        }
      }while(height < 0);

      //Initialize the fail counter to start at 0
      fail = 0;

      //Prompt the user to enter the width of the house
      //Input must be an odd number greater than 1
      //If the input is even or less than one, ask the user to try again
      //After three failed attempts, the function will exit and program will terminate
      do{
        std::cout << "Please enter an odd number for the width of the house (must be an odd number and bigger than 1) >";
        std::cin  >> width;
        if(width % 2 == 0){
          std::cout << "You entered " << width << " for the width. Not an odd number." << '\n';
          fail ++;
        }else if(width == 1){
          std::cout << "You entered " << width << " for the width.Has to be more than 1." << '\n';
          fail ++;
        }
        if(fail > 2){
          //user has failed to do valid input 3 times, exit function with 1 instead of 0
          std::cout << "It seems you are having trouble following instructions. Try again later.";
          return 1;
        }
      }while(width < 3 || width%2==0);

      //User has entered valid numbers for height and width
      //Pass their chosen values to the build_house function
      build_house(width, height);

      //Once house is built, increase the counter by 1
      //Counter keeps track of how many houses were built successfully
      //during this program execution
      count ++;
    }else if (option == "no"){
      //If input == no, the user has chosen to exit the program
      //Show the user how many houses they built during program run-time
      std::cout << "\nHope you like your " << count << " houses!" << '\n';
      break;
    }
  }
  //Intended exit point based on user's input of 'No'
  return 0;
}

//The function will build a house based on the user's valid width and height requirements
//The house will be outputted to the user's console
void build_house(int x, int y){
  //int x = width of house, int y = height of house

  int a,b,c;//counter variables for loops

  //Builds the roof of the house using asterisks (*) and spaces
  //counter a is for how many rows are needed for the roof
  //counter b is for the spacing before the asterisk
  //counter c is for outputting the asterisk in the correct position
  for(a = x / 2;a>=0;a--){
    for(b = a; b>0; b--)
      std::cout << ' ';
    for(c = 1; c <= x-(a*2); c ++)
      std::cout << '*';
    std::cout << '\n';
  }

  //Builds the walls of the house using pipes (|) and spaces
  //counter a is for hour many rows are needed for the body of the house
  //counter b is for the number of spaces between the pipes
  //a pipe is outputted before and after the b loop
  for(a=0;a<y;a++){
    std::cout << '|';
    for(b = 0; b < x-2; b++)
      std::cout << ' ';
    std::cout << '|' << '\n';
  }

  //Builds the floor of the house using dashes (-)
  //counter a will output a dash for the width of the house
  for(a = 0; a <x; a++)
    std::cout << '-';
  std::cout << '\n';

}
