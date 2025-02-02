
#ifndef LOGIC_H
#define LOGIC_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4
#define MAX_LEN 100

typedef struct
{
    char question[MAX_LEN];
    char options[MAX_OPTIONS][MAX_LEN];
    char correct_option;
} Question;

void print_question(Question q, int question_number);

#endif