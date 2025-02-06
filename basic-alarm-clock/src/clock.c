#include "clock.h"

void alarm_clock()
{
    int hh, mm, ss;
    printf("Enter the alarm time in HH MM SS format: ");
    scanf("%d %d %d", &hh, &mm, &ss);

    printf("Alarm set for %02d:%02d:%02d\n", hh, mm, ss);

    while (true)
    {
        time_t now;
        struct tm *current;
        now = time(NULL);
        current = localtime(&now);

        if (current->tm_hour == hh && current->tm_min == mm && current->tm_sec == ss)
        {
            printf("\nWake up! It's time! 🔔\a\n");
            break;
        }
        sleep(1); // sleep for 1 second
    }
}
