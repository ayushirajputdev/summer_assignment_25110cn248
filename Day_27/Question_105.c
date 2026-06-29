#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Define the student structure
struct Student {
    int rollNumber;
    char name[50];
    float gpa;
};

int main() {
    // Array to store records and control variables
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    
    // Loop control flags and search utility variables
    int searchRoll;
    int foundIndex;
    int i, j;

    while (1) {
        // Display Application Menu
        printf("\n=== STUDENT RECORD MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit Application\n");
        printf("Enter your selection (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // ADD STUDENT RECORD
                if (studentCount >= MAX_STUDENTS) {
                    printf("\nDatabase error: Storage limit reached (%d max).\n", MAX_STUDENTS);
                    break;
                }

                printf("\nEnter Roll Number: ");
                scanf("%d", &students[studentCount].rollNumber);
                
                // Buffer clearance for string consumption
                getchar(); 
                
                printf("Enter Full Name: ");
                fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
                students[studentCount].name[strcspn(students[studentCount].name, "\n")] = '\0'; // Strip trailing newline

                printf("Enter GPA: ");
                scanf("%f", &students[studentCount].gpa);

                studentCount++;
                printf("\nSuccess: Record added successfully!\n");
                break;

            case 2: // DISPLAY ALL RECORDS
                if (studentCount == 0) {
                    printf("\nDatabase empty: No student records found.\n");
                    break;
                }

                printf("\n-------------------------------------------------\n");
                printf("%-12s %-25s %-5s\n", "Roll No", "Name", "GPA");
                printf("-------------------------------------------------\n");
                for (i = 0; i < studentCount; i++) {
                    printf("%-12d %-25s %-.2f\n", students[i].rollNumber, students[i].name, students[i].gpa);
                }
                printf("-------------------------------------------------\n");
                break;

            case 3: // SEARCH STUDENT RECORD
                if (studentCount == 0) {
                    printf("\nDatabase empty: No student records found.\n");
                    break;
                }

                printf("\nEnter Roll Number to search: ");
                scanf("%d", &searchRoll);

                foundIndex = -1;
                for (i = 0; i < studentCount; i++) {
                    if (students[i].rollNumber == searchRoll) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("\nMatch Found:\n");
                    printf("Roll Number: %d\n", students[foundIndex].rollNumber);
                    printf("Name       : %s\n", students[foundIndex].name);
                    printf("GPA        : %.2f\n", students[foundIndex].gpa);
                } else {
                    printf("\nSearch failure: Student with Roll Number %d not found.\n", searchRoll);
                }
                break;

            case 4: // DELETE STUDENT RECORD
                if (studentCount == 0) {
                    printf("\nDatabase empty: No student records found.\n");
                    break;
                }

                printf("\nEnter Roll Number to delete: ");
                scanf("%d", &searchRoll);

                foundIndex = -1;
                for (i = 0; i < studentCount; i++) {
                    if (students[i].rollNumber == searchRoll) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    // Compress array elements forward to fill the target index gap
                    for (j = foundIndex; j < studentCount - 1; j++) {
                        students[j] = students[j + 1];
                    }
                    studentCount--;
                    printf("\nSuccess: Record deleted successfully.\n");
                } else {
                    printf("\nDeletion failure: Student with Roll Number %d not found.\n", searchRoll);
                }
                break;

            case 5: // EXIT APPLICATION
                printf("\nExiting System. Goodbye!\n");
                return 0;

            default:
                printf("\nInput error: Invalid option selected. Please select between 1 and 5.\n");
        }
    }
    return 0;
}

