#include "main.h"

// display the currency menu
void show_menu(Currency currencies[], int size)
{
    printf("\nAvailable currencies:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d. %s (Rate: %.2f)\n", i + 1, currencies[i].name, currencies[i].rate);
    }
    printf("%d. Exit\n", size + 1);
}

// get the user's choice for the source currency
int get_user_to_choice(int max_option)
{
    int choice = 0;
    while (true)
    {
        printf("Enter your From currency choice (1 to %d): ", max_option);
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= max_option)
        {
            break; // valid input
        }
        printf("Invalid choice. Please try again.\n");
        while (getchar() != '\n')
            ; // clear input buffer
    }
    return choice;
}

// get the user's choice for the source currency
int get_user_from_choice(int max_option)
{
    int choice = 0;
    while (true)
    {
        printf("Enter your To currency choice (1 to %d): ", max_option);
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= max_option)
        {
            break; // valid input
        }
        printf("Invalid choice. Please try again.\n");
        while (getchar() != '\n')
            ; // clear input buffer
    }
    return choice;
}

// perform currency conversion
double convert_currency(double amount, double rate)
{
    return amount * rate;
}

// ask the user if they want to continue
bool do_continue()
{
    char response = '\0';
    while (true)
    {
        printf("Do you want to convert another currency? (y/n): ");
        if (scanf(" %c", &response) == 1)
        {
            response = tolower(response);
            if (response == 'y' || response == 'n')
            {
                return response == 'y';
            }
        }
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }
}
