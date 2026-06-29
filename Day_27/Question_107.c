#include <stdio.h>
#include <string.h>


struct Employee {
    int id;
    char name[50];
    float basic_salary;
    float hra;          
    float da;           
    float pf;           
    float gross_salary;
    float net_salary;
};

int main() {
    
    struct Employee employees[100];
    int employee_count = 0;
    int choice;

    
    int search_id;
    int found;

    
    while (1) {
        printf("\n====================================");
        printf("\n      SALARY MANAGEMENT SYSTEM      ");
        printf("\n====================================");
        printf("\n1. Add New Employee Record");
        printf("\n2. Display All Employee Payslips");
        printf("\n3. Search Employee Salary Details");
        printf("\n4. Exit");
        printf("\n====================================");
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        
        if (choice == 1) {
            
            if (employee_count >= 100) {
                printf("\nError: Database is full!\n");
            } else {
                printf("\nEnter Employee ID: ");
                scanf("%d", &employees[employee_count].id);
                
                printf("Enter Employee Name (No spaces): ");
                scanf("%s", employees[employee_count].name);
                
                printf("Enter Basic Salary: ");
                scanf("%f", &employees[employee_count].basic_salary);

               
                employees[employee_count].hra = employees[employee_count].basic_salary * 0.20;
                employees[employee_count].da = employees[employee_count].basic_salary * 0.10;
                employees[employee_count].pf = employees[employee_count].basic_salary * 0.12;

                
                employees[employee_count].gross_salary = employees[employee_count].basic_salary + 
                                                         employees[employee_count].hra + 
                                                         employees[employee_count].da;

                
                employees[employee_count].net_salary = employees[employee_count].gross_salary - 
                                                       employees[employee_count].pf;

                printf("\nEmployee added successfully!\n");
                employee_count++; // Increment total database count
            }
        } 
        else if (choice == 2) {
           
            if (employee_count == 0) {
                printf("\nNo employee records found.\n");
            } else {
                printf("\n---------------------------------------------------------------------------------\n");
                printf("%-5s %-15s %-12s %-8s %-8s %-8s %-12s %-12s\n", 
                       "ID", "Name", "Basic", "HRA", "DA", "PF", "Gross", "Net Pay");
                printf("---------------------------------------------------------------------------------\n");
                
                
                for (int i = 0; i < employee_count; i++) {
                    printf("%-5d %-15s %-12.2f %-8.2f %-8.2f %-8.2f %-12.2f %-12.2f\n",
                           employees[i].id,
                           employees[i].name,
                           employees[i].basic_salary,
                           employees[i].hra,
                           employees[i].da,
                           employees[i].pf,
                           employees[i].gross_salary,
                           employees[i].net_salary);
                }
                printf("---------------------------------------------------------------------------------\n");
            }
        } 
        else if (choice == 3) {
            
            if (employee_count == 0) {
                printf("\nNo records available to search.\n");
            } else {
                printf("\nEnter Employee ID to search: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < employee_count; i++) {
                    if (employees[i].id == search_id) {
                        printf("\n--- Detailed Payslip for %s ---", employees[i].name);
                        printf("\nEmployee ID   : %d", employees[i].id);
                        printf("\nBasic Salary  : $%.2f", employees[i].basic_salary);
                        printf("\nAllowance HRA : $%.2f", employees[i].hra);
                        printf("\nAllowance DA  : $%.2f", employees[i].da);
                        printf("\nDeduction PF  : $%.2f", employees[i].pf);
                        printf("\n-------------------------------");
                        printf("\nGross Salary  : $%.2f", employees[i].gross_salary);
                        printf("\nNet Take-Home : $%.2f\n", employees[i].net_salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nEmployee with ID %d not found.\n", search_id);
                }
            }
        } 
        else if (choice == 4) {
            printf("\nExiting Salary Management System. Goodbye!\n");
            break; 
        } 
        else {
            printf("\nInvalid selection! Please input an option from 1 to 4.\n");
        }
    }

    return 0;
}
