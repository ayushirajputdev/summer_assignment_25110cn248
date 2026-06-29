#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

int main() {
    // Parallel arrays acting as the database fields
    int rollNumbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_LENGTH];
    float marks[MAX_STUDENTS];
    
    int studentCount = 0;
    int choice;
    
    // Control variables for operations
    int searchRoll;
    int found;
    
    while (1) {
        // Display System Menu
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                // Check for system storage bounds
                if (studentCount >= MAX_STUDENTS) {
                    printf("\nError: System database is full!\n");
                    break;
                }
                
                printf("\n--- Enter New Student Details ---\n");
                printf("Enter Roll Number: ");
                scanf("%d", &rollNumbers[studentCount]);
                
                // Clear input buffer before reading string with spaces
                while (getchar() != '\n'); 
                
                printf("Enter Student Name: ");
                // Read line safely (including spaces), strip newline
                fgets(names[studentCount], NAME_LENGTH, stdin);
                names[studentCount][strcspn(names[studentCount], "\n")] = '\0';
                
                printf("Enter Marks: ");
                scanf("%f", &marks[studentCount]);
                
                studentCount++;
                printf("\nRecord added successfully!\n");
                break;
                
            case 2:
                // View all collected metrics
                if (studentCount == 0) {
                    printf("\nNo student records found in the system.\n");
                    break;
                }
                
                printf("\n%-10s %-30s %-10s\n", "Roll No", "Student Name", "Marks");
                printf("----------------------------------------------------\n");
                for (int i = 0; i < studentCount; i++) {
                    printf("%-10d %-30s %-10.2f\n", rollNumbers[i], names[i], marks[i]);
                }
                break;
                
            case 3:
                // Linear search mechanism
                if (studentCount == 0) {
                    printf("\nNo records available to search.\n");
                    break;
                }
                
                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);
                
                found = 0;
                for (int i = 0; i < studentCount; i++) {
                    if (rollNumbers[i] == searchRoll) {
                        printf("\n--- Student Found ---\n");
                        printf("Roll Number : %d\n", rollNumbers[i]);
                        printf("Name        : %s\n", names[i]);
                        printf("Marks       : %.2f\n", marks[i]);
                        found = 1;
                        break; // Stop loop since unique record is found
                    }
                }
                
                if (!found) {
                    printf("\nRecord with Roll Number %d not found.\n", searchRoll);
                }
                break;
                
            case 4:
                // Graceful loop termination
                printf("\nExiting Student Record System. Goodbye!\n");
                return 0;
                
            default:
                printf("\nInvalid Choice! Please pick an option between 1 and 4.\n");
        }
    }
    
    return 0;
}
