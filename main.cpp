#include <iostream>
#include <iomanip>
#include <vector>
#include "pos.hpp"
using namespace std;

//type clang++ -std=c++17 main.cpp -o main && ./main to run program


int main() {
   // Data
  string names[15];
  float price[15];
  int quantities[15];


  Item items[15];
  vector<Slot> cart;


  string menuNames[7] = {
     "Banana",
     "Orange",
     "Mango",
     "Watermelon",
     "Fresh Bread",
     "Apple",
     "Pear"
  };

  float menuPrice[7] = {
     5,
     5,
     6,
     5,
     4,
     5,
     3
  };

  Item menu[7];

  POS::LoadItems(menuNames, menuPrice, menu);

  POS::SetRunning();

  while (POS::IsRunning()) {
       POS::ShowMenu(menu, cart);
       cout << "\n";
  }
}
