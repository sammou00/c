#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 100  // maximum number of tasks
#define MAX_LENGTH 100 // maximum length of each task

/*
simple-todo-list
-----------------
A console-based to-do list application where users can add, view, and delete tasks.

*/

// global variables
char todos[MAX_TASKS][MAX_LENGTH];
int todo_count = 0;

// function prototypes
void print_instructions();
void handle_user_input(int choice);
void add_todo();
void view_todo();
void update_todo();
void delete_todo();
bool do_continue();

int main(void)
{
    do
    {
        print_instructions();
        int choice = get_int("Enter your choice: ");
        handle_user_input(choice);
    } while (do_continue());

    printf("Thank you for using the application.\n");
    return 0;
}

// functions definitions

void print_instructions()
{
    printf("1. Add a new task\n");
    printf("2. View tasks\n");
    printf("3. Update a task\n");
    printf("4. Delete a task\n");
    printf("5. Exit\n");
}

void handle_user_input(int choice)
{
    switch (choice)
    {
    case 1:
        add_todo();
        break;
    case 2:
        view_todo();
        break;
    case 3:
        update_todo();
        break;
    case 4:
        delete_todo();
        break;
    case 5:
        printf("Exiting the program...\n");
        break;
    default:
        printf("Invalid choice.\n");
        break;
    }
}

void add_todo()
{
    // check if todo_count reached the maximum number of tasks
    if (todo_count >= MAX_TASKS)
    {
        printf("You have reached the maximum number of tasks.\n");
        return;
    }

    string new_todo = get_string("Enter a new task: ");

    // copy the new task to the todos array
    strncpy(todos[todo_count], new_todo, MAX_LENGTH - 1);
    todos[todo_count][MAX_LENGTH - 1] = '\0'; // add the null terminator

    todo_count++;

    printf("Task added successfully.\n");
}

void view_todo()
{
    // check if there are no tasks
    if (todo_count == 0)
    {
        printf("No tasks to show.\n");
        return;
    }

    printf("Tasks:\n");
    for (int i = 0; i < todo_count; i++)
    {
        printf("%d. %s\n", i + 1, todos[i]);
    }
}

void update_todo()
{
    // check if there are no tasks
    if (todo_count == 0)
    {
        printf("No tasks to update.\n");
        return;
    }

    int task_number = get_int("Enter the task number to update: ");
    if (task_number < 1 || task_number > todo_count)
    {
        printf("Invalid task number.\n");
        return;
    }

    string new_todo = get_string("Enter the new task: ");

    // copy the new task to the todos array
    strncpy(todos[task_number - 1], new_todo, MAX_LENGTH - 1);
    todos[task_number - 1][MAX_LENGTH - 1] = '\0'; // add the null terminator

    printf("Task updated successfully.\n");
}

void delete_todo()
{
    // check if there are no tasks
    if (todo_count == 0)
    {
        printf("No tasks to delete.\n");
        return;
    }

    int task_number = get_int("Enter the task number to delete: ");
    if (task_number < 1 || task_number > todo_count)
    {
        printf("Invalid task number.\n");
        return;
    }

    // shift the tasks to the left
    for (int i = task_number - 1; i < todo_count - 1; i++)
    {
        strncpy(todos[i], todos[i + 1], MAX_LENGTH - 1);
        todos[i][MAX_LENGTH - 1] = '\0'; // add the null terminator
    }

    todo_count--;

    printf("Task deleted successfully.\n");
}

bool do_continue()
{
    char choice;
    do
    {
        choice = get_char("Do you want to continue? (y/n): ");
        choice = tolower(choice);
    } while (choice != 'y' && choice != 'n');

    return choice == 'y';
}