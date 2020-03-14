/*
* Filename:   Question_04.cpp
* Authors:    William Dorey & David Bitar
* StudentIDs: 40133598        40122868
* Description:For assignment 3 of COEN 243 Winter 2020 Group K
*             This program generates 100 000 random values, then samples 1000 of
*             them. Then a user input determines how many partitions(vecotrs),
*             the random numbers will be sorted into.
*             Once all values have been sorted, the user may search/add values.
*/
#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

//Functions
void vectorSorting(vector<long>&, vector<vector<long> >&, int, long, long);
bool vectorCheckDoubles(vector<vector<long> >&, int, long);
void singleValueAdd(long, vector<vector<long> >&, int, long, long);

//Main function
int main() {
  //Declaring variables
  string response;
  int n;
  long min, max, input;

  //Creating empty vectors for unsorted random numbers
  vector<long> original(100000);
  vector<long> selection(1000);

  //Using functionaliites in the <random> library, this will allow us to create
  //mostly random numbers (not completely random because the generator is seed based)
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<signed long> rng;
  std::uniform_int_distribution<int> select;

  //Fill the 'original' vector with random signed integers
  for(int i = 0; i < 100000; i++){
    original[i] = rng(generator);
  }

  //randomly select 1000 values from the 'original' vector to begin partitioning
  //the data into partitions
  min = max = selection[0] = original[rng(generator)%100000];
  for(int j = 1; j < 1000; j++){
    selection[j] = original[select(generator)%100000];
    if(selection[j] < min){
      min = selection[j];
    }else if(selection[j] > max){
      max = selection[j];
    }
  }


  //Tells the user what the data range is and then asks how many partitions
  //should be used
  std::cout << "The range of data is " << min << " to " << max << '\n';
  std::cout << "The total size of the data range is " << max - min << '\n';
  std::cout << "How many partitions should the data be divided into? >";
  std::cin  >> n;
  std::cout << "There will be " << n << " partitions of " << (max-min)/n << " values each" << '\n';

  //Creating a vector of vectors for long data type equal to the amount
  //of partitions required plus one extra for values outside the data range
  vector<vector<long> > sorted(n+1);

  //Sorting the 1000 sample values into their respective partitions and then
  //displaying the distribution of the values across the partitions
  vectorSorting(selection, sorted, n, min, max);
  std::cout << "Number of values in each partition using only selection of 1000 random values:" << '\n';
  for (int i = 0; i <= n; i++) {
    std::cout << "\tThe number of values in partition " << i+1 << " is ";
    std::cout << sorted[i].size() << '\n';
  }

  //Sorting the remaining values into their respective partitions and then
  //displaying the distribution of the values across the partitions
  vectorSorting(original, sorted, n, min, max);
  std::cout << "Now including original 100 000 values:" << '\n';
  for (int i = 0; i <= n; i++) {
    std::cout << "\tThe number of values in partition " << i+1 << " is ";
    std::cout << sorted[i].size() << '\n';
  }
  std::cout << "Partition "<< n+1 << " contains values outside the data range" << '\n';

  //Asking the user what value they want to search for repeatedly until they
  //respond "no"
  do {
    std::cout << "What value do you want to search for? >";
    std::cin >> input;
    std::cout << "Checking if "<< input << " exists in a partition..." <<'\n';
    singleValueAdd(input, sorted, n, min, max);
    std::cout << "Search for another value? (yes/no) >";
    std::cin >> response;
  } while(response != "no");
  return 0;
}

//Function to sort values found in a vector into a 2-dimensional vector by range
//but only if it would be a unique value in the range
void vectorSorting(vector<long>& input, vector<vector<long> >& output, int sections, long min, long max){
  long delta = (max - min) / sections;
  for(int i = 0; i < input.size(); i++){
    if(input[i] < min || input[i] > max){
      //Add to partition 'N+1' for values outsde the data range
      if(!(vectorCheckDoubles(output, sections, input[i])))
        output[sections].push_back(input[i]);
    }else if((max - delta) <= input[i] && input[i] <= max){
      //Place value in last partition as it is the largest possible value set
      //in the data range
      if(!(vectorCheckDoubles(output, sections-1, input[i])))
        output[sections-1].push_back(input[i]);
    }else{
      //Checks the value against each partition's data range and places it in
      //the correct partition
      for(int j = 0; j < sections-1; j++){
        if((min+(delta*j)) <= input[i] && input[i] < (min+(delta*(j+1))) ){
          if(!(vectorCheckDoubles(output, j, input[i])))
            output[j].push_back(input[i]);
        }
      }
    }
  }
}

//Checks that a passed value is not already present in the vector
bool vectorCheckDoubles(vector<vector<long> >& vect, int row, long value){
  for(int i = 0; i < vect[row].size(); i++){
    if(vect[row][i] == value)
      return true;
  }
  return false;
}

//Function to sort a single value into a 2-dimensional vector by range
//but only if it would be a unique value in the range
void singleValueAdd(long input, vector<vector<long> >& output, int sections, long min, long max){
  long delta = (max - min) / sections;
  if(input < min || input > max){
    std::cout << "Value is outside of data range" << '\n';
  }else if((max - delta) <= input && input <= max){
    //Place value in last partition as it is the largest possible value set
    //in the data range
    if(!(vectorCheckDoubles(output, sections-1, input))){
      output[sections-1].push_back(input);
      std::cout << "Adding " << input << " to partition " << sections << '\n';
    }else{
      std::cout << "Value already exists in partition " << sections << '\n';
    }
  }else{
    //Checks the value against each partition's data range and places it in
    //the correct partition
    for(int j = 0; j < sections-1; j++){
      if((min+(delta*j)) <= input && input < (min+(delta*(j+1))) ){
        if(!(vectorCheckDoubles(output, j, input))){
          output[j].push_back(input);
          std::cout << "Adding " << input << " to partition " << j+1<< '\n';
        }else{
          std::cout << "Value already exists in partition " << j+1<< '\n';
        }
      }
    }
  }
}
