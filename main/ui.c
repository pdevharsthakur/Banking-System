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