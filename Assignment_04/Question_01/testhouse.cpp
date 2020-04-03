#include <iostream>
#include <string>
using namespace std;

#include "house.h"

int main() //main function
{
  int age, rooms; //variables
  double cost;
  string type;

  //prompts user to enter values for the information of the house
  std::cout << "Please enter the information for house 1:" << endl;
  std::cout << "\tAge: ";
  std::cin >> age;

  std::cout << "\tRooms: ";
  std::cin >> rooms;

  std::cout << "\tType: ";
  std::cin >> type;

  House house1(age, rooms, type); //creation of the  first object (House 1)

  //prompts user to enter values for the information of the house

  std::cout << "\nPlease enter the information for house 2:" << endl;
  std::cout << "\tAge: ";
  std::cin >> age;

  std::cout << "\tRooms: ";
  std::cin >> rooms;

  std::cout << "\tType: ";
  std::cin >> type;

  House house2(age, rooms, type); //creation of the first object (House 2)

  //prints the price for both objects defined by values inputed for each house
  std::cout << "\nThe estimated price of house 1 is " << house1.estimatePrice() << '\n';
  std::cout << "The estimated price of house 2 is " << house2.estimatePrice() << '\n';

    return 0; //end of execution
}
