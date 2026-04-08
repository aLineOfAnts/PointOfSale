#include <iostream>
#include <iomanip>
#include <vector>
#include "item.hpp"
using namespace std;

namespace POS {
    
        static bool running;

        static bool VerifyInput(int min, int max, int input) {
        if (input >= min && input <= max) {
            return true;
        }
        
        cout << "Invalid Input \n";
        return false;
        }

        static bool VerifyInput(double min, double max, double input) {
        if (input >= min && input <= max) {
            return true;
        }
        
        
        cout << "Invalid Input \n";
        return false;
        }

       
        static bool IsRunning() {
            if (running) {
                return true;
            }
            return false;
        }
        
        
        static void Transaction(double change, double total, vector<Slot>& cart) {
            cout << "\nTRANSACTION COMPLETE \n";
            cout << "NAME" << setw(10) << "QTY" << setw(10) <<  "PRICE" << setw(10) << "TOTAL \n";
            for (int i = 0; i < cart.size(); i++) {
                Slot *item = &cart[i];
                
                cout << item->name << setw(10) << item->quantity << setw(10) << item->price << setw(10) << item->cost << endl;
            }
            cout << "Total: " << total << endl;
            cout << "Change: " << change << endl;

            running = false;
        }

        static void LoadItems(string names[17], float prices[17], Item menu[17]) {
            for (int i = 0; i < 15; i++) {
                Item item = Item(
                    names[i],
                    prices[i]
                );


                menu[i] = item;
            }
        }

        static void AddItem(Item item, vector<Slot>& cart) {
        
        cout << "\nAdd " << item.name << "?" << endl << "1. ) Yes \n" << "2. ) No \n";
        int input;
        cin >> input;
        if (VerifyInput(1, 2, input)) {
            if (input == 1) {
                cout << "\nInsert a quantity: ";
            
                cin >> input; 

                cout << "ADDING ITEM!";

                for (int c = 0; c < cart.size(); c++) { 
                    Slot *slot = &cart[c]; //if the same item is already in the cart
                    if (slot->name == item.name) {
                        slot->quantity += input;
                        slot->cost = slot->price * slot->quantity;
                        return;
                    }
                    
                }
                
                Slot slot = Slot(item.name, item.price, input);
                cart.push_back(slot);
                return;
            } else {
                return;
            }
        }


            AddItem(item, cart);
        }

        static void Shop(Item menu[7], vector<Slot>& cart) {
            int input;
            cout << "Select (1-7): ";
            cin >> input;

            if (VerifyInput(1, 7, input)) {
                Item *item;
                for (int i = 0; i < 15; i++) {
                    item = &menu[i];
                    if (input - 1 == i) {

                        AddItem(*item, cart);
                        break;
                    }
                }
            } else {
                Shop(menu, cart);
            }
        }

        static void Cart(vector<Slot>& cart) {
            cout << "== Cart ==\n";

            for (int i = 0; i < cart.size(); i++) {
                Slot *slot = &cart[i];
                cout << slot->name << " " << slot->cost << "$ " << slot->quantity << endl;
            }
            cout << endl;
        }

        static int CalculateTotal(vector<Slot>& cart) {
            double total;
            for (int i = 0; i < cart.size(); i++) {
                total += cart[i].cost;
            }
            return total;
        }
        
        static void Cashier(Item menu[7], vector<Slot>& cart) {
            Cart(cart);
            double amount = CalculateTotal(cart);
            cout << "Total: " << amount << "$\n" << "Insert cash \nAmount: ";
            double input;

            cin >> input;

            if (input >= amount) {
                Transaction(input - amount, amount, cart);
            } else {
                cout << "Insufficent amount. ";
                cout << endl;
                running = false;
            }
        }

        static void Options(Item menu[7], vector<Slot>& cart) {
            cout << "Resume? \n1.) Yes \n2.) No \n";
            int input;
            cin >> input;
            if (VerifyInput(1, 2, input)) {
                if (input == 1) {
                    cout << endl;
                    Shop(menu, cart);
                } else {
                    Cashier(menu, cart);
                }
            } else {
                Options(menu, cart);
            }
        }

        

        

        static void SetRunning() {
            running = true;
        }
        
    
        

        static void ShowMenu(Item menu[7], vector<Slot>& cart) {
            cout << "POS SYSTEM \n";
            Item *item;
            for (int i = 0; i < 7; i++) {
                item = &menu[i];
                cout << i + 1 << ".) " << item->name << " " << item->price << "$" << endl;
            }
                cout << endl;
                Cart(cart);
            
            int size = cart.size();
            
            if (size > 0) {
                Options(menu, cart);
                
            } else {
                Shop(menu, cart);
            }
           
        }
        
        
    };