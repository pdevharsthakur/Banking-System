/**
 * @file database.h
 * @brief Contains functions for database operations in the banking system.
 * 
 * This file declares functions for loading accounts from the database file,
 * saving accounts, updating accounts, and removing accounts from the database.
 */

#ifndef DATABASE_H
#define DATABASE_H

#include "account.h"

#define DATABASE_FILE "database/bank_accounts.txt"
#define MAX_ACCOUNTS 100

/**
 * @brief Get the last account number from the database file.
 * @return The highest account number in the database, or a base number if no accounts exist
 */
int getLastAccountNumber();

/**
 * @brief Load accounts from the database file into an array.
 * @param accounts Array to store the accounts
 * @return Number of accounts loaded
 */
int loadAccounts(Account accounts[]);

/**
 * @brief Save a new account to the database file.
 * @param account Pointer to the Account to save
 * @return 1 if successful, 0 if failed
 */
int saveAccount(Account *account);

/**
 * @brief Update an existing account in the database file.
 * @param account Pointer to the Account with updated information
 * @return 1 if successful, 0 if failed
 */
int updateAccountInFile(Account *account);

/**
 * @brief Remove an account from the database file.
 * @param accountNumber Account number to remove
 * @return 1 if successful, 0 if failed
 */
int removeAccountFromFile(int accountNumber);

#endif /* DATABASE_H */ 