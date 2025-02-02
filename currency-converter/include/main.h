#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <json-c/json.h>

// Currency node structure
typedef struct CurrencyNode
{
    char *name;
    double rate;
    struct CurrencyNode *next;
} CurrencyNode;

// Function prototypes

/**
 * @brief Create a node object
 *
 * @param name  The name of the currency
 * @param rate  The exchange rate of the currency
 * @return CurrencyNode*
 */
CurrencyNode *create_node(char *name, double rate);

/**
 * @brief Add a currency object to the linked list
 *
 * @param head  The head of the linked list
 * @param name  The name of the currency
 * @param rate  The exchange rate of the currency
 */
void add_currency(CurrencyNode **head, char *name, double rate);

/**
 * @brief Display the menu
 *
 * @param head  The head of the linked list
 */
void show_menu(CurrencyNode *head);

/**
 * @brief Get the user's choice
 *
 * @param max_option  The maximum option
 * @return int
 */
int get_user_from_choice(int max_option);

/**
 * @brief Get the user's choice
 *
 * @param max_option  The maximum option
 * @return int
 */

int get_user_to_choice(int max_option);

/**
 * @brief  Get the amount to convert
 *
 * @param amount
 * @param rate
 * @return double
 */
double convert_currency(double amount, double rate);

/**
 * @brief Free the linked list
 *
 * @param head  The head of the linked list
 */

void free_list(CurrencyNode *head);

/**
 * @brief Check if the user wants to continue
 *
 * @return true
 * @return false
 */
bool do_continue(void);

/**
 * @brief Fetch the exchange rates
 *
 * @param head  The head of the linked list
 */
void fetch_exchange_rates(CurrencyNode **head);

/**
 * @brief Write the data to the buffer
 *
 * @param contents  The data to write
 * @param size  The size of the data
 * @param nmemb  The number of members
 * @param buffer  The buffer to write to
 * @return size_t
 */
size_t write_callback(void *contents, size_t size, size_t nmemb, char *buffer);

#endif
