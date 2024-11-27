#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>

// Struct for currency data
typedef struct Currency
{
    char name[50];
    double rate;
} Currency;

// Function prototypes
void showMenu(Currency currencies[], int size);
int getUserChoice(int maxOption);
double convert_currency(double amount, double rate);
bool do_continue();

#endif
