#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    // Array to store up to 100 employee records
    struct Employee emp[100];
    int count = 0; // Tracks the total number of employees currently in the system
    int choice;    // Stores user menu selection
    
    // Variables used for temporary operations throughout the execution
    int i, j;
    int searchId, found;

    // Infinite loop for menu execution until explicitly exited
    while (1) {
        printf("\n=================================");
        printf("\n=== EMPLOYEE MANAGEMENT SYSTEM ===");
        printf("\n=================================");
        printf("\n1. Add Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        // Process user choice
        if (choice == 1) {
            // === ADD EMPLOYEE ===
            if (count < 100) {
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[count].id);
                
                // Check if the ID already exists to maintain unique records
                found = 0;
                for (i = 0; i < count; i++) {
                    if (emp[i].id == emp[count].id) {
                        found = 1;
                        break;
                    }
                }
                
                if (found == 1) {
                    printf("Error: An employee with ID %d already exists.\n", emp[count].id);
                } else {
                    printf("Enter Employee Name: ");
                    getchar(); // Consume trailing newline character from scanf
                    fgets(emp[count].name, sizeof(emp[count].name), stdin);
                    emp[count].name[strcspn(emp[count].name, "\n")] = 0; // Strip newline character

                    printf("Enter Department: ");
                    fgets(emp[count].department, sizeof(emp[count].department), stdin);
                    emp[count].department[strcspn(emp[count].department, "\n")] = 0; // Strip newline character

                    printf("Enter Salary: ");
                    scanf("%f", &emp[count].salary);

                    count++; // Increment the global counter
                    printf("\nEmployee added successfully!\n");
                }
            } else {
                printf("\nSystem database full! Cannot add more employees.\n");
            }
            
        } else if (choice == 2) {
            // === DISPLAY ALL EMPLOYEES ===
            if (count == 0) {
                printf("\nNo records found in the system.\n");
            } else {
                printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
                printf("-------------------------------------------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("%-10d %-20s %-20s %-10.2f\n", emp[i].id, emp[i].name, emp[i].department, emp[i].salary);
                }
            }
            
        } else if (choice == 3) {
            // === SEARCH EMPLOYEE BY ID ===
            if (count == 0) {
                printf("\nNo records available to search.\n");
            } else {
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &searchId);
                
                found = 0;
                for (i = 0; i < count; i++) {
                    if (emp[i].id == searchId) {
                        printf("\nEmployee Found Details:");
                        printf("\n-----------------------");
                        printf("\nID        : %d", emp[i].id);
                        printf("\nName      : %s", emp[i].name);
                        printf("\nDepartment: %s", emp[i].department);
                        printf("\nSalary    : %.2f\n", emp[i].salary);
                        found = 1;
                        break; // Stop searching once a match is found
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID %d not found.\n", searchId);
                }
            }
            
        } else if (choice == 4) {
            // === DELETE EMPLOYEE RECORD ===
            if (count == 0) {
                printf("\nNo records available to delete.\n");
            } else {
                printf("\nEnter Employee ID to delete: ");
                scanf("%d", &searchId);
                
                found = 0;
                for (i = 0; i < count; i++) {
                    if (emp[i].id == searchId) {
                        // Shift all subsequent records left to fill the gap
                        for (j = i; j < count - 1; j++) {
                            emp[j] = emp[j + 1];
                        }
                        count--; // Decrease the total records counter
                        found = 1;
                        printf("\nRecord deleted successfully!\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID %d not found.\n", searchId);
                }
            }
            
        } else if (choice == 5) {
            // === EXIT ===
            printf("\nExiting the system. Goodbye!\n");
            break; // Terminates the infinite loop
            
        } else {
            // === INVALID MENU INPUT ===
            printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}
