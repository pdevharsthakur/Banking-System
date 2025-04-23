/**
 * @file ui.c
 * @brief Implementation of UI functions for the banking system.
 * 
 * This file implements functions for displaying information to the user
 * and collecting user input in a consistent format.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include "../include/ui.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMessageAndWait(const char *message) {
    printf("\n%s\n", message);
    printf("Press Enter to continue...");
    getchar();
}

void displayAccountDetails(const Account *account) {
    printf("\n===== Account Details =====\n");
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Age: %d\n", account->age);
    printf("Gender: %c\n", account->gender);
    printf("Balance: $%.2f\n", account->balance);
    printf("Date of Creation: %s\n", account->dateOfCreation);
}

void displayAccountTableHeader() {
    printf("\n%-10s %-20s %-5s %-6s %-10s %-12s\n", "Acc. No.", "Name", "Age", "Gender", "Balance", "Creation Date");
    printf("------------------------------------------------------------------\n");
}

void displayAccountTableRow(const Account *account) {
    printf("%-10d %-20s %-5d %-6c $%-9.2f %s\n", 
        account->accountNumber, 
        account->name, 
        account->age, 
        account->gender, 
        account->balance, 
        account->dateOfCreation);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

void displayTransactionProcessing(const char *operation) {
    const char *loadingStages[] = {
        "Connecting to server       ",
        "Authenticating transaction ",
        "Processing request         ",
        "Updating account balance   ", 
        "Finalizing transaction     "
    };
    
    printf("\n\033[33m=== %s Transaction Processing ===\033[0m\n", operation);
    
    for (int stage = 0; stage < 5; stage++) {
        printf("%s", loadingStages[stage]);
        fflush(stdout);
        
        // Display loading animation dots
        for (int i = 0; i < 3; i++) {
            usleep(300000); // Sleep for 300ms
            printf("\033[32m.\033[0m");
            fflush(stdout);
        }
        
        usleep(200000); // Wait a bit more
        printf(" \033[32m[Done]\033[0m\n");
        fflush(stdout);
    }
    
    printf("\033[32m=== Transaction Completed Successfully ===\033[0m\n\n");
    usleep(500000); // Pause a moment before continuing
} 