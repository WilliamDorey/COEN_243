#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  std::cout << "What's your name?" << '\n';
  std::cin >> name;

  std::cout << "Hello " << name << "!" << '\n';
  return 0;
}
