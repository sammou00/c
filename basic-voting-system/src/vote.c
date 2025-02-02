#include "vote.h"

// Function definitions
void display_candidates(Candidate *candidates, int num_candidates)
{
    printf("\nList of Candidates:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(Candidate *candidates, int num_candidates)
{
    display_candidates(candidates, num_candidates);
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_candidates)
    {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    printf("You have successfully voted for %s\n", candidates[choice - 1].name);
}

void display_results(Candidate *candidates, int num_candidates)
{
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int max_votes = 0;

    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    printf("\nWinner(s):\n");

    for (int i = 0; i < num_candidates; i++)
    {
        if (candidates[i].votes == max_votes && max_votes > 0)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
