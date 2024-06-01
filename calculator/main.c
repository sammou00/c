#include <stdio.h>

// Function prototypes

void add();
void subtraction();
void multiplication();
void division();

// Main function
int main()
{
    int choice;
    while (1)
    {
        printf("Simple Calculator\n");
        printf("-----------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit...\n");
        printf("-----------------\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            printf("Exiting...\n");
            printf("Thank you for using the calculator\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function definitions
void add()
{
    float num1, num2, result;
    printf("Enter two numbers : ");
    scanf("%f %f", &num1, &num2);
    result = num1 + num2;
    printf("Addition of : %.2f and %.2f  numbers is : %.2f\n", num1, num2, result);
}

void subtraction()
{
    float num1, num2, result;
    printf("Enter two numbers : ");
    scanf("%f %f", &num1, &num2);
    result = num1 - num2;
    printf("Subtraction of :  %.2f from %.2f numbers is : %.2f\n", num1, num2, result);
}

void multiplication()
{
    float num1, num2, result;
    printf("Enter two numbers : ");
    scanf("%f %f", &num1, &num2);
    result = num1 * num2;
    printf("Multiplication of :  %.2f and %.2f numbers is : %.2f\n", num1, num2, result);
}

void division()
{
    float num1, num2, result;
    printf("Enter two numbers : ");
    scanf("%f %f", &num1, &num2);

    if (num2 == 0)
    {
        printf("Division by zero is not possible\n");
        return;
    }
    else
    {
        result = num1 / num2;
        printf("Division of of :  %.2f by %.2f numbers is : %.2f\n", num1, num2, result);
    }
}