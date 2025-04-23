# 🏦 Banking System

<div align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/platform-Cross--platform-lightgrey.svg" alt="Platform">
  <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License">
</div>

<p align="center">A simple yet powerful console-based banking system application written in C.</p>

---

## 📋 Overview

This application allows users to manage bank accounts, perform transactions, and store data in a text file database. It's designed with a clean, modular structure following best practices for C programming.

## ✨ Features

<table>
  <tr>
    <td>💼 <b>Create Account</b></td>
    <td>Create a new bank account with personal details like name, age, and gender</td>
  </tr>
  <tr>
    <td>📊 <b>List Accounts</b></td>
    <td>View all accounts in the system with a clean tabular display</td>
  </tr>
  <tr>
    <td>🗑️ <b>Delete Account</b></td>
    <td>Remove an account from the system with confirmation</td>
  </tr>
  <tr>
    <td>💰 <b>Account Operations</b></td>
    <td>Perform transactions like deposit and withdrawal on existing accounts</td>
  </tr>
  <tr>
    <td>💾 <b>Data Persistence</b></td>
    <td>All account data is stored in a text file database for reliability</td>
  </tr>
</table>

## 🗂️ Project Structure

```
Banking System/
├── bin/                  # Contains the compiled executable
├── database/             # Contains the database file
│   └── bank_accounts.txt # Database file storing account information
├── include/              # Header files
│   ├── account.h         # Account structure and functions
│   ├── database.h        # Database operations
│   ├── menu.h            # Menu functions
│   └── ui.h              # User interface functions
├── obj/                  # Object files generated during compilation
├── main/                 # Source files
│   ├── account.c         # Implementation of account functions
│   ├── database.c        # Implementation of database operations
│   ├── menu.c            # Implementation of menu functions
│   └── ui.c              # Implementation of UI functions
├── main.c                # Main program entry point
├── Makefile              # Build script
└── README.md             # Project documentation
```

## 🚀 Compilation and Execution

### Prerequisites

- GCC compiler
- Make utility

### Building the Application

To compile the application:

```bash
make
```

### Running the Application

To run the application:

```bash
make run
```

Or manually:

```bash
./bin/banking_system
```

### Cleaning Build Files

To clean the compiled files:

```bash
make clean
```

## 💾 Database

The application uses a simple text file (`database/bank_accounts.txt`) as a database to store account information. Each line represents one account with comma-separated values in the following format:

```
account_number,name,age,gender,balance,date_of_creation
```

## 📝 Usage Guide

<details>
<summary><b>Click to expand usage instructions</b></summary>

### 1. Create an Account
- Select option 1 from the main menu
- Enter your name, age, and gender
- The system will generate an account number and set initial balance to 0
- Note your account details for future reference

### 2. List All Accounts
- Select option 2 from the main menu
- View a table of all existing accounts with their details

### 3. Delete an Account
- Select option 3 from the main menu
- Choose the account number you wish to delete
- Confirm the deletion

### 4. Account Operations
- Select option 4 from the main menu
- Choose the account you want to operate on
- Select deposit or withdraw options
- Enter the amount and confirm the transaction

### 5. Exit Application
- Select option 5 from the main menu
- Confirm that you want to exit
</details>

## 🔧 Implementation Details

- The account structure includes account number, name, age, gender, balance, and creation date
- Text-based user interface with clear menus and prompts
- File I/O operations for data persistence
- Error handling for invalid inputs and file operations
- Modular design with separation of concerns

## 📜 License

This project is licensed under the MIT License - see the LICENSE file for details.

---

<div align="center">
  <p>Made with ❤️ by a passionate developer</p>
</div> 