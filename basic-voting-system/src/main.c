#include "main.h"
#include "vote.h"

int main()
{
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate memory for the candidates
    Candidate *candidates = (Candidate *)malloc(num_candidates * sizeof(Candidate));
    if (candidates == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // allocate memory for the candidate names
    for (int i = 0; i < num_candidates; i++)
    {
        candidates[i].name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        if (candidates[i].name == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    for (int i = 0; i < num_candidates; i++)
    {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    int choice;

    do
    {
        printf("\n1. Display candidates\n2. Vote\n3. Display results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_candidates(candidates, num_candidates);
            break;
        case 2:
            vote(candidates, num_candidates);
            break;
        case 3:
            display_results(candidates, num_candidates);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the candidate names
    for (int i = 0; i < num_candidates; i++)
    {
        free(candidates[i].name);
    }

    // Free the memory allocated for the candidates
    free(candidates);

    return 0;
}
