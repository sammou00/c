#include "main.h"
#include "logic.h"

int main()
{
    Question quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 'A'},
        {"Which programming language is known as 'C with Classes'?", {"Java", "Python", "C++", "Ruby"}, 'C'},
        {"What is 5 + 7?", {"10", "12", "15", "11"}, 'B'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Venus", "Jupiter"}, 'B'},
        {"What is the chemical symbol for water?", {"H2O", "O2", "CO2", "HO2"}, 'A'}};

    int score = 0;
    char user_choice;

    printf("Welcome to the Quiz!\n");
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        print_question(quiz[i], i + 1);

        printf("Enter your choice:(A,B,C or D) :  ");
        scanf(" %c", &user_choice);
        if (toupper(user_choice) == quiz[i].correct_option)
        {
            printf("Correct Answer!\n");
            score++;
        }
        else
        {
            printf("Wrong Answer!, the correct answer is %c\n", quiz[i].correct_option);
        }

        printf("\n");
    }

    printf("Your score is %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}
