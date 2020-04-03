/*
  Filename: houselist.h
  Author:   William Dorey
            40133598
            David Bitar
            40122868
  Description:
            Class deffinitions for classes "HouseList" and "House"
            Member functions defined in houselist.cpp
*/
#include <iostream>
#include <string>

using namespace std;



class House{ //creates the House class
  private:
    //data members
    int age;
    int rooms;
    int id;
    double cost;
    string type;
  public:
    //constructor
    House(int, int, string);
    House();
    //allows user to acess private variables through functions
    int getId();
    void setId(int i);
    int getAge();
    void setAge(int a);
    string getType();
    void setType(string s);
    int getRooms();
    void setRooms(int r);
    double estimatePrice(); //function that estimates price
};

class HouseList{ //creates the HouseList class
 private:
   static const size_t LIST_SIZE = 150; // the maximum items in the list
   House *items; // items will point to the dynamically allocated array
   size_t numItems; // the number of items currently in the list
 public:
   HouseList();
   ~HouseList();
   //functions that print list of houses
   void printList();
   void priceList();
   void priceSortList();
};
