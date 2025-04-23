/**
 * @file account.c
 * @brief Implementation of account operation functions.
 * 
 * This file implements functions for account operations like 
 * deposit, withdrawal, and finding accounts.
 */

#include <stdio.h>
#include "../include/account.h"
#include "../include/ui.h"

int deposit(Account *account) {
    float amount;
    
    printf("\nCurrent balance: $%.2f\n", account->balance);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    clearInputBuffer();
    
    if (amount <= 0) {
        printf("\nInvalid amount. Deposit must be greater than zero.\n");
        return 0;
    }
    
    // Display transaction processing animation
    displayTransactionProcessing("Deposit");
    
    account->balance += amount;
    printf("\nDeposit successful. New balance: $%.2f\n", account->balance);
    return 1;
}

int withdraw(Account *account) {
    float amount;
    
    printf("\nCurrent balance: $%.2f\n", account->balance);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    clearInputBuffer();
    
    if (amount <= 0) {
        printf("\nInvalid amount. Withdrawal must be greater than zero.\n");
        return 0;
    }
    
    if (amount > account->balance) {
        printf("\nInsufficient funds. Withdrawal failed.\n");
        return 0;
    }
    
    // Display transaction processing animation
    displayTransactionProcessing("Withdrawal");
    
    account->balance -= amount;
    printf("\nWithdrawal successful. New balance: $%.2f\n", account->balance);
    return 1;
}

int findAccountIndex(Account accounts[], int count, int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
} 