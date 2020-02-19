/*
 * Filename:   Question_02.cpp
 * Authors:    William Dorey & David Bitar
 * StudentIDs: 40133598        40122868
 * Description:For assignment 3 of COEN 243 Winter 2020 Group K
 *             Takes an input string of characters, then finds the length of the
 *             string, how many words there are, how many proper words there are
 *             and how many words there are with 2 consecutive letters
 */
#include <iostream>
#include <string>

using namespace std;

//Function prototypes
int strChars(string);
int strWords(string, int);
int strPwords(string, int);
int strDouble(string, int);

//Main function
int main(){
  //Local variables
  int x {0};
  string str;

  //Prompt for the user to enter a string to be stored in str
  std::cout << "Please enter a sentence/string >";
  getline(cin,str);

  //Using the defined functions, find the statistics and display them
  std::cout << "The string \"" << str << "\"contains:" << endl;
  x = strChars(str);
  //Adding a space to more easily count words later
  str = str +' ';
  std::cout << "\tCharacters:\t " << x << endl;
  std::cout << "\tWords:\t\t " << strWords(str, x) << endl;
  std::cout << "\tProper words:\t " << strPwords(str, x) << endl;
  std::cout << "\tWords w/doubles: " << strDouble(str, x) << endl;

  //End of function
  return 0;
}

//Additional functions

//Simple function to return the lenth of the string input
int strChars(string x){
  return x.size();
}

//Function to determine how many words are in the string
int strWords(string a, int b){
  //Because the string will always begin with a word, the counter starts at 1
  int z {1};
  //The loop will check each pair of characters for the combination that would
  //mean a new word has begun (ie space followed by a letter)
  for(int i = 1; i < b ; i++){
    //If there is a space
    if(a[i] == ' '){
      //and if the following character is a letter
      if((a[i+1] >= 'A' && a[i+1] <= 'Z')||(a[i+1] >= 'a' && a[i+1] <= 'z')){
        //increment the counter
        z++;
      }
    }
  }
  return z;
}

//Function similar to strWords(), however will check if the word is proper,
//meaning if the next word starts with a capital letter
int strPwords(string a, int b){
  int z {0};
  //If the first word starts with a capital, the counter will start at one
  if( 'A'<=a[0]&&a[0]<='Z' )
    z = 1;
  //The loop will check each pair of characters for the combination that would
  //mean a new proper word has begun (ie space followed by a capital letter)
  for(int i = 1; i < b ; i++){
    //If there is a space
    if(a[i] == ' '){
      //and if the following character is a capital letter
      if('A'<=a[i+1]&&a[i+1]<='Z'){
        //increment the counter
        z++;
      }
    }
  }
  return z;
}

//Function to test if there are any instances of a letter being the same as the
//preceding letter in a word
int strDouble(string a, int b){
  //Local variables
  int z {0};
  bool same {false};
  //This loop checks each set of consecutive letters to see if they are the same
  for(int i = 1; i < b; i++){
    if(a[i] == ' '){
      //If a there is a space, then there will be a new word, but double spaces
      //will not increase the counter
      same = false;
    }else if(same == true){
      //If the character is still in the same word, skip to the next character
      continue;
    }else if(a[i-1]==a[i] && same == false){
      //If the precious character and the current one are the same, increment z
      z ++;
      same = true;
    }
  }
  //Return the counter value
  return z;
}
