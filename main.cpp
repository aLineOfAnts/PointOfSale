#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



//type clang++ -std=c++17 main.cpp -o main && ./main to run program

// NOTE TO SELF CHANGE 1-7 TO 0-7

class POS {
   public:
      string menuNames[15] = {
    "Banana",
    "Orange",
    "Mango",
    "Watermelon",
    "Fresh Bread",
    "Apple",
    "Pear",
    "Tuna",
    "Chicken",
    "Beef",
    "Tofu",
    "Pork",
    "Potato",
    "Strawberry",
    "Whey Protein",
    
 };

   double menuPrice[15] = {
      5,
      6,
      5,
      4,
      5,
      3,
      5,
      5,
      6,
      5,
      5,
      4,
      5,
      3,
      30
   };
 
      //Cart Arrays
      string names[15] = {""};
      double price[15] = {0};
      int quantities[15] = {0};

      bool running = true;
            
   
    float applyTax(float menuPrice) {
	    return menuPrice * 0.12;
    };

   void Options(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           cout << "Resume? \n0. ) Yes \n1.) No \n";
           int input;
           cin >> input;
           if (getSelection(1, input)) {
               if (input == 0) { 
                   cout << endl;
                   Shop(menuN, menuP, names, price, quantities);
               } else {
                   ProcessPayment(menuN, menuP, names, price, quantities); // Add this
               }
           } else {
               Options(menuN, menuP, names, price, quantities);
           }
       }

void PrintReceipt() {
    
}

void Cart() { 
    cout << string(20, '=') << " CART " << string(24, '=') << endl;
    cout << "ITEM" << setw(20) << "QTY" << right << setw(23) << "COST" << endl;
    cout << string(50, '=') << endl;

   for (int i = 0; i < 15; i++) {
      if (names[i] == "") { break; }
      //characters before price need to be 26
      //formatting 
      int l1 = CalculateGap(names[i], 23);
      
      
      cout << names[i] << setw(l1) << right << quantities[i] << right << setw(23) << price[i] << endl;
   }

   cout << endl;
}

int CalculateGap(string str, int max) {
    int gap = 0;
    int num = str.size();

    while (num < max) {
        num++;
        gap++;
    }

    return gap;
}

int CalculateTotal(double price[15]) {
   double total;
   for (int i = 0; i < 15; i++) {
      total += price[i];
   }
   return total;
}

void DisplayHeader(){
    cout << string (50, '=') << endl << "\tWELCOME TO REGIE'S SUPERMARKET" << endl << string (50, '=') << endl;
};

void PrintReceipt(double tax, double total, double change) {
        system("cls");
      cout << "\nTRANSACTION COMPLETE \n";
      cout << "NAME" << setw(10) << "QTY" << setw(10) <<  "PRICE\n";
      for (int i = 0; i < 15; i++) {    
        if (names[i] == "") {break;}
         cout << names[i] << setw(10) << quantities[i] << setw(10) << price[i] << endl;
      }
        cout << "Total: " << total << endl;
        cout << "Change: " << change << endl;
        cout << "Tax: " << tax << endl;


        running = false;
}



 void ProcessPayment(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           
           double subtotal = CalculateTotal(price);
           double tax = applyTax(subtotal);
           double total = subtotal + tax;

           //Cashier Sprite

          
            
           cout << string(16, '=') << " [ CASHIER ] " << string(21, '=') << endl;

           string cashier[16] = {
            "        .--'''''''''--.\n",
            "     .'      .---.      '.\n",
            "    /    .-----------.    \\\n",
            "   /        .-----.        \\\n",
            "   |       .-.   .-.       |\n",
            "   |      /   \\ /   \\      |\n",
            "    \\    | .-. | .-. |    /\n",
            "     '-._| | | | | | |_.-'\n",
            "         | '-' | '-' |\n",
            "          \\___/ \\___/\n",
            "       _.-'  /   \\  `-._\n",
            "     .' _.--|     |--._ '.\n",
            "     ' _...-|     |-..._ '\n",
            "            |     |\n",
            "            '.___.'\n",
            "              | |\n\n"
           };

           cout << endl;
           for (int i = 0; i < 16; i++) {
                cout << string(8, ' ') << cashier[i];
           }
           
            cout << string(50, '=') << endl;
            Cart();
           cout << "Total: " << total << endl << "Insert cash \nAmount: ";
           double input;


           cin >> input;

          
           if (input >= total) {
               PrintReceipt(tax, total, input - total);
           } else {
               cout << "Insufficent amount. ";
               cout << endl;
               running = false;
           }
   }



void Shop(string menuN[7], double menuP[7], string names[15], double price[15], int quantities[15]) {
           int input;
           cout << "Select (0-14): ";
           cin >> input;


           if (getSelection(14, input)) {
             
               for (int i = 0; i < 15; i++) {
                   if (input == i) {


                       AddItem(menuN[i], menuP[i], names, price, quantities);
                       break;
                   }
               }
           } else {
               Shop(menuN, menuP, names, price, quantities);
           }
    }

    

void AddItem(string menuN, double menuP, string names[15], double price[15], int quantities[15]) {
       cout << "\nAdd " << menuN << "?" << endl << "0. ) Yes \n" << "1. ) No \n";
       int input;
       cin >> input;
       
       if (getSelection(1, input)) {
           if (input == 0) {
               cout << "\nInsert a quantity: ";
               
               cin >> input;

               

				//Check if item exists in inventory
               for (int c = 0; c < 15; c++) {
                   if (names[c] == menuN) { //if the same item is already in the cart
                   		quantities[c] += input;
                   		price[c] = menuP * quantities[c];
                        cout << "ADDING ITEM!\n";
                   		return;
				   }
                  
               }
              
            	for (int c = 0; c < 15; c++) {
                   if (names[c] == "") {
                     names[c] = menuN;
                     price[c] = menuP * input;
                     quantities[c] = input;
                     cout << "ADDING ITEM!\n";
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
    return false;
}


void displayHeader(){
cout << string (50, '=') << endl;
cout << "\tWELCOME TO REGIE'S SUPERMARKET" << endl;
cout << string (50, '=') << endl;



};

void getMenu(){
cout << left << setw(20) << "ITEM" << right << setw(27) << "PRICE" << endl;


cout << string (50, '=') << endl;
    for (int i = 0; i < 15; i++) {
	    cout << left << setw(20) << menuNames[i] << " " << right << setw(25) << fixed << setprecision(2) << menuPrice[i] << endl;
    }
    cout << endl;
    Cart();

    int size = 0;
    for (int i = 0; i < 15; i++) {
        if (names[i] == "") {
            break;
        }
        size++;
    }
        
        if (size > 0) {
            Options(menuNames, menuPrice, names, price, quantities);
        } else {
            Shop(menuNames, menuPrice, names, price, quantities);
        }
}





void Run() {
    DisplayHeader();
   while (running) {
      getMenu();
      cout << "\n";
 }
}
      
};



int main() {
   POS pos = POS();
   pos.Run();
   

}

