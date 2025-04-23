/**
 * @file account.h
 * @brief Contains the Account structure definition and account operation functions.
 * 
 * This file defines the Account structure that represents bank accounts in the system
 * and declares functions for account operations like deposit and withdrawal.
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

/**
 * @struct Account
 * @brief Represents a bank account with personal details and balance information.
 */
typedef struct {
    int accountNumber;
    char name[50];
    int age;
    char gender;
    float balance;
    char dateOfCreation[20];
} Account;

/**
 * @brief Deposit money into an account.
 * @param account Pointer to the Account to deposit into
 * @return 1 if successful, 0 if failed
 */
int deposit(Account *account);

/**
 * @brief Withdraw money from an account.
 * @param account Pointer to the Account to withdraw from
 * @return 1 if successful, 0 if failed
 */
int withdraw(Account *account);

/**
 * @brief Find the index of an account in an array by account number.
 * @param accounts Array of accounts to search
 * @param count Number of accounts in the array
 * @param accountNumber Account number to find
 * @return Index of the account if found, -1 otherwise
 */
int findAccountIndex(Account accounts[], int count, int accountNumber);

#endif /* ACCOUNT_H */ 