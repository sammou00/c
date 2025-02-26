#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

// function prototypes
void start();
float getNumber();
char getOperator();
float calculate(float num1, char operator, float num2);
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
        float num1 = getNumber();
        char operator= getOperator();
        float num2 = getNumber();
        float result = calculate(num1, operator, num2);
        printf("Result is: %.2f\n", result);
    } while (calculateAgain());

    printf("Thank you for using a calculator.\n");
}

float getNumber()
{
    float num;
    while (true)
    {
        num = get_float("Enter a number: ");
        if (!isnan(num))
        {
            break;
        }
        printf("Invalid input. Please enter a valid number.\n");
    }

    return num;
}

char getOperator()
{
    char operator;
    while (true)
    {
        operator= get_char("Enter an operator (+, -, *, /): ");
        if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        {
            break;
        }
        printf("Invalid operator. Please enter one of +, -, *, /.\n");
    }

    return operator;
}

float calculate(float num1, char operator, float num2)
{
    switch (operator)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            printf("Cannot divide by zero\n");
            return 0;
        }
        return num1 / num2;
    default:
        printf("Invalid operator\n");
        return 0;
    }
}

bool calculateAgain()
{
    char choice;
    while (true)
    {
        choice = get_char("Do you want to calculate again? (y/n): ");
        choice = tolower(choice);
        if (choice == 'y' || choice == 'n')
        {
            break;
        }
        printf("Invalid input. Please enter 'y' for yes or 'n' for no.\n");
    }

    return choice == 'y';
}
