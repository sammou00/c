#include "clock.h"

int main()
{
    char input = '\0';
    clock_t start_time = 0;
    clock_t stop_time = 0;
    double elapsed_time = 0.0;
    bool running = false;
    printf("Simple Console Stopwatch\n");

    // display instructions
    display_instructions();

    while (true)
    {

        // get user input
        scanf(" %c", &input);

        if (input == 'q')
        {
            printf("Goodbye!\n");
            break;
        }
        else if (input == 's' && !running)
        {
            start_time = time(NULL);
            running = true;
            printf("Stopwatch started.\n");
        }
        else if (input == 't' && running)
        {
            stop_time = time(NULL);
            running = false;
            elapsed_time = difftime(stop_time, start_time);
            printf("Stopwatch stopped. Elapsed time: %.2f seconds\n", elapsed_time);
        }
        else if (input == 'r')
        {
            start_time = 0;
            stop_time = 0;
            running = false;
            printf("Stopwatch reset.\n");
        }
        else if (input == 'h')
        {
            display_instructions();
        }
        else
        {
            printf("Invalid input. Press 'h' for help.\n");
        }
    }

    return 0;
}