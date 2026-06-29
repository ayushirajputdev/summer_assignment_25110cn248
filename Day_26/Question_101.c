#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, user_guess;
    int attempts = 0;

   
    srand(time(NULL));

    
    secret_number = (rand() % 100) + 1;

    printf("===================================\n");
    printf("   WELCOME TO NUMBER GUESSING GAME   \n");
    printf("===================================\n");
    printf("I have picked a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    
    do {
        printf("Enter your guess: ");
        
       
        if (scanf("%d", &user_guess) != 1) {
            printf("Invalid input! Please enter a valid number.\n\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        attempts++; 
       
        if (user_guess > secret_number) {
            printf("Too high!  Try a lower number.\n\n");
        } 
        else if (user_guess < secret_number) {
            printf("Too low!  Try a higher number.\n\n");
        } 
        else {
            printf("\n CONGRATULATIONS! You found it! \n");
            printf("The secret number was: %d\n", secret_number);
            printf("It took you %d attempts to win.\n", attempts);
        }

    } while (user_guess != secret_number);

    return 0;
}
