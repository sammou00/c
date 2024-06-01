#include <stdio.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();

int main()
{
    int choice;

    while (1)
    {
        // Displaying the menu
        printf("\nSimple Calculator\n");
        printf("-------------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Performing the chosen operation
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            printf("Exiting...\n");
            printf("Thank you for using the calculator.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function definitions

void add()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 + num2;
    printf("Result: %.2f\n", result);
}

void subtract()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 - num2;
    printf("Result: %.2f\n", result);
}

void multiply()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    result = num1 * num2;
    printf("Result: %.2f\n", result);
}

void divide()
{
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    if (num2 != 0)
    {
        result = num1 / num2;
        printf("Result: %.2f\n", result);
    }
    else
    {
        printf("Error: Division by zero is not allowed.\n");
        return;
    }
}
