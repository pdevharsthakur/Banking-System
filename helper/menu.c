/**
 * @file menu.c
 * @brief Implementation of menu functions for the banking system.
 * 
 * This file implements functions for displaying and handling the main menu
 * and various submenus in the banking system application.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "../include/menu.h"
#include "../include/account.h"
#include "../include/database.h"
#include "../include/ui.h"

void mainMenu() {
    int choice;
    
    while (1) {
        clearScreen();
        printf("\n===== Banking System Menu =====\n");
        printf("1. Create Account\n");
        printf("2. List All Accounts\n");
        printf("3. Delete Account\n");
        printf("4. Operate on Account\n");
        printf("5. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                listAllAccounts();
                break;
            case 3:
                deleteAccount();
                break;
            case 4:
                operateOnAccount();
                break;
            case 5:
                exitApplication();
                break;
            default:
                displayMessageAndWait("Invalid choice. Please try again.");
        }
    }
}

/**
 * @brief Handle the exit process with confirmation
 */
void exitApplication() {
    char choice;
    
    clearScreen();
    printf("\n===== Exit Application =====\n");
    printf("Are you sure you want to exit? (Y/N): ");
    scanf("%c", &choice);
    clearInputBuffer();
    
    if (choice == 'Y' || choice == 'y') {
        clearScreen();
        printf("\n===== Banking System =====\n");
        printf("Thank you for using the banking system.\n");
        printf("All changes have been saved.\n");
        printf("Goodbye!\n\n");
        exit(0);
    }
    
    // If user doesn't confirm exit, show continue message
    printf("\nContinuing with the application...\n");
    printf("Press Enter to return to the main menu.");
    getchar();
}

void createAccount() {
    Account newAccount;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    // Generate a new account number
    newAccount.accountNumber = getLastAccountNumber() + 1;
    
    clearScreen();
    printf("\n===== Create New Account =====\n");
    
    printf("Enter name: ");
    readString(newAccount.name, 50);
    
    printf("Enter age: ");
    scanf("%d", &newAccount.age);
    clearInputBuffer();
    
    printf("Enter gender (M/F): ");
    scanf("%c", &newAccount.gender);
    clearInputBuffer();
    
    // Set initial balance
    newAccount.balance = 0.0;
    
    // Set date of creation
    strftime(newAccount.dateOfCreation, 20, "%Y-%m-%d", tm);
    
    // Save account to file
    if (saveAccount(&newAccount)) {
        printf("\nAccount created successfully!\n");
        displayAccountDetails(&newAccount);
    } else {
        printf("\nError creating account. Please try again.\n");
    }
    
    displayMessageAndWait("Press Enter to return to the main menu.");
}

void listAllAccounts() {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    
    clearScreen();
    
    if (count == 0) {
        displayMessageAndWait("No accounts found.");
    } else {
        printf("\n===== All Accounts (%d) =====\n", count);
        displayAccountTableHeader();
        
        for (int i = 0; i < count; i++) {
            displayAccountTableRow(&accounts[i]);
        }
        
        displayMessageAndWait("Press Enter to return to the main menu.");
    }
}

void deleteAccount() {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    int accountNumber, index;
    
    clearScreen();
    
    if (count == 0) {
        displayMessageAndWait("No accounts found.");
        return;
    }
    
    printf("\n===== Delete Account =====\n");
    displayAccountTableHeader();
    
    for (int i = 0; i < count; i++) {
        displayAccountTableRow(&accounts[i]);
    }
    
    printf("\nEnter account number to delete: ");
    scanf("%d", &accountNumber);
    clearInputBuffer();
    
    index = findAccountIndex(accounts, count, accountNumber);
    
    if (index == -1) {
        displayMessageAndWait("Account not found.");
    } else {
        if (removeAccountFromFile(accountNumber)) {
            char message[100];
            sprintf(message, "Account %d deleted successfully.", accountNumber);
            displayMessageAndWait(message);
        } else {
            displayMessageAndWait("Error deleting account. Please try again.");
        }
    }
}

void operateOnAccount() {
    Account accounts[MAX_ACCOUNTS];
    int count = loadAccounts(accounts);
    int accountNumber, index, choice;
    
    clearScreen();
    
    if (count == 0) {
        displayMessageAndWait("No accounts found.");
        return;
    }
    
    printf("\n===== Operate on Account =====\n");
    displayAccountTableHeader();
    
    for (int i = 0; i < count; i++) {
        displayAccountTableRow(&accounts[i]);
    }
    
    printf("\nEnter account number: ");
    scanf("%d", &accountNumber);
    clearInputBuffer();
    
    index = findAccountIndex(accounts, count, accountNumber);
    
    if (index == -1) {
        displayMessageAndWait("Account not found.");
    } else {
        clearScreen();
        displayAccountDetails(&accounts[index]);
        
        printf("\n===== Account Operations =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View Account Status\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                if (deposit(&accounts[index])) {
                    updateAccountInFile(&accounts[index]);
                }
                break;
            case 2:
                if (withdraw(&accounts[index])) {
                    updateAccountInFile(&accounts[index]);
                }
                break;
            case 3:
                // Display detailed account status with animation
                clearScreen();
                printf("\n\033[33m=== Retrieving Account Status ===\033[0m\n");
                
                // Add a simple loading animation
                printf("Retrieving account data");
                for (int i = 0; i < 3; i++) {
                    usleep(300000); // Sleep for 300ms
                    printf("\033[32m.\033[0m");
                    fflush(stdout);
                }
                printf(" \033[32m[Done]\033[0m\n\n");
                
                // Display detailed account information
                printf("\033[33m===== ACCOUNT STATUS =====\033[0m\n");
                printf("\n\033[1mGeneral Information\033[0m\n");
                printf("%-20s: %d\n", "Account Number", accounts[index].accountNumber);
                printf("%-20s: %s\n", "Account Holder", accounts[index].name);
                printf("%-20s: %d\n", "Age", accounts[index].age);
                printf("%-20s: %c\n", "Gender", accounts[index].gender);
                
                printf("\n\033[1mFinancial Information\033[0m\n");
                printf("%-20s: $%.2f\n", "Current Balance", accounts[index].balance);
                printf("%-20s: %s\n", "Account Created on", accounts[index].dateOfCreation);
                
                printf("\n\033[1mAccount Status\033[0m\n");
                if (accounts[index].balance > 0) {
                    printf("%-20s: \033[32mACTIVE\033[0m\n", "Current Status");
                    printf("%-20s: \033[32mGOOD STANDING\033[0m\n", "Standing");
                } else {
                    printf("%-20s: \033[33mACTIVE\033[0m\n", "Current Status");
                    printf("%-20s: \033[33mZERO BALANCE\033[0m\n", "Standing");
                }
                
                displayMessageAndWait("\nPress Enter to return to the main menu.");
                break;
            case 4:
                return;
            default:
                printf("\nInvalid choice.\n");
        }
        
        displayMessageAndWait("Press Enter to return to the main menu.");
    }
} 