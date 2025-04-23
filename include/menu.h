/**
 * @file menu.h
 * @brief Contains functions for the banking system menu operations.
 * 
 * This file declares functions for displaying and handling the main menu
 * and various submenus in the banking system application.
 */

#ifndef MENU_H
#define MENU_H

/**
 * @brief Display the main menu and handle user choices.
 * @return void
 */
void mainMenu();

/**
 * @brief Handle creating a new account.
 * @return void
 */
void createAccount();

/**
 * @brief Display all accounts in the system.
 * @return void
 */
void listAllAccounts();

/**
 * @brief Handle deleting an existing account.
 * @return void
 */
void deleteAccount();

/**
 * @brief Handle operations on an existing account.
 * @return void
 */
void operateOnAccount();

/**
 * @brief Handle the application exit process with confirmation.
 * @return void
 */
void exitApplication();

#endif /* MENU_H */ 