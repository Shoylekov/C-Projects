# Super Market Billing System

## Overview
The Super Market Billing System is a simple command-line application that allows users to manage a supermarket's billing operations. Users can add items to the inventory, view available items, and calculate the total bill for purchases. The application demonstrates basic file handling, data validation, and user interaction in C++.

## Features
- **Add Items**: Users can add items to the store's inventory with details such as item name, price, and quantity.
- **View Available Items**: Before shopping, users can view all available items in the store.
- **Shopping**: Users can enter the item and quantity they wish to purchase, and the application will calculate the total amount.
- **Bill Calculation**: The total bill is calculated and displayed at the end of the shopping session.
- **Data Persistence**: Item details are stored in a text file (`Bill.txt`) for persistence between program runs.

## Prerequisites
- A C++ compiler (e.g., g++, clang++)
- A text editor or IDE (e.g., Visual Studio Code, Code::Blocks)

## How to Run
1. Clone the repository or download the source code files.
2. Open your terminal/command prompt.
3. Navigate to the directory where the source files are located.
4. Compile the program using the following command:
   ```bash
   g++ Super_Market.cpp -o Super_Market.exe
## Usage
### When prompted, choose an option:

1: Load stock in the store (Add items)
2: View available items
3: Start shopping
4: Exit the program
Follow the on-screen prompts to add items, view inventory, or make purchases.

File Structure
Super_Market.cpp: The main source code file containing the implementation of the billing system.
Bill.txt: A text file that stores item details (created/updated by the program).
Example
Adding an Item
plaintext
Copy code
Enter Item Name: Apples
Enter the price of the item: 2
Enter the Quantity: 50
Item added successfully!
Viewing Available Items
plaintext
Copy code
Available Items in Store:
Item | Price | Quantity
------------------------
Apples | 2 | 50
Shopping
plaintext
Copy code
Enter Item: Apples
Enter Quantity: 10
Item | Price | Quantity | Total Amount
Apples | 2 | 10 | 20
Total Bill
plaintext
Copy code
Total Bill ---------------- : 20 $
Thank you! Come back again!
Contributing
Feel free to submit issues, suggest features, or contribute code via pull requests.