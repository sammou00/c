#include "../include/main.h"

// Display the currency menu
void showMenu(Currency currencies[], int size) {
    printf("\nAvailable currencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s (Rate: %.2f)\n", i + 1, currencies[i].name, currencies[i].rate);
    }
    printf("%d. Exit\n", size + 1);
}

// Get the user's choice and validate it
int getUserChoice(int maxOption) {
    int choice;
    while (true) {
        printf("Enter your choice (1-%d): ", maxOption);
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= maxOption) {
            return choice;
        } else {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n'); // Clear invalid input
        }
    }
}

// Perform currency conversion
double convert_currency(double amount, double rate) {
    return amount * rate;
}

// Ask the user if they want to continue
bool do_continue() {
    char response;
    printf("Do you want to perform another conversion? (y/n): ");
    while (true) {
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y') {
            return true;
        } else if (response == 'n' || response == 'N') {
            return false;
        } else {
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
    }
}
