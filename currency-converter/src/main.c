#include "main.h"

int main()
{
    // define currency options
    Currency currencies[] = {
        {"USD (US Dollar)", 1.00},
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
        {"Gor (Georgian Lari)", 3.30},
        {"EGP (Egyptian Pound)", 15.70}};
    int size = sizeof(currencies) / sizeof(currencies[0]);
    int choice_from = 0;
    int choice_to = 0;
    double amount = 0, convertedAmount = 0;

    // allocate memory for currency names

    printf("Welcome to the Currency Converter!\n");

    do
    {
        // show menu and get user choice_from and choice_to
        Currency *currencies_copy = show_menu(currencies, size);
        choice_from = get_user_to_choice(size + 1);
        choice_to = get_user_from_choice(size + 1);

        // handle exit option
        if (choice_from == size + 1 || choice_to == size + 1)
        {
            // free allocated memory
            for (int i = 0; i < size; i++)
            {
                free(currencies_copy[i].name);
            }

            break;
        }

        // get the amount and validate it
        do
        {
            printf("Enter the amount : ");
            scanf("%lf", &amount);
            if (amount <= 0)
            {
                printf("Invalid amount. Please enter a positive number.\n");
            }
        } while (amount <= 0);

        // convert from source to target currency
        double rate = currencies[choice_to - 1].rate / currencies[choice_from - 1].rate;
        convertedAmount = convert_currency(amount, rate);

        // display the result
        printf("%.2f  %s is  %.2f  %s\n", amount, currencies[choice_from - 1].name, convertedAmount, currencies[choice_to - 1].name);

        // free allocated memory
        for (int i = 0; i < size; i++)
        {
            free(currencies_copy[i].name);
        }

    } while (do_continue());

    printf("Thank you for using the Currency Converter!\n");

    return 0;
}
