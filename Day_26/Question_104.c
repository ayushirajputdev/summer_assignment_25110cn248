#include <stdio.h>
#include <ctype.h>

// Structure to store quiz data
struct QuizQuestion {
    char question[150];
    char options[4][50];
    char correctOption;
};

int main() {
    
    struct QuizQuestion quiz[] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Java", "B. Python", "C. C Language", "D. C++"},
            'C'
        },
        {
            "What is the size of an 'int' data type in C (usually on 32/64 bit systems)?",
            {"A. 1 Byte", "B. 2 Bytes", "C. 4 Bytes", "D. 8 Bytes"},
            'C'
        },
        {
            "Which keyword is used to prevent any changes to a variable in C?",
            {"A. static", "B. const", "C. volatile", "D. immutable"},
            'B'
        },
        {
            "Which of the following is correct format specifier for double value?",
            {"A. %f", "B. %lf", "C. %d", "D. %s"},
            'B'
        }
    };

    
    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    char userGuess;

    printf("=========================================\n");
    printf("        WELCOME TO THE C QUIZ GAME       \n");
    printf("=========================================\n\n");

    
    for (int i = 0; i < totalQuestions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        
       
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        
        printf("Enter your choice (A, B, C, or D): ");
        
        
        scanf(" %c", &userGuess);

        
        userGuess = toupper(userGuess);

        
        if (userGuess == quiz[i].correctOption) {
            printf("✔ Correct Answer!\n\n");
            score++;
        } else {
            printf("❌ Wrong! The correct answer was %c.\n\n", quiz[i].correctOption);
        }
        printf("-----------------------------------------\n");
    }

    printf("\n=========================================\n");
    printf("                GAME OVER                \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, totalQuestions);
    
    
    float percentage = ((float)score / totalQuestions) * 100;
    printf("Accuracy: %.2f%%\n", percentage);
    printf("=========================================\n");

    return 0;
}
