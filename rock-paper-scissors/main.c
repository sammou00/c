#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
int getPlayerChoice();
int getComputerChoice();
void displayChoice(int choice);
void determineWinner(int playerChoice, int computerChoice);

// Main function
int main()
{
    // Seed the random number generator with the current time
    // to make sure the random numbers are different each time
    srand(time(0));

    char playAgain;

    do
    {
        // display the game menu
        displayMenu();

        // Get the player's choice and the computer's choice
        int playerChoice, computerChoice;

        playerChoice = getPlayerChoice();
        computerChoice = getComputerChoice();

        // display the player's choice
        printf("Your choice: ");
        displayChoice(playerChoice);
        determineWinner(playerChoice, computerChoice);

        // Prompt user to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        return 0;
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing!\n");
    return 0;
}

// Function definitions
// Display the game menu
void displayMenu()
{
    printf("Rock, Paper, Scissors Game\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Choose your move: ");
}

// Get player's choice
int getPlayerChoice()
{
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Get computer's choice
int getComputerChoice()
{
    return (rand() % 3) + 1;
}

// Display the player's or computer's choice
void displayChoice(int choice)
{
    switch (choice)
    {
    case 1:
        printf("Rock\n");
        break;
    case 2:
        printf("Paper\n");
        break;
    case 3:
        printf("Scissors\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

// Determine the winner of the game
void determineWinner(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
    {
        printf("It's a tie!\n");
    }
    else if ((playerChoice == 1 && computerChoice == 3) ||
             (playerChoice == 2 && computerChoice == 1) ||
             (playerChoice == 3 && computerChoice == 2))
    {
        printf("You win!\n");
    }
    else
    {
        printf("Computer wins!\n");
    }
}