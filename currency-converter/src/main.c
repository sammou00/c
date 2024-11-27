#include "../include/main.h"

int main()
{
    // Define currency options
    Currency currencies[] = {
        {"EUR (Euro)", 0.94},
        {"GBP (British Pound)", 0.79},
        {"INR (Indian Rupee)", 83.03},
        {"JPY (Japanese Yen)", 149.56},
        {"RUB (Russian Ruble)", 63.74},
        {"BRL (Brazilian Real)", 4.16},
        {"CNY (Chinese Yuan)", 6.92},
        {"KRW (South Korean Won)", 1193.91},
        {"AUD (Australian Dollar)", 1.42},
        {"CAD (Canadian Dollar)", 1.32},
        {"MXN (Mexican Peso)", 18.97},
        {"ZAR (South African Rand)", 14.40},
        {"AED (UAE Dirham)", 3.67},
        {"SAR (Saudi Riyal)", 3.75},
        {"QAR (Qatari Riyal)", 3.64},
        {"KWD (Kuwaiti Dinar)", 0.30},
        {"BHD (Bahraini Dinar)", 0.38},
        {"OMR (Omani Rial)", 0.38},
        {"JOD (Jordanian Dinar)", 0.71},
        {"EGP (Egyptian Pound)", 15.70}};
    int size = sizeof(currencies) / sizeof(currencies[0]);
    int choice;
    double amount, convertedAmount;

    printf("Welcome to the Currency Converter!\n");

    do
    {
        // Show menu and get user choice
        showMenu(currencies, size);
        choice = getUserChoice(size + 1);

        // Handle exit option
        if (choice == size + 1)
        {
            break;
        }

        // Get the amount and validate it
        printf("Enter the amount in USD: ");
        while (scanf("%lf", &amount) != 1 || amount < 0)
        {
            printf("Invalid amount. Please enter a positive number: ");
            while (getchar() != '\n')
                ;
        }

        // Perform conversion and display result
        convertedAmount = convert_currency(amount, currencies[choice - 1].rate);
        printf("\n%.2f USD is equal to %.2f %s.\n", amount, convertedAmount, currencies[choice - 1].name);

    } while (do_continue());

    printf("\nThank you for using the Currency Converter! Goodbye.\n");
    return 0;
}
