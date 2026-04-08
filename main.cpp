#include <iostream>
#include <iomanip>
#include <vector>
#include "pos.hpp"
using namespace std;


/*
Inventory Capacity: Your system must contain exactly 15 unique items in your arrays.​
Parallel Arrays: Use at least three arrays (Item Names, Item Prices, and Quantities Purchased).
​Input Loop: Use a while or do-while loop to allow the user to add multiple items to a "cart."
​Decision Logic: Use if/else or switch statements to handle menu selections and payment validation.
​Formatting: Use #include <iomanip> to ensure all currency values display with exactly two decimal places (e.g., $5.00).
//clang++ -std=c++17 main.cpp -o main && ./main
*/


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


  enum status {CART, SHOP, COMPLETE};
  bool running = true;


  POS::LoadItems(menuNames, menuPrice, menu);

  POS::SetRunning();

  while (POS::IsRunning()) {
       POS::ShowMenu(menu, cart);
       cout << "\n";
  }
}
