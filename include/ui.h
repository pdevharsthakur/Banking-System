/**
 * @file ui.h
 * @brief Contains UI helper functions for the banking system.
 * 
 * This file declares functions for displaying information to the user
 * and collecting user input in a consistent format.
 */

#ifndef UI_H
#define UI_H

#include "account.h"

/**
 * @brief Clear the screen.
 * @return void
 */
void clearScreen();

/**
 * @brief Display a message and wait for the user to press Enter.
 * @param message The message to display
 * @return void
 */
void displayMessageAndWait(const char *message);

/**
 * @brief Display account details in a formatted way.
 * @param account Pointer to the Account to display
 * @return void
 */
void displayAccountDetails(const Account *account);

/**
 * @brief Display a table header for account listings.
 * @return void
 */
void displayAccountTableHeader();

/**
 * @brief Display a single account as a row in the accounts table.
 * @param account The account to display
 * @return void
 */
void displayAccountTableRow(const Account *account);

/**
 * @brief Clear input buffer after scanning.
 * @return void
 */
void clearInputBuffer();

/**
 * @brief Read a string safely without buffer overflow.
 * @param buffer The buffer to store the string
 * @param size The size of the buffer
 * @return void
 */
void readString(char *buffer, int size);

#endif /* UI_H */ 