#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>

// Function prototypes
void start();
float getNumber(const char *prompt);
char getOperator();
void calculate(float number1, float number2, char operator);
bool calculateAgain();

int main()
{
    start();
    return 0;
}

void start()
{
    do
    {
        float number1 = getNumber("Enter the first number: ");
        char operator= getOperator();
        float number2 = getNumber("Enter the second number: ");

        calculate(number1, number2, operator);
    } while (calculateAgain());

    printf("Goodbye!...\n");
}

float getNumber(const char *prompt)
{
    float number;
    while (true)
    {
        number = get_float("%s", prompt);
        if (!isnan(number))
        {
            return number;
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

char getOperator()
{
    char operator;
    while (true)
    {
        operator= get_char("Enter an operator (+, -, *, /): ");
        if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        {
            return operator;
        }
        printf("Invalid operator. Please enter one of (+, -, *, /).\n");
    }
}

void calculate(float number1, float number2, char operator)
{
    switch (operator)
    {
    case '+':
        printf("%.2f + %.2f = %.2f\n", number1, number2, number1 + number2);
        break;
    case '-':
        printf("%.2f - %.2f = %.2f\n", number1, number2, number1 - number2);
        break;
    case '*':
        printf("%.2f * %.2f = %.2f\n", number1, number2, number1 * number2);
        break;
    case '/':
        if (number2 == 0)
        {
            printf("Error: Cannot divide by zero.\n");
        }
        else
        {
            printf("%.2f / %.2f = %.2f\n", number1, number2, number1 / number2);
        }
        break;
    default:
        printf("Error: Invalid operator.\n");
        break;
    }
}

bool calculateAgain()
{
    char answer;
    while (true)
    {
        answer = get_char("Do you want to calculate again? (y/n): ");
        if (tolower(answer) == 'y' || tolower(answer) == 'n')
        {
            break;
        }
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }

    return tolower(answer) == 'y';
}
