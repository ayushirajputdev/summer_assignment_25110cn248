#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
    char department[30];
};

int main() {
    struct Employee empList[MAX_EMPLOYEES];
    int empCount = 0;
    int choice;
    
    int searchId;
    int foundIndex;
    int i, j;

    while (1) {
        
        printf("\n=================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add Employee Records");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Delete Employee Record");
        printf("\n5. Exit System");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (empCount >= MAX_EMPLOYEES) {
                    printf("\nError: System database is full!\n");
                } else {
                    printf("\nEnter Employee ID: ");
                    scanf("%d", &empList[empCount].id);
                    
                   
                    getchar(); 
                    printf("Enter Employee Name: ");
                    fgets(empList[empCount].name, sizeof(empList[empCount].name), stdin);
                    empList[empCount].name[strcspn(empList[empCount].name, "\n")] = '\0'; 

                    printf("Enter Department: ");
                    fgets(empList[empCount].department, sizeof(empList[empCount].department), stdin);
                    empList[empCount].department[strcspn(empList[empCount].department, "\n")] = '\0'; 

                    printf("Enter Salary: ");
                    scanf("%f", &empList[empCount].salary);

                    empCount++;
                    printf("\nSuccess: Employee profile added successfully!\n");
                }
                break;

            case 2: 
                if (empCount == 0) {
                    printf("\nNo employee records found in the database.\n");
                } else {
                    printf("\n-------------------------------------------------------------");
                    printf("\n%-10s %-20s %-15s %-10s", "ID", "Name", "Department", "Salary");
                    printf("\n-------------------------------------------------------------");
                    for (i = 0; i < empCount; i++) {
                        printf("\n%-10d %-20s %-15s %-10.2f", 
                               empList[i].id, 
                               empList[i].name, 
                               empList[i].department, 
                               empList[i].salary);
                    }
                    printf("\n-------------------------------------------------------------\n");
                }
                break;

            case 3: 
                if (empCount == 0) {
                    printf("\nDatabase is empty. Nothing to search.\n");
                } else {
                    printf("\nEnter Employee ID to search: ");
                    scanf("%d", &searchId);

                    foundIndex = -1;
                    for (i = 0; i < empCount; i++) {
                        if (empList[i].id == searchId) {
                            foundIndex = i;
                            break;
                        }
                    }

                    if (foundIndex != -1) {
                        printf("\n--- Record Found ---");
                        printf("\nID: %d", empList[foundIndex].id);
                        printf("\nName: %s", empList[foundIndex].name);
                        printf("\nDepartment: %s", empList[foundIndex].department);
                        printf("\nSalary: %.2f\n", empList[foundIndex].salary);
                    } else {
                        printf("\nError: Employee ID %d not found.\n", searchId);
                    }
                }
                break;

            case 4: 
                if (empCount == 0) {
                    printf("\nDatabase is empty. Nothing to delete.\n");
                } else {
                    printf("\nEnter Employee ID to delete: ");
                    scanf("%d", &searchId);

                    foundIndex = -1;
                    for (i = 0; i < empCount; i++) {
                        if (empList[i].id == searchId) {
                            foundIndex = i;
                            break;
                        }
                    }

                    if (foundIndex != -1) {
                        
                        for (j = foundIndex; j < empCount - 1; j++) {
                            empList[j] = empList[j + 1];
                        }
                        empCount--; 
                        printf("\nSuccess: Employee record deleted.\n");
                    } else {
                        printf("\nError: Employee ID %d not found.\n", searchId);
                    }
                }
                break;

            case 5: 
                printf("\nExiting the system. Thank you!\n");
                return 0;

            default:
                printf("\nInvalid Selection! Please input a valid option (1-5).\n");
        }
    }
    return 0;
}
