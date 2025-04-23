/**
 * @file main.c
 * @brief Entry point for the Banking System Application.
 * 
 * This file contains the main function which initializes the banking system
 * and starts the main menu. It creates the database file if it doesn't exist
 * and handles any startup operations.
 * 
 * Features:
 * - Create account
 * - List all accounts
 * - Delete account
 * - Operate on account (deposit/withdraw)
 * - Text file based database for persistence
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/menu.h"
#include "include/database.h"

/**
 * @brief Main function - entry point of the application.
 * @return 0 on successful execution, 1 on failure
 */
int main() {
    // Create database file if it doesn't exist
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        printf("Error: Unable to create or access the database file.\n");
        return 1;
    }
    fclose(file);
    
    printf("Welcome to the Banking System Application\n");
    printf("========================================\n");
    printf("Initializing system...\n");
    
    // Start the main menu
    mainMenu();
    
    return 0;
} 