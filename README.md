# 🏦 Banking System

<div align="center">
  <!-- Removed image reference that doesn't exist -->
  
  [![Language](https://img.shields.io/badge/language-C-blue.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
  [![Platform](https://img.shields.io/badge/platform-Linux%2FmacOS%2FWindows-lightgrey.svg?style=for-the-badge&logo=windows)](https://github.com/yourusername/banking-system)
  [![License](https://img.shields.io/badge/license-MIT-green.svg?style=for-the-badge&logo=opensourceinitiative)](LICENSE)
  <!-- Add other relevant badges like build status if applicable -->
  <!-- [![Build Status](https://img.shields.io/github/actions/workflow/status/yourusername/banking-system/.github/workflows/build.yml?branch=main&style=for-the-badge&logo=github)](https://github.com/yourusername/banking-system/actions) -->
</div>

<p align="center">
  <b>A robust and user-friendly console-based banking system application written in C.</b>
</p>

<div align="center">
  
  [**Features**](#-features) • 
  [**Installation**](#-getting-started) • 
  [**Usage**](#-usage-guide) • 
  [**Contributing**](#-contributing) • 
  [**License**](#-license)
  
</div>

---

## 📖 Table of Contents

- [📋 Overview](#-overview)
- [✨ Features](#-features)
- [🏗️ Project Structure](#️-project-structure)
- [🚀 Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation & Compilation](#installation--compilation)
  - [Running the Application](#running-the-application)
- [💾 Database](#-database)
- [📝 Usage Guide](#-usage-guide)
- [🔧 Implementation Details](#-implementation-details)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)

---

## 📋 Overview

<!-- Removed image reference that doesn't exist -->

This console application simulates basic banking operations, allowing users to manage accounts through a command-line interface.

> **Key Capabilities:**
> - Account creation, viewing, deletion
> - Transaction processing (deposits/withdrawals)
> - Data persistence via text file database

The project emphasizes a modular design using separate header and source files for better organization and maintainability.

---

## ✨ Features

<table>
  <tr>
    <td width="60" align="center">👤</td>
    <td><b>Account Management</b></td>
    <td>
      <ul>
        <li>✅ Create new accounts with personal details</li>
        <li>✅ View a list of all existing accounts in a formatted table</li>
        <li>✅ Delete accounts with user confirmation</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td width="60" align="center">💳</td>
    <td><b>Transaction Processing</b></td>
    <td>
      <ul>
        <li>✅ Deposit funds into accounts</li>
        <li>✅ Withdraw funds from accounts</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td width="60" align="center">💾</td>
    <td><b>Data Persistence</b></td>
    <td>
      <ul>
        <li>✅ Account data saved to text file</li>
        <li>✅ Data loaded upon application start</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td width="60" align="center">🖥️</td>
    <td><b>User Interface</b></td>
    <td>
      <ul>
        <li>✅ Intuitive console-based menu system</li>
        <li>✅ Clear prompts and feedback for user actions</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td width="60" align="center">🧱</td>
    <td><b>Architecture</b></td>
    <td>
      <ul>
        <li>✅ Modular codebase organization</li>
        <li>✅ Clean separation of concerns</li>
      </ul>
    </td>
  </tr>
</table>

---

## 🏗️ Project Structure

The project follows a clean, organized structure to promote maintainability and code reuse.

<details open>
<summary><b>Directory Structure</b></summary>
<br>

```
Banking System/
├── bin/                  # Compiled executable binary
├── database/             # Database storage directory
│   └── bank_accounts.txt # Text file database for account data
├── helper/               # Source files for helper modules
│   ├── account.c         # Account management logic
│   ├── database.c        # Database read/write operations
│   ├── menu.c            # Menu display and navigation logic
│   └── ui.c              # User interface elements (prompts, tables)
├── include/              # Header files for declarations
│   ├── account.h         # Account structure and function prototypes
│   ├── database.h        # Database function prototypes
│   ├── menu.h            # Menu function prototypes
│   └── ui.h              # UI function prototypes
├── obj/                  # Object files generated during compilation
├── .gitattributes        # Git attributes configuration
├── .gitignore            # Specifies intentionally untracked files
├── LICENSE               # Project license file (MIT)
├── main.c                # Main application entry point
├── Makefile              # Build script for compiling the project
└── README.md             # This documentation file
```
</details>

---

## 🚀 Getting Started

Follow these instructions to get the project up and running on your local machine.

### Prerequisites

<details>
<summary><b>Expand to view required dependencies</b></summary>
<br>

| Dependency | Purpose | Version | Installation |
|------------|---------|---------|--------------|
| GCC Compiler | Code compilation | 9.0+ | [GCC Website](https://gcc.gnu.org/) |
| Make Utility | Build automation | 3.0+ | [GNU Make](https://www.gnu.org/software/make/) |

</details>

### Installation & Compilation

1️⃣ **Clone the repository**
```bash
git clone <repository_url>
cd Banking-System
```

2️⃣ **Compile the project**
```bash
make
```

> 💡 This compiles source files from `helper/` and `main.c`, placing the executable in `bin/` and object files in `obj/`.

### Running the Application

<details open>
<summary><b>Using the make command</b></summary>
<br>

```bash
make run
```
</details>

<details>
<summary><b>Manually running the executable</b></summary>
<br>

```bash
./bin/banking_system
```
</details>

### Cleaning Build Files

```bash
make clean
```

---

## 💾 Database

The application uses a text file database located at `database/bank_accounts.txt`.

<div align="center">
  <table>
    <tr>
      <th colspan="6">Example Database Format</th>
    </tr>
    <tr>
      <th>Account Number</th>
      <th>Name</th>
      <th>Age</th>
      <th>Gender</th>
      <th>Balance</th>
      <th>Creation Date</th>
    </tr>
    <tr>
      <td align="center">1001</td>
      <td>John Doe</td>
      <td align="center">30</td>
      <td>Male</td>
      <td align="right">5000.00</td>
      <td>2023-10-27</td>
    </tr>
    <tr>
      <td align="center">1002</td>
      <td>Jane Smith</td>
      <td align="center">28</td>
      <td>Female</td>
      <td align="right">7500.50</td>
      <td>2023-10-28</td>
    </tr>
  </table>
</div>

> ⚠️ **Note**: This simple text database lacks features of robust databases like transaction atomicity and concurrency control. It's suitable for this project but not for production environments with sensitive data.

---

## 📝 Usage Guide

<details>
<summary><b>🖱️ Click to Expand Usage Instructions</b></summary>
<br>

### Main Menu

Upon running the application, you'll see this menu:

```
Welcome to the Banking System Application
========================================
Initializing system...

Main Menu:
1. Create Account
2. List All Accounts
3. Delete Account
4. Account Operations (Deposit/Withdraw)
5. Exit
Enter your choice: 
```

### Operations Guide

<table>
  <tr>
    <th width="200">Operation</th>
    <th>Steps</th>
  </tr>
  <tr>
    <td><b>Create an Account</b></td>
    <td>
      <ol>
        <li>Select option <code>1</code> from the main menu</li>
        <li>Enter your name when prompted</li>
        <li>Enter your age (must be a number)</li>
        <li>Enter your gender (Male/Female/Other)</li>
        <li>The system will generate a unique account number</li>
        <li>Initial balance will be set to 0</li>
        <li>Account creation date will be set to current date</li>
      </ol>
    </td>
  </tr>
  <tr>
    <td><b>List All Accounts</b></td>
    <td>
      <ol>
        <li>Select option <code>2</code> from the main menu</li>
        <li>A table will display all accounts with their details</li>
      </ol>
    </td>
  </tr>
  <tr>
    <td><b>Delete an Account</b></td>
    <td>
      <ol>
        <li>Select option <code>3</code> from the main menu</li>
        <li>Enter the account number you wish to delete</li>
        <li>Confirm the deletion when prompted (Y/N)</li>
      </ol>
    </td>
  </tr>
  <tr>
    <td><b>Account Operations</b></td>
    <td>
      <ol>
        <li>Select option <code>4</code> from the main menu</li>
        <li>Enter the account number to operate on</li>
        <li>Choose <code>1</code> for Deposit or <code>2</code> for Withdraw</li>
        <li>Enter the amount for the transaction</li>
        <li>The updated balance will be displayed</li>
      </ol>
    </td>
  </tr>
  <tr>
    <td><b>Exit Application</b></td>
    <td>
      <ol>
        <li>Select option <code>5</code> from the main menu</li>
        <li>Confirm exit when prompted (Y/N)</li>
      </ol>
    </td>
  </tr>
</table>

</details>

---

## 🔧 Implementation Details

<table>
  <tr>
    <td width="180"><b>Account Structure</b></td>
    <td>Defined in <code>include/account.h</code>, includes fields for account number, name, age, gender, balance, and creation date.</td>
  </tr>
  <tr>
    <td><b>File I/O</b></td>
    <td>Standard C library functions (<code>fopen</code>, <code>fprintf</code>, <code>fscanf</code>, <code>fclose</code>) handle database operations.</td>
  </tr>
  <tr>
    <td><b>Error Handling</b></td>
    <td>Basic checks for file operations and user inputs with appropriate error messages.</td>
  </tr>
  <tr>
    <td><b>Modularity</b></td>
    <td>Code is divided into logical modules to promote separation of concerns:</td>
  </tr>
</table>

<details>
<summary><b>Module Organization</b></summary>
<br>

* **Account Module** (`account.h/c`): Handles account data structure and operations
* **Database Module** (`database.h/c`): Manages persistence and file operations
* **Menu Module** (`menu.h/c`): Controls the user interface flow and menu options
* **UI Module** (`ui.h/c`): Provides user interface utilities and formatting

</details>

---

## 🤝 Contributing

We welcome contributions to improve the Banking System project!

### How to Contribute

1. **Fork the repository**  
   <!-- Removed image reference that doesn't exist -->

2. **Create a feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```

3. **Make your changes**

4. **Commit your changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```

5. **Push to the branch**
   ```bash
   git push origin feature/AmazingFeature
   ```

6. **Open a Pull Request**

### Guidelines

- Follow the existing code style
- Add comments to your code where necessary
- Write meaningful commit messages
- Update documentation as needed

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

<div align="center">
  <p>
    <a href="https://github.com/pdevharshthakur/banking-system-c/issues">Report Bug</a> •
    <a href="https://github.com/pdevharshthakur/banking-system-c/issues">Request Feature</a>
  </p>
  
  <p>Happy Banking! 🏦</p>
</div> 