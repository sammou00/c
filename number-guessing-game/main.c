#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
void playGame();
int getRandomNumber(int min, int max);
int getUserGuess();
void checkGuess(int guess, int num);
bool playAgain();

int main()
{
    // Seed the random number generator
    srand(time(NULL));
        do
    {
        playGame();
    } while (playAgain());

    printf("Thanks for playing!\n");
    return 0;
}

void playGame()
{
    int num = getRandomNumber(1, 100);
    int guess;
    do
    {
        guess = getUserGuess();
        checkGuess(guess, num);
    } while (guess != num);
}

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int getUserGuess()
{
    int guess;
    do
    {
        guess = get_int("Enter your guess (1-100): ");
        if (guess < 1 || guess > 100)
        {
            printf("Invalid guess. Enter a number between 1 and 100\n");
        }
    } while (guess < 1 || guess > 100);

    return guess;
}

void checkGuess(int guess, int num)
{
    if (guess == num)
    {
        printf("Congratulations! You guessed the number\n");
    }
    else if (guess > num)
    {
        printf("Too high\n");
    }
    else
    {
        printf("Too low\n");
    }
}

bool playAgain()
{
    char response;
    do
    {
        response = tolower(get_char("Do you want to play again? (y/n): "));
        if (response == 'y')
        {
            return true;
        }
        else if (response == 'n')
        {
            return false;
        }
        printf("Invalid response. Enter 'y' to play again or 'n' to quit\n");
    } while (true);
}
