#include <stdio.h>

int main() {
    // Array sizes and constraints
    #define MAX_STUDENTS 50
    #define MAX_NAME_LEN 30

    // Storage arrays
    char studentNames[MAX_STUDENTS][MAX_NAME_LEN];
    int studentRolls[MAX_STUDENTS];
    float studentMarks[MAX_STUDENTS];
    
    // Tracking variables
    int totalStudents = 0;
    int choice;
    
    // Loop control & matching variables
    int searchRoll;
    int found;
    int i, j; 

    // Temporary variables for sorting strings and numbers
    char tempName[MAX_NAME_LEN];
    int tempRoll;
    float tempMark;

    printf("=== Student Report Card Management System ===\n");

    // Main program loop replacing separate menu functions
    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Sort Students by Marks (Highest First)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Option 1: Add New Student
        if (choice == 1) {
            if (totalStudents >= MAX_STUDENTS) {
                printf("\nError: System storage is full!\n");
            } else {
                printf("\nEnter Roll Number: ");
                scanf("%d", &studentRolls[totalStudents]);
                
                printf("Enter Student Name (No spaces): ");
                scanf("%s", studentNames[totalStudents]);
                
                printf("Enter Marks Obtained (0-100): ");
                scanf("%f", &studentMarks[totalStudents]);

                totalStudents++;
                printf("\nStudent record added successfully!\n");
            }
        } 
        
        // Option 2: Display All Students
        else if (choice == 2) {
            if (totalStudents == 0) {
                printf("\nNo records available to display.\n");
            } else {
                printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
                printf("-----------------------------------------\n");
                for (i = 0; i < totalStudents; i++) {
                    printf("%-10d %-20s %-10.2f\n", studentRolls[i], studentNames[i], studentMarks[i]);
                }
            }
        } 
        
        // Option 3: Search Student by Roll Number
        else if (choice == 3) {
            if (totalStudents == 0) {
                printf("\nNo records available to search.\n");
            } else {
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);
                
                found = 0;
                for (i = 0; i < totalStudents; i++) {
                    if (studentRolls[i] == searchRoll) {
                        printf("\nRecord Found!");
                        printf("\nRoll Number: %d", studentRolls[i]);
                        printf("\nName       : %s", studentNames[i]);
                        printf("\nMarks      : %.2f\n", studentMarks[i]);
                        found = 1;
                        break; // Exit search loop early
                    }
                }
                if (!found) {
                    printf("\nStudent with Roll Number %d not found.\n", searchRoll);
                }
            }
        } 
        
        // Option 4: Sort Students by Marks (Bubble Sort)
        else if (choice == 4) {
            if (totalStudents < 2) {
                printf("\nNot enough records to perform sorting.\n");
            } else {
                // Inline Bubble Sort logic
                for (i = 0; i < totalStudents - 1; i++) {
                    for (j = 0; j < totalStudents - i - 1; j++) {
                        if (studentMarks[j] < studentMarks[j + 1]) {
                            
                            // Swap Marks
                            tempMark = studentMarks[j];
                            studentMarks[j] = studentMarks[j + 1];
                            studentMarks[j + 1] = tempMark;

                            // Swap Roll Numbers
                            tempRoll = studentRolls[j];
                            studentRolls[j] = studentRolls[j + 1];
                            studentRolls[j + 1] = tempRoll;

                            // Swap Names (Manual character-by-character array swap)
                            int k = 0;
                            while (studentNames[j][k] != '\0' || tempName[k] != '\0') {
                                tempName[k] = studentNames[j][k];
                                k++;
                            }
                            tempName[k] = '\0';

                            k = 0;
                            while (studentNames[j + 1][k] != '\0') {
                                studentNames[j][k] = studentNames[j + 1][k];
                                k++;
                            }
                            studentNames[j][k] = '\0';

                            k = 0;
                            while (tempName[k] != '\0') {
                                studentNames[j + 1][k] = tempName[k];
                                k++;
                            }
                            studentNames[j + 1][k] = '\0';
                        }
                    }
                }
                printf("\nStudents sorted by marks successfully! (Select Option 2 to view)\n");
            }
        } 
        
        // Option 5: Exit Program
        else if (choice == 5) {
            printf("\nExiting program. Goodbye!\n");
            break;
        } 
        
        // Fallback for invalid input
        else {
            printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }
    }

    return 0;
}
