/*
  Filename: house.h
  Author:   William Dorey
            40133598
            David Bitar
            40122868
  Description:
            Class definitions for class "House"
            Member functions defined in house.cpp
*/
#include <iostream>

using namespace std;

class House{ //creates the House class
  private:
    //data members
    int age;
    int rooms;
    double cost;
    string type;
  public:
    //constructor
    House(int, int, string);
    
    //allows user to acess private variables through functions
    int getAge();
    void setAge(int a);
    string getType();
    int getRooms();
    
    double estimatePrice(); //function that estimates price
};
