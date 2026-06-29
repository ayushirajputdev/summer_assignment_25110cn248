#include <stdio.h>

int main() {
    
    int pin = 1234;         
    int enteredPin;          
    int pinAttempts = 0;    
    double balance = 5000.0;
    int choice;              
    double amount;          
    int running = 1;        

    
    while (pinAttempts < 3) {
        printf("--- Welcome to the ATM Service ---\n");
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("\nPIN Verified Successfully!\n\n");
            break; 
        } else {
            pinAttempts++;
            printf("Incorrect PIN. Remaining attempts: %d\n\n", 3 - pinAttempts);
        }
    }

   
    if (pinAttempts == 3) {
        printf("Your card has been blocked due to 3 incorrect PIN entries.\n");
        printf("Please contact your branch manager.\n");
        return 0; // Terminate execution
    }

   
    while (running) {
        printf("===================================\n");
        printf("            ATM MENU               \n");
        printf("===================================\n");
        printf("1. Check Balance\n");
        printf("2. Cash Withdrawal\n");
        printf("3. Cash Deposit\n");
        printf("4. Exit ATM\n");
        printf("===================================\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("\nYour current available balance is: $%.2f\n\n", balance);
                break;

            case 2:
              
                printf("\nEnter the amount to withdraw: $");
                scanf("%lf", &amount);

                if (amount <= 0) {
                    printf("Invalid entry. Amount must be greater than zero.\n\n");
                } else if (amount > balance) {
                    printf("Transaction failed. Insufficient funds!\n\n");
                } else {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                    printf("Updated balance: $%.2f\n\n", balance);
                }
                break;

            case 3:
                
                printf("\nEnter the amount to deposit: $");
                scanf("%lf", &amount);

                if (amount <= 0) {
                    printf("Invalid entry. Amount must be greater than zero.\n\n");
                } else {
                    balance += amount;
                    printf("Cash deposited successfully.\n");
                    printf("Updated balance: $%.2f\n\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM services. bye! bye!\n");
                running = 0; // Flags loop to terminate
                break;

            default:
                
                printf("\nInvalid selection! Please pick a valid option from the menu.\n\n");
                break;
        }
    }

    return 0;
}
