#include <iostream>
#include <iomanip>
#include <vector>
#include "item.hpp"
using namespace std;

class POS {
    public:
        static bool VerifyInput(int min, int max, int input) {
        if (input >= min && input <= max) {
            return true;
        }
        
        cout << "Invalid Input \n";
        return false;
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
            cout << "\nInsert a quantity: ";
            
            cin >> input; 

            cout << "ADDING ITEM!";

            for (int c = 0; c < cart.size(); c++) { 
                    Slot *slot = &cart[c]; //if the same item is already in the cart
                    if (slot->name == item.name) {
                        slot->quantity += input;
                        slot->cost = slot->price * slot->quantity;
                    }
                    return;
                }
            
            Slot slot = Slot(item.name, item.price, input);
            cart.push_back(slot);
            return;
        }


        AddItem(item, cart);
        }


        static void Cart(vector<Slot>& cart) {
            cout << "== Cart ==\n";

            for (int i = 0; i < cart.size(); i++) {
                Slot *slot = &cart[i];
                cout << slot->name << " " << slot->cost << "$ " << slot->quantity << endl;
            }
            cout << endl;
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

        int input;
        cin >> input;


        for (int i = 0; i < 15; i++) {
            item = &menu[i];
            if (input - 1 == i) {

                AddItem(*item, cart);
                break;
            }
        }
        
        }
        };