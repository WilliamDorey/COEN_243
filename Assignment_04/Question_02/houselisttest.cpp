/*
  Filename: houselisttest.cpp
  Author:   William Dorey
            40133598
            David Bitar
            40122868

*/
#include "houselist.h"
#include <iostream>
#include <string>
using namespace std;

int main() //main function
{
  HouseList List0; //function that prompts user to define size of list and input the data for each house
  List0.priceList(); //function that prints the information all houses
  List0.printList(); //function that prints the pricing for all houses
  List0.priceSortList(); //function that prompts user to define a range of price and all houses that

  return 0; //end of execution
}
