/*
  Filename: houselist.cpp
  Author:   William Dorey
            40133598
            David Bitar
            40122868
  Description:
            Member functions definitions for classes HouseList and House
*/
#include "houselist.h"
#include <string>
#include <vector>
using namespace std;

//Member Functions for class House
House::House(int a, int r, string t){ //sets Houses data
  age = a;
  rooms = r;
  type = t;
  cost = 0;
}

House::House(){ //initialzes House's data
  age = 0;
  rooms = 0;
  type = "";
  cost = 0;
}

int House::getId(){ //returns House's ID
  return id;
}

void House::setId(int i){ //assigns an ID to ahouse
  id = i;
}

int House::getAge(){ //returns House's age
  return age;
}

void House::setAge(int a){ //prints age of house
  age = a;
}

string House::getType(){ //returns House's type
  return type;
}

void House::setType(string s){ //prints type of house
  type = s;
}

int House::getRooms(){ //returns number of rooms in house
  return rooms;
}

void House::setRooms(int r){ //pases number of rooms of the house
  rooms = r;
}
//computes and returns price of house
//depending on the type of house, different % appreciations will be used to calculate the price
double House::estimatePrice(){ //computes and returns price of house
  double multi; //perecentage of appreciation variable
  if (type == "Attached") { //for Attached houses
    cost = 100000; //initial price
    multi = 0.01; //% appreciation for the firt 5 years
    for(int i = 0; i < age; i++){
      if(i == 5){
        multi = 0.02; //% appreciation after 5 years
      }
      cost = cost + (cost*multi);
    }

  } else if (type == "Semi-Attached") { //for Semi-Attached houses
    cost = 150000; //initial price
    multi = 0.02; //% appreciation for the firt 5 years
    for(int i = 0; i < age; i++){
      if(i == 5){
        multi = 0.03; //% appreciation after 5 years
      }
      cost = cost + (cost*multi);
    }

  } else if (type == "Detached"){ //for Detached houses
    cost = 200000;//initial price
    multi = 0.02; //% appreciation
    for(int i = 0; i < age; i++){
      cost = cost + (cost*multi);
    }

  }
  return cost;
}

//Member Functions for class HouseList

//function that allows user to enter information of houses
HouseList::HouseList(){
  int i {0};
  int age, room;
  string type;
  items = new House[LIST_SIZE];   //uses pointers to create a dynamically allocated array of objects


  do {
    //prompts to the define size of list
    std::cout << "How many houses should this list contain?(max. 150) >";
    std::cin >> numItems;
  } while(!(numItems < LIST_SIZE));

  do {
    //prompts user to enter values for the information of the house
    std::cout << "Information for House " << i << ":\n";
    items[i].setId(i);
    std::cout << "\tAge  >";
    std::cin >> age;
    items[i].setAge(age);
    std::cout << "\tRooms>";
    std::cin >> room;
    items[i].setRooms(room);
    std::cout << "\tType >";
    std::cin >> type;
    items[i].setType(type);
    items[i].estimatePrice();
    i++;
  } while(i < numItems);
}
HouseList::~HouseList(){
  std::cout << "HouseList Destroyed" << '\n';
}

//function that prints the information for each house
void HouseList::printList(){
  std::cout << "********Full House Information********" << '\n';
  for (size_t i = 0; i < numItems; i++) {
    std::cout << "House "<< items[i].getId() << ": " << '\n';
    std::cout << "\tAge  : " << items[i].getAge() << '\n';
    std::cout << "\tRooms: " << items[i].getRooms() << '\n';
    std::cout << "\tType : " << items[i].getType() << '\n';
    std::cout << "\tPrice: " << items[i].estimatePrice() << '\n';
  }
}
//function that prints the price for each house
void HouseList::priceList(){
  std::cout << "**********Full House Pricing**********" << '\n';
  for (size_t i = 0; i < numItems; i++) {
    std::cout << "House "<< items[i].getId() << " Price: " << items[i].estimatePrice() << '\n';
  }
}
//function that sorts the list of Houses and prints the price houses that lie within a range defined by the user
void HouseList::priceSortList(){
  double lb, ub; //variables that will define range
  int hold {0}, held{0};
  vector<House> list;
  std::cout << "**********Sorted Price List***********" << '\n';
  std::cout << "Please enter a value for the lower bound >";
  std::cin >> lb;
  std::cout << "Please enter a value for the upper bound >";
  std::cin >> ub;

  //all of the the houses that lie within the set range are added to a vector
  for (size_t i = 0; i < numItems; i++) {
    if ( (lb<=items[i].estimatePrice())&&(items[i].estimatePrice()<=ub) ) {
      list.push_back(items[i]);
    }
  }
  //for loops sorts the houses added to the vector
  for(int i = 1; i < list.size(); i++){
    for(int j = 0; j < list.size()-i; j++){
      if(list[j].estimatePrice() > list[j+1].estimatePrice()){
        House temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
      }
    }
  }
  //for loop prints the price of Houses that lie that are in the vector
  for (size_t i = 0; i < list.size(); i++) {
    std::cout << "House "<< list[i].getId() << " Price: " << list[i].estimatePrice() << '\n';
  }
}
