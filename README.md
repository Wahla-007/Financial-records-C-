
# Transaction Management Program

This program is a simple transaction management system written in C++. It allows users to perform various operations related to transactions such as adding transactions, removing transactions by ID, viewing transaction history, and calculating total transaction amounts.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Add Transaction**: Add a new transaction including description, amount, and number of items.
- **Remove Transaction**: Remove a transaction by specifying its unique ID.
- **View Transaction History**: Display all recorded transactions.
- **Calculate Total Amount**: Compute and display the sum of all transaction amounts.
- **Date Handling**: Automatically timestamps each transaction with the current date.

## Requirements

- C++ compiler that supports C++11 (tested with g++)
- Basic understanding of file handling in C++

## Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yourusername/transaction-management.git
   cd transaction-management
   ```

2. **Compile the program**:

   Compile the program using your C++ compiler. For example, using g++:

   ```bash
   g++ main.cpp -o transaction_manager
   ```

## Usage

1. **Run the program**:

   ```bash
   ./transaction_manager
   ```

2. **Menu Options**:

   - **1**: Add a transaction.
   - **2**: Remove a transaction by ID.
   - **3**: Calculate and display the total transaction amount.
   - **4**: View transaction history.
   - **5**: Exit the program.

3. **Adding a Transaction**:

   - Enter the product description, price, and number of items. Date is automatically recorded.

4. **Removing a Transaction**:

   - Enter the ID of the transaction to remove.

5. **Viewing Transaction History**:

   - Displays all recorded transactions.

6. **Calculating Total Transaction Amount**:

   - Computes and displays the sum of all transaction amounts.

