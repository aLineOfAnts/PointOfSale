#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Item {
   public:
       string name;
       float price;
      
  
       void ShowItem() {
           cout << name << " " << price << "$ " << endl;
       }
      
       Item(string name, float price) {
           this->price = price;
           this->name = name;
       }
      
       Item() {


       }
};


class Slot : public Item {
   public:
       int quantity;
       int cost;


       Slot(string name, float price, int quantity) : Item(name, price) {
           this->price = price;
           this->name = name;
           this->quantity = quantity;
           cost = price * quantity;
       }
};