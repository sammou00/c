#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <cs50.h>

// Function prototypes
void playGame();
int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int computerChoice);
bool playAgain();

int main()
{
    srand(time(NULL));
    playGame();
    return 0;
}

void playGame()
{
    do
    {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();
        determineWinner(userChoice, computerChoice);
    } while (playAgain());

    printf("Thanks for playing!\n");
}

int getUserChoice()
{
    int choice = 0;
    while (choice < 1 || choice > 3)
    {
        printf("Enter your choice: \n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        choice = get_int("-------------\n");

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice, please try again.\n");
        }
    }

    return choice;
}

int getComputerChoice()
{
    return rand() % 3 + 1;
}

void determineWinner(int userChoice, int computerChoice)
{
    const char *choices[] = {"Rock", "Paper", "Scissors"};
    printf("You chose      : %s\nComputer chose : %s\n", choices[userChoice - 1], choices[computerChoice - 1]);

    if (userChoice == computerChoice)
    {
        printf("It's a tie!\n");
    }
    else if ((userChoice == 1 && computerChoice == 3) ||
             (userChoice == 2 && computerChoice == 1) ||
             (userChoice == 3 && computerChoice == 2))
    {
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }
}

bool playAgain()
{
    char replay;
    do
    {
        replay = get_char("\nDo you want to play again? (y/n)\n");
        replay = tolower(replay);

        if (replay != 'y' && replay != 'n')
        {
            printf("Invalid input, please enter 'y' or 'n'.\n");
        }
    } while (replay != 'y' && replay != 'n');

    return replay == 'y';
}
