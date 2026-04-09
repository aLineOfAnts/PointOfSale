#include <iostream>
#include <iomanip>

using namespace std;

//type clang++ -std=c++17 main.cpp -o main && ./main to run program


class POS { //Encapsulating all properties and behaviors of the POS system in a singleton class
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
       "Whey Protein"
  
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
     //They refer to the properties of the items in a cart
     //A property of an cart item is accessed via it's index and what array is.
     string names[15] = {""};
     double price[15] = {0};
     int id[15] = {0};
     int quantities[15] = {0};

     //So as long as running is true, the user may continuously add items to their cart till
     //They decide to process payment.
     bool running = true;
          
 
   float applyTax(float menuPrice) { //Returns the tax
       return menuPrice * 0.12;
   };

  void Options() {
   //Asks if the user would like to continue adding items to their shopping cart
          cout << "Resume? \n0. ) Yes \n1.) No \n";
          int input;
          cin >> input;
          if (GetSelection(1, input)) {
              if (input == 0) {
                  cout << endl;
                  Shop();
              } else {
                  ProcessPayment(); //
              }
          } else { //If the response is invalid, the function will call itself again till the input is valid.
              Options();
          }
      }


void Cart() {
   cout << string(20, '=') << " CART " << string(24, '=') << endl;
   cout << "ITEM" << setw(20) << "QTY" << right << setw(23) << "COST" << endl;
   cout << string(50, '=') << endl;

  for (int i = 0; i < 15; i++) {
     if (names[i] == "") { break; }
     //characters before price need to be 26
     //so the gap after name is calculated to prevent the length of the name screwing up
     //the UI.
     int l1 = CalcGap(names[i], 23);
    
    
     cout << names[i] << setw(l1) << right << quantities[i] << right << setw(23) << price[i] << endl;
  }

  cout << endl;
}

int CalcGap(string str, int max) {
   int gap = 0;
   int num = str.size(); //Number starts at the length of the given string

   while (num < max) { //Counts how much space is needed before a max
       num++;
       gap++;
   }

   return gap;
}

int CalcSubtotal(double price[15]) {
  double total;

  for (int i = 0; i < 15; i++) {
       if (names[i] == "") {break; }
       total += price[i];
  }

  return total;
}



   void PrintReceipt(double tax, double total, double change, double cash) {
       system("clear");

     cout << string (50, '=') << endl << "\t\tREGIE'S SUPERMARKET" << endl << setw(29) << "RECEIPT" << endl << string (50, '=') << endl;
     cout << "NAME" << setw(15) << "QTY" << setw(15) << right << "PRICE" << setw(15) << "TOTAL\n";
     cout << string(50, '-') << endl;
     for (int i = 0; i < 15; i++) {   
       if (names[i] == "") {break;}

       int l1 = CalcGap(names[i], 18);
        cout << names[i] << setw(l1) << right << quantities[i] << setw(15) << menuPrice[id[i]] << setw(15) << price[i] << endl;
     }
    
    
       cout << string(50, '-') << endl;

       cout << "Subtotal:" << setw(39) << right <<  total - tax << endl;
       cout << "Tax (12%):" << setw(37) << right << tax << endl;
       cout << string(50, '-') << endl;
       cout << "Total Amount Due: " << setw(30) << right << total << endl;
       cout << string(50, '-') << endl;
       cout << "Cash Tendered: " << setw(33) << cash << endl;
       cout << "Cash Change: " << setw(35) << change << endl;
       cout << string(50, '=') << endl;
       cout << "\t\tTHANKS FOR SHOPPING!\n";
       cout << string(50, '=') << endl;


       running = false;
}



void ProcessPayment() {
          //Calculating subtotal, tax and total with the tax added.
          double subtotal = CalcSubtotal(price);
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

       //Running a for loop for each string to be printed after a string of 8 space characters
       //To center the sprite
          for (int i = 0; i < 16; i++) {
               cout << string(8, ' ') << cashier[i];
          }
         
           cout << string(50, '=') << endl;
           Cart();
           cout << string(50, '-') << endl;

           //Asking for payment from the user
          cout << "Total: " << total << endl << "Insert Payment: ";
          double input;


          cin >> input;
        
          //If the input is higher or equal to the total, a receipt is printed displaying
          //That the user has bought the items they've selected.
          if (input >= total) {
              PrintReceipt(tax, total, input - total, input);
          } else { //If the cash given however is less then the POS will decline the input
           //Due to the insufficent amount.
              cout << "Insufficent amount";
              cout << endl;
              running = false;
          }
  }



void Shop() {
          int input;
          cout << "Select (0-14): ";
          cin >> input;

      
          if (GetSelection(14, input)) { //Ensures input is between 0 and 20 to continue
           
              for (int i = 0; i < 15; i++) {
                  if (input == i) {
                      AddItem(menuNames[i], menuPrice[i], i);
                      break;
                  }
              }
          } else {
              Shop();
          }
   }

  

void AddItem(string menuN, double menuP, int id) {
      cout << "\nAdd " << menuN << "?" << endl << "0. ) Yes \n" << "1. ) No \n";
      int input;
      cin >> input;
     
      if (GetSelection(1, input)) { //If the input is between 0 and 1, it is valid
          if (input == 0) {

               //Input will repeat if user types in a number less than or equal to zero
               while (input <= 0) {
                   cout << "\nInsert a quantity: ";
                   cin >> input;

                   if (input == 0) {
                       cout << "Invalid Input";
                   }
               }

               //Check if item exists in inventory
              for (int c = 0; c < 15; c++) {
                  if (names[c] == menuN) { //if the same item is already in the cart
                       quantities[c] += input;
                       price[c] = menuP * quantities[c];
                       return;
                  }
                
              }
              // If item of the same type does not exist, an empty slot of the item will be
              // overidden
               for (int c = 0; c < 15; c++) {
                  if (names[c] == "") { //A slot of the cart [c] with an empty string names[c] is considered empty
                   //It's properties will be overidden and assigned ot the properties of the requested item
                       names[c] = menuN;
                       price[c] = menuP * input;
                       this->id[c] = id;
                       quantities[c] = input;
                    return;
                  }
              }

              cout << "CART FULL" << endl; //Cart is full
              return;
          } else {
              return;
          }
      }
}

bool GetSelection(int max, int input)  { //Responsible for verifying input
   if (input >= 0 && input <= max) {
       return true;
   }
   cout << "Invalid Input, please try again \n";
   return false;
}


void DisplayHeader(){
   cout << string (50, '=') << endl << "\tWELCOME TO REGIE'S SUPERMARKET" << endl << string (50, '=') << endl;
};

void ShowMenu(){
cout << left << setw(20) << "ITEM" << right << setw(27) << "PRICE" << endl;


cout << string (50, '=') << endl;
   for (int i = 0; i < 15; i++) {
       cout << left << setw(20) << menuNames[i] << " " << right << setw(25) << fixed << setprecision(2) << menuPrice[i] << endl;
   }
   cout << endl;
   Cart();

   int size = 0;

   for (int i = 0; i < 15; i++) {
       if (names[i] == "") { //If the string property of an element in a cart is empty, stop incrementing the size.
           break;
       }
       size++;
   }
      
       if (size > 0) { //When the cart is empty the POS will ask what item you'd like to select
           // Once you have one, after every time the menu is called the program will ask if you'd like to continue.
           Options();
       } else {
           Shop();
       }
}





void Run() {
   //When the program starts it will display the header
   //It will then perform a while loop
   DisplayHeader();
  while (running) {
     ShowMenu();
     cout << "\n";
}
}
    
};



int main() {
  POS pos = POS();
  pos.Run();
 

}



