#include "logic.h"

bool check_palindrome(char *str)
{
    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end)
    {
        // skip non-alphanumeric characters
        while (start < end && !isalnum(str[start]))
        {
            start++;
        }
        while (start < end && !isalnum(str[end]))
        {
            end--;
        }

        // compare characters (case-insensitive)
        if (tolower(str[start]) != tolower(str[end]))
        {
            return false;
        }

        start++;
        end--;
    }
    return true;
}

