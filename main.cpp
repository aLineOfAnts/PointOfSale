#include <iostream>
#include <iomanip>
#include <vector>
#include "pos.hpp"
using namespace std;



//type clang++ -std=c++17 main.cpp -o main && ./main to run program

// NOTE TO SELF CHANGE 1-7 TO 0-7

void Options(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           cout << "Resume? \n0. ) Yes \n1.) No \n";
           int input;
           cin >> input;
           if (getSelection(1, input)) {
               if (input == 1) { 
                   cout << endl;
                   Shop(menuN, menuP, names, price, quantities);
               } else {
                   Cashier(menuN, menuP, names, price, quantities); // Add this
               }
           } else {
               Options(menuN, menuP, names, price, quantities);
           }
       }


void Cart(string names[15], double price[15], int quantities[15]) {
   cout << "== Cart ==\n";

   for (int i = 0; i < 15; i++) {
      
      cout << names[i] << " " << price[i] << "$ " << quantities[i] << endl;
   }
   cout << endl;
}


int CalculateTotal(double price[15]) {
   double total;
   for (int i = 0; i < 15; i++) {
      total += price[i];
   }
   return total;
}


void Transaction(string names[15], double price[15], int quantities[15], double total, double change) {
      cout << "\nTRANSACTION COMPLETE \n";
      cout << "NAME" << setw(10) << "QTY" << setw(10) <<  "PRICE";
      for (int i = 0; i < 15; i++) {    
         cout << names[i] << setw(10) << quantities[i] << setw(10) << price[i] << setw(10) << endl;
      }
         cout << "Total: " << total << endl;
         cout << "Change: " << change << endl;


         //running = false;
}



 void Cashier(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           Cart(names, price, quantities);
           double amount = CalculateTotal(price);
           cout << "Total: " << amount << "$\n" << "Insert cash \nAmount: ";
           double input;


           cin >> input;


           if (input >= amount) {
               Transaction(names, price, quantities, amount, input - amount);
           } else {
               cout << "Insufficent amount. ";
               cout << endl;
               running = false;
           }
   }



void Shop(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           int input;
           cout << "Select (1-7): ";
           cin >> input;


           if (getSelection(7)) {
             
               for (int i = 0; i < 15; i++) {
                   if (input - 1 == i) {


                       AddItem(menuN[i], menuP[i], names, price, quantities);
                       break;
                   }
               }
           } else {
               Shop(menuN, menuP, names, price, quantities);
           }
    }


void AddItem(string menuN, double menuP, string names[15], double price[15], int quantities[15]) {
       cout << "\nAdd " << menuN << "?" << endl << "1. ) Yes \n" << "2. ) No \n";
       int input;
       cin >> input;
       
       if (getSelection(1)) {
           if (input == 1) {
               cout << "\nInsert a quantity: ";
               
               cin >> input;

               cout << "ADDING ITEM!";

				//Check if item exists in inventory
               for (int c = 0; c < 15; c++) {
                   if (names[c] == menuN) { //if the same item is already in the cart
                   		quantities[c] += input;
                   		price[c] = menuP * quantities[c];
                   		break;
				   }
                  
               }
              
            	for (int c = 0; c < 15; c++) {
                   if (names[c] == "") {
                     names[c] = menuN;
                     price[c] = menuP;
                     quantities[c] = input;
                     return;
                   }
               }

               cout << "CART FULL" << endl;
               return;
           } else {
               return;
           }
       }
}

bool getSelection(int max, int input)  {
    if (input >= 0 && input <= max) {
        return true;
    }
}



void ShowMenu(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
    cout << "POS SYSTEM \n";
    
    for (int i = 0; i < 7; i++) {
    	
        cout << i + 1 << ".) " << menuN[i] << " " << menuP[i] << "$" << endl;
    }
        cout << endl;
        //Cart(cart);
         
   int size = 0;

   for (int i = 0; i < 15; i++) {
      size++;
      if (names[i] == "") {
         break;
      }
   }
      
    if (size > 0) {
        Options(menuN, menuP, names, price, quantities);
    } else {
        Shop(menuN, menuP, names, price, quantities);
    }
}

void pos() {

}

class User {
	static string names[15];
	static float price[15];
	static int quantities[15];
};

int main() {
 



 


//Menu Arrays
 string menuNames[15] = {
    "Banana",
    "Orange",
    "Mango",
    "Watermelon",
    "Fresh Bread",
    "Apple",
    "Pear"
 };


 double menuPrice[7] = {
    5,
    5,
    6,
    5,
    4,
    5,
    3
 };
 
 //Cart Arrays
 string names[15] = {""};
 double price[15] = {0};
 int quantities[15] = {0};

bool running = true;

 while (running) {
      ShowMenu(menuNames, menuPrice, names, price, quantities);
      cout << "\n";
 }
}

