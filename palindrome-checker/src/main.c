#include "main.h"
#include "logic.h"

int main()
{
    char input[200];

    printf("Enter a string or number to check if it is a palindrome: ");
    fgets(input, sizeof(input), stdin);

    // remove the newline character if present
    int len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }

    if (check_palindrome(input))
    {
        printf("\"%s\" is a palindrome.\n", input);
    }
    else
    {
        printf("\"%s\" is not a palindrome.\n", input);
    }

    return 0;
}
