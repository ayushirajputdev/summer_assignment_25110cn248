#include <stdio.h>
#include <string.h>


struct Student {
    int roll_no;
    char name[50];
    int math;
    int science;
    int english;
    int total;
    float percentage;
    char division[15];
    char result[5];
};

int main() {
    int num_students;

    printf("=========================================\n");
    printf("       MARKSHEET GENERATION SYSTEM       \n");
    printf("=========================================\n");
    
    
    printf("Enter the number of students to process: ");
    scanf("%d", &num_students);

    struct Student students[num_students];

   
    for (int i = 0; i < num_students; i++) {
        printf("\n-----------------------------------------\n");
        printf("Entering Details for Student %d\n", i + 1);
        printf("-----------------------------------------\n");

        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);
        
        printf("Enter Student Name: ");
        scanf(" %[^\n]s", students[i].name); 
        do {
            printf("Enter Mathematics Marks (0-100): ");
            scanf("%d", &students[i].math);
            if (students[i].math < 0 || students[i].math > 100) {
                printf("Invalid allocation! Score must range between 0 and 100.\n");
            }
        } while (students[i].math < 0 || students[i].math > 100);

        do {
            printf("Enter Science Marks (0-100): ");
            scanf("%d", &students[i].science);
            if (students[i].science < 0 || students[i].science > 100) {
                printf("Invalid allocation! Score must range between 0 and 100.\n");
            }
        } while (students[i].science < 0 || students[i].science > 100);

        do {
            printf("Enter English Marks (0-100): ");
            scanf("%d", &students[i].english);
            if (students[i].english < 0 || students[i].english > 100) {
                printf("Invalid allocation! Score must range between 0 and 100.\n");
            }
        } while (students[i].english < 0 || students[i].english > 100);

        
        students[i].total = students[i].math + students[i].science + students[i].english;
        students[i].percentage = students[i].total / 3.0;

        
        if (students[i].math >= 40 && students[i].science >= 40 && students[i].english >= 40) {
            strcpy(students[i].result, "PASS");

           
            if (students[i].percentage >= 75.0) {
                strcpy(students[i].division, "Distinction");
            } else if (students[i].percentage >= 60.0) {
                strcpy(students[i].division, "First Div");
            } else if (students[i].percentage >= 50.0) {
                strcpy(students[i].division, "Second Div");
            } else {
                strcpy(students[i].division, "Third Div");
            }
        } else {
            strcpy(students[i].result, "FAIL");
            strcpy(students[i].division, "N/A");
        }
    }

    
    printf("\n\n=================================================================================\n");
    printf("                               MASTER MARKSHEET REPORT                           \n");
    printf("=================================================================================\n");
    printf("%-7s %-15s %-5s %-5s %-5s %-5s %-7s %-6s %-12s\n", 
           "Roll No", "Name", "Math", "Sci", "Eng", "Total", "Per(%)", "Status", "Division");
    printf("---------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("%-7d %-15s %-5d %-5d %-5d %-5d %-7.2f %-6s %-12s\n",
               students[i].roll_no,
               students[i].name,
               students[i].math,
               students[i].science,
               students[i].english,
               students[i].total,
               students[i].percentage,
               students[i].result,
               students[i].division);
    }
    printf("=================================================================================\n");

    return 0;
}
