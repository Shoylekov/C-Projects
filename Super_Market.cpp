#include <iostream>
#include <fstream>
#include <sstream>
#include <thread> // For sleep_for
#include <chrono> // For chrono literals
using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

class Bill {
private:
    string Item;
    int Rate;
    int Quantity;

public:
    Bill() : Item(""), Rate(0), Quantity(0) {}

    void setItem(const string& item) { Item = item; }
    void setRate(int rate) { Rate = rate; }
    void setQuant(int quant) { Quantity = quant; }

    string getItem() const { return Item; }
    int getRate() const { return Rate; }
    int getQuant() const { return Quantity; }
};

void pause(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) break;
        else {
            cout << "\tInvalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}

void addItem(Bill& b) {
    bool close = false;
    while (!close) {
        int choice = getValidatedInt("\t1. Add Item\n\t2. Close\n\tEnter Your Choice: ");
        if (choice == 1) {
            system(CLEAR);
            string item;
            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            int rate = getValidatedInt("\tEnter the price of the item: ");
            b.setRate(rate);

            int quant = getValidatedInt("\tEnter the Quantity: ");
            b.setQuant(quant);

            ofstream out("Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: Unable to open file!\n";
            } else {
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl;
                cout << "\tItem added successfully!\n";
            }
            out.close();
            pause(3000);
        } else if (choice == 2) {
            system(CLEAR);
            close = true;
            cout << "\tReturning to Main Menu...\n";
            pause(2000);
        }
    }
}

void displayItems() {
    system(CLEAR);
    ifstream in("Bill.txt");
    if (!in) {
        cout << "\tNo items available in the store.\n";
    } else {
        cout << "\n\tAvailable Items in Store:\n";
        cout << "\tItem | Price | Quantity\n";
        cout << "\t------------------------\n";

        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string itemName;
            int itemRate, itemQuant;
            char delimiter;

            ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;
            cout << "\t" << itemName << " | " << itemRate << " | " << itemQuant << endl;
        }
    }
    in.close();
    pause(3000);
}

void printBill() {
    system(CLEAR);
    int total = 0;
    bool close = false;
    
    while (!close) {
        system(CLEAR);
        int choice = getValidatedInt("\t1. Start Shopping\n\t2. Proceed with payment\n\tEnter Choice: ");
        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            quant = getValidatedInt("\tEnter Quantity: ");

            ifstream in("Bill.txt");
            ofstream out("Bill_Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss(line);
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\n\tItem | Price | Quantity | Total Amount\n";
                        cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t" << amount << endl;

                        itemQuant -= quant;
                        total += amount;
                        out << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    } else {
                        cout << "\tInsufficient stock for " << item << ". Only " << itemQuant << " available.\n";
                    }
                } else {
                    out << line << endl;
                }
            }
            if (!found) {
                cout << "\tItem not found in inventory.\n";
            }
            out.close();
            in.close();

            remove("Bill.txt");
            rename("Bill_Temp.txt", "Bill.txt");

            pause(2000);
        } else if (choice == 2) {
            close = true;
            cout << "\tCalculating Total Bill...\n";
            pause(3000);
        }
    }
    system(CLEAR);
    cout << "\n\tTotal Bill ---------------- : " << total << " $\n";
    cout << "\tThank you! Come back again!\n";
    pause(3000);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system(CLEAR);
        int val = getValidatedInt(
            "\tWelcome To Super Market Billing System\n"
            "\t**************************************\n"
            "\t1. Load stock in the store\n"
            "\t2. View available items\n"
            "\t3. Start Shopping\n"
            "\t4. Exit\n"
            "\tEnter Your Choice: ");

        switch (val) {
            case 1:
                system(CLEAR);
                addItem(b);
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printBill();
                break;
            case 4:
                system(CLEAR);
                exit = true;
                cout << "\tGoodbye! Have a nice day! :)\n";
                pause(3000);
                break;
            default:
                cout << "\tInvalid choice. Please try again.\n";
                pause(3000);
        }
    }
}
