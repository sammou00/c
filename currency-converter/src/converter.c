#include "main.h"

CurrencyNode *create_node(char *name, double rate)
{
    CurrencyNode *node = (CurrencyNode *)malloc(sizeof(CurrencyNode));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
    }
    // allocate memory for the name
    node->name = (char *)malloc(strlen(name) + 1);
    if (node->name == NULL)
    {
        printf("Memory allocation failed\n");
    }
    strcpy(node->name, name);
    node->rate = rate;
    node->next = NULL;

    return node;
}

void add_currency(CurrencyNode **head, char *name, double rate)
{
    CurrencyNode *new_node = create_node(name, rate);

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        CurrencyNode *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void show_menu(CurrencyNode *head)
{
    int index = 1;
    CurrencyNode *current = head;
    printf("\nAvailable currencies:\n");
    while (current != NULL)
    {
        printf("%d. %s\n", index, current->name);
        current = current->next;
        index++;
    }
    printf("%d. Exit\n", index);
}

int get_user_from_choice(int max_option)
{
    int choice;
    printf("Enter the currency you want to convert from: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > max_option)
    {
        printf("Invalid choice. Please try again: ");
        scanf("%d", &choice);
    }
    return choice;
}

int get_user_to_choice(int max_option)
{
    int choice;
    printf("Enter the currency you want to convert to: ");
    scanf("%d", &choice);
    while (choice < 1 || choice > max_option)
    {
        printf("Invalid choice. Please try again: ");
        scanf("%d", &choice);
    }
    return choice;
}

double convert_currency(double amount, double rate)
{
    return amount * rate;
}

void free_list(CurrencyNode *head)
{
    CurrencyNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp);
    }
}

bool do_continue(void)
{
    char choice;
    printf("Do you want to convert another currency? (y/n): ");
    scanf(" %c", &choice);

    choice = tolower(choice);
    while (choice != 'y' && choice != 'n')
    {
        printf("Invalid choice. Please try again: ");
        scanf(" %c", &choice);
    }
    return choice == 'y';
}