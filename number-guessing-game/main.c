#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h>

// Function prototypes
int getRandNum(int min, int max);
int getUserGuess(int min, int max);
void checkGuess(int guess, int num);

int main(void)
{
    // Seed the random number generator
    srand(time(0));

    while (1)
    {

        int randomNumber = getRandNum(1, 100);
        int guess;

        do
        {
            guess = getUserGuess(1, 100);
            checkGuess(guess, randomNumber);
        } while (guess != randomNumber);

        char playAgain = get_char("Do you want to play again? (y/n): ");

        if (playAgain == 'n' || playAgain == 'N')
        {
            break;
        }
    }

    return 0;
}

int getRandNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int getUserGuess(int min, int max)
{
    int guess;
    while (1)
    {
        guess = get_int("Enter a number between %d and %d: ", min, max);
        if (guess >= min && guess <= max)
        {
            return guess;
        }
        else
        {
            printf("Invalid input! Please enter a number between %d and %d.\n", min, max);
        }
    }
}

void checkGuess(int guess, int num)
{
    if (guess == num)
    {
        printf("Congratulations! You guessed the number!\n");
    }
    else if (guess < num)
    {
        printf("Too low! Try again.\n");
    }
    else
    {
        printf("Too high! Try again.\n");
    }
}
