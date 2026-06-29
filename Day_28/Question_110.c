#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100


struct BankAccount {
    int account_number;
    char name[50];
    double balance;
};

int main() {
    
    struct BankAccount accounts[MAX_ACCOUNTS];
    
    
    int total_accounts = 0;
    int next_account_number = 1001;
    int choice = 0;

    
    int search_acc, target_acc;
    int found, i;
    double amount;

    printf("=== WELCOME TO THE BANK MANAGEMENT SYSTEM ===\n");

    // Menu Loop
    while (choice != 6) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input type! Exiting system.\n");
            break;
        }

        
        switch (choice) {
            case 1: // Create New Account
                if (total_accounts >= MAX_ACCOUNTS) {
                    printf("Error: System storage full. Cannot create more accounts.\n");
                } else {
                    accounts[total_accounts].account_number = next_account_number;
                    
                    printf("Enter Account Holder Name (No spaces): ");
                    scanf("%s", accounts[total_accounts].name);
                    
                    printf("Enter Initial Deposit Amount: $");
                    scanf("%lf", &amount);
                    
                    if (amount < 0) {
                        printf("Error: Initial deposit cannot be negative.\n");
                    } else {
                        accounts[total_accounts].balance = amount;
                        printf("\nSuccess! Account created.\n");
                        printf("Account Number: %d\n", accounts[total_accounts].account_number);
                        printf("Holder Name: %s\n", accounts[total_accounts].name);
                        printf("Current Balance: $%.2f\n", accounts[total_accounts].balance);
                        
                        
                        next_account_number++;
                        total_accounts++;
                    }
                }
                break;

            case 2: // Deposit Money
                printf("Enter Account Number: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (i = 0; i < total_accounts; i++) {
                    if (accounts[i].account_number == search_acc) {
                        found = 1;
                        target_acc = i;
                        break;
                    }
                }

                if (found == 1) {
                    printf("Enter Deposit Amount: $");
                    scanf("%lf", &amount);
                    if (amount <= 0) {
                        printf("Error: Deposit amount must be positive.\n");
                    } else {
                        accounts[target_acc].balance += amount;
                        printf("Success! Deposited $%.2f. New Balance: $%.2f\n", amount, accounts[target_acc].balance);
                    }
                } else {
                    printf("Error: Account number %d not found.\n", search_acc);
                }
                break;

            case 3: // Withdraw Money
                printf("Enter Account Number: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (i = 0; i < total_accounts; i++) {
                    if (accounts[i].account_number == search_acc) {
                        found = 1;
                        target_acc = i;
                        break;
                    }
                }

                if (found == 1) {
                    printf("Enter Withdrawal Amount: $");
                    scanf("%lf", &amount);
                    if (amount <= 0) {
                        printf("Error: Withdrawal amount must be positive.\n");
                    } else if (amount > accounts[target_acc].balance) {
                        printf("Error: Insufficient balance. Current balance is $%.2f\n", accounts[target_acc].balance);
                    } else {
                        accounts[target_acc].balance -= amount;
                        printf("Success! Withdrew $%.2f. New Balance: $%.2f\n", amount, accounts[target_acc].balance);
                    }
                } else {
                    printf("Error: Account number %d not found.\n", search_acc);
                }
                break;

            case 4: // Check Balance
                printf("Enter Account Number: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (i = 0; i < total_accounts; i++) {
                    if (accounts[i].account_number == search_acc) {
                        printf("\n--- Account Details ---\n");
                        printf("Account Number: %d\n", accounts[i].account_number);
                        printf("Holder Name: %s\n", accounts[i].name);
                        printf("Current Balance: $%.2f\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: Account number %d not found.\n", search_acc);
                }
                break;

            case 5: // View All Accounts
                if (total_accounts == 0) {
                    printf("No accounts available in the system.\n");
                } else {
                    printf("\n=============================================\n");
                    printf("%-15s %-20s %-10s\n", "Acc Number", "Holder Name", "Balance");
                    printf("---------------------------------------------\n");
                    for (i = 0; i < total_accounts; i++) {
                        printf("%-15d %-20s $%-10.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
                    }
                    printf("=============================================\n");
                }
                break;

            case 6: // Exit
                printf("Thank you for using our Banking System. Goodbye!\n");
                break;

            default:
                printf("Invalid option selected! Please choose between 1 and 6.\n");
        }
    }

    return 0;
}
