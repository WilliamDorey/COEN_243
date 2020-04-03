/*
  Filename: house.cpp
  Author:   William Dorey
            40133598
            David Bitar
            40122868
  Description:
            Member functions definitions for class House
*/
#include "house.h"
#include <string>
using namespace std;


House::House(int a, int r, string t){ //sets Houses data
  age = a;
  rooms = r;
  type = t;
  cost = 0;
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

int House::getRooms(){ //returns House's # room
  return rooms;
}
//computes and returns price of house
//depending on the type of house, different % appreciations will be used to calculate the price1

double House::estimatePrice(){ //computes and returns price of house
  double multi; //perecentage of appreciation
  if (type == "Attached") { //for Attached houses
    cost = 100000;//initial price
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
