# ATM System

## Project Overview

This ATM system is a C++ console application that allows users to perform basic banking operations such as creating new accounts, depositing money, transferring funds between accounts, and withdrawing money. The system validates account details like account name and card number, ensuring they adhere to the required format. Additionally, the system handles transaction fees for transfers and withdrawals, adding bonuses for deposits.

## Features

- **Create New Account**: Add a new account with a unique card number and a valid account name.
- **Deposit**: Deposit money into an existing account, with a 1% bonus on the deposited amount.
- **Transfer**: Transfer funds between two accounts, with a 1.5% fee deducted from both the sender and receiver.
- **Withdrawal**: Withdraw money from an account, with a 3% deduction applied as a fee.
- **Error Handling**: Ensures valid input for account creation, deposits, transfers, and withdrawals. Proper error messages are displayed for invalid inputs.
- **Account Information**: Displays account information after each operation (account name, card number, and current balance).

## Requirements

### Programming Language
- **C++**

### Libraries
- `<iostream>`: Used for input/output operations.
- `<limits>`: Used to handle input validation for account names and card numbers.

### Build Tools
- Any C++ compiler (e.g., GCC, Clang, MSVC).

 **Menu Options**:
Upon running the program, you will see a menu with the following options:
1----Create new account 2----Deposit 3----Transfer to another account 4----Withdrawal 5----Exit

markdown
Copy code

 **Choose an Operation**:
- Select a number corresponding to the desired operation.
- The system will guide you through input prompts for each operation.

## Functionality Breakdown

### Account Creation
- Ensures the account name contains only English letters and spaces.
- Card numbers must be exactly 10 digits long and cannot be the same as any existing card number or consist of all the same digits (e.g., 1111111111).
  
### Deposit
- Adds a 1% bonus to any amount deposited.
  
### Transfer
- Deducts a 1.5% fee from both the sender and receiver accounts during a transfer.
- Prevents transferring more than the available balance.

### Withdrawal
- Deducts a 3% fee from the withdrawn amount.

### Input Validation
- Handles invalid inputs for account name, card number, and monetary amounts.
- Ensures proper user input by checking for non-numeric characters, incorrect lengths, and more.

