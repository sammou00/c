#include "logic.h"

void print_question(Question q, int question_number)
{
    printf("Question %d : %s\n", question_number, q.question);

    for (int i = 0; i < MAX_OPTIONS; i++)
    {
        printf("%c) %s\n", 'A' + i, q.options[i]);
    }
}