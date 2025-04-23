/**
 * @file database.c
 * @brief Implementation of database operations for the banking system.
 * 
 * This file implements functions for loading accounts from the database file,
 * saving accounts, updating accounts, and removing accounts from the database.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/database.h"

int getLastAccountNumber() {
    FILE *file = fopen(DATABASE_FILE, "r");
    int lastAccountNumber = 1000; // Start account numbers from 1001
    
    if (file == NULL) {
        return lastAccountNumber;
    }
    
    Account account;
    while (fscanf(file, "%d,%[^,],%d,%c,%f,%[^\n]\n", 
            &account.accountNumber, 
            account.name, 
            &account.age, 
            &account.gender, 
            &account.balance, 
            account.dateOfCreation) == 6) {
        if (account.accountNumber > lastAccountNumber) {
            lastAccountNumber = account.accountNumber;
        }
    }
    
    fclose(file);
    return lastAccountNumber;
}

int loadAccounts(Account accounts[]) {
    FILE *file = fopen(DATABASE_FILE, "r");
    int count = 0;
    
    if (file == NULL) {
        return 0;
    }
    
    while (count < MAX_ACCOUNTS && 
          fscanf(file, "%d,%[^,],%d,%c,%f,%[^\n]\n", 
                &accounts[count].accountNumber, 
                accounts[count].name, 
                &accounts[count].age, 
                &accounts[count].gender, 
                &accounts[count].balance, 
                accounts[count].dateOfCreation) == 6) {
        count++;
    }
    
    fclose(file);
    return count;
}

int saveAccount(Account *account) {
    FILE *file = fopen(DATABASE_FILE, "a");
    
    if (file == NULL) {
        printf("Error opening database file.\n");
        return 0;
    }
    
    fprintf(file, "%d,%s,%d,%c,%.2f,%s\n", 
            account->accountNumber, 
            account->name, 
            account->age, 
            account->gender, 
            account->balance, 
            account->dateOfCreation);
    
    fclose(file);
    return 1;
}

int updateAccountInFile(Account *account) {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    FILE *file = fopen(DATABASE_FILE, "w");
    
    if (file == NULL) {
        printf("Error opening database file.\n");
        return 0;
    }
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == account->accountNumber) {
            fprintf(file, "%d,%s,%d,%c,%.2f,%s\n", 
                account->accountNumber, 
                account->name, 
                account->age, 
                account->gender, 
                account->balance, 
                account->dateOfCreation);
        } else {
            fprintf(file, "%d,%s,%d,%c,%.2f,%s\n", 
                accounts[i].accountNumber, 
                accounts[i].name, 
                accounts[i].age, 
                accounts[i].gender, 
                accounts[i].balance, 
                accounts[i].dateOfCreation);
        }
    }
    
    fclose(file);
    return 1;
}

int removeAccountFromFile(int accountNumber) {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    FILE *file = fopen(DATABASE_FILE, "w");
    int removed = 0;
    
    if (file == NULL) {
        printf("Error opening database file.\n");
        return 0;
    }
    
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber != accountNumber) {
            fprintf(file, "%d,%s,%d,%c,%.2f,%s\n", 
                accounts[i].accountNumber, 
                accounts[i].name, 
                accounts[i].age, 
                accounts[i].gender, 
                accounts[i].balance, 
                accounts[i].dateOfCreation);
        } else {
            removed = 1;
        }
    }
    
    fclose(file);
    return removed;
} 