#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// maximum length for currency names (if dynamic allocation fails)
#define MAX_NAME_LENGTH 50

// struct for currency data
typedef struct
{
    char *name;
    double rate;
} Currency;

// Function prototypes

/**
 * displays the menu of available currencies to the user.
 * @param currencies Array of Currency structures.
 * @param size Number of currencies in the array.
 */
void show_menu(Currency currencies[], int size);

/**
 * prompts the user to select a source currency.
 * @param max_option The maximum number of options available.
 * @return The selected option index (0-based).
 */
int get_user_from_choice(int max_option);

/**
 * prompts the user to select a target currency.
 * @param max_option The maximum number of options available.
 * @return The selected option index (0-based).
 */
int get_user_to_choice(int max_option);

/**
 * converts an amount from one currency to another based on the exchange rate.
 * @param amount The amount to be converted.
 * @param rate The exchange rate for the conversion.
 * @return The converted amount.
 */
double convert_currency(double amount, double rate);

/**
 * asks the user if they want to perform another conversion.
 * @return true if the user wants to continue, false otherwise.
 */
bool do_continue();

#endif // MAIN_H
