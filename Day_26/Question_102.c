#include <stdio.h>

int main() {
    int age;

    
    printf("===========================================\n");
    printf("      VOTING ELIGIBILITY SYSTEM            \n");
    printf("===========================================\n");
    printf("Enter your age: ");
    
   
    if (scanf("%d", &age) != 1) {
        printf("\nError: Invalid character input. Please enter a number.\n");
        return 1; 
    }

    
    if (age < 0) {
        printf("\nStatus: Access Denied!\n");
        printf("Reason: Age cannot be a negative number.\n");
    } 
    else if (age >= 18) {
        printf("\nStatus: Congratulations!\n");
        printf("Reason: You are eligible to cast your vote.\n");
    } 
    else {
        printf("\nStatus: Access Denied!\n");
        printf("Reason: You must be 18 or older to vote.\n");
        printf("Years remaining: %d year(s)\n", 18 - age);
    }

    printf("===========================================\n");
    return 0;
}
