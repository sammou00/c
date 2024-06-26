#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cs50.h>

// Function prototypes
void playGame();
int getUserChoice();
int getComputerChoice();
void determineWinner(int userChoice, int computerChoice);
bool askToPlayAgain();

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
    } while (askToPlayAgain());

    printf("Thank you for playing!\n");
}

int getUserChoice()
{
    int choice;

    printf("Please enter your choice:\n1. Rock\n2. Paper\n3. Scissors\nChoice: ");
    while (true)
    {
        choice = get_int("");
        if (choice >= 1 && choice <= 3)
        {
            break;
        }
        printf("Invalid choice. Please enter 1, 2, or 3: ");
    }

    return choice;
}

int getComputerChoice()
{
    return rand() % 3 + 1;
}

void determineWinner(int userChoice, int computerChoice)
{
    const string choices[] = {"Rock", "Paper", "Scissors"};

    printf("You chose      : %s\n", choices[userChoice - 1]);
    printf("Computer chose : %s\n", choices[computerChoice - 1]);

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
        printf("You lose!\n");
    }
}

bool askToPlayAgain()
{
    char response;
    printf("Do you want to play again? (y/n): ");
    while (true)
    {
        response = get_char("");
        if (response == 'y' || response == 'Y')
        {
            return true;
        }
        else if (response == 'n' || response == 'N')
        {
            return false;
        }
        printf("Invalid response. Please enter 'y' or 'n': ");
    }
}
