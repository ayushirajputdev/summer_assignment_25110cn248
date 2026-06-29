#include <stdio.h>

int main() {
    char str1[200], str2[100], result[300];
    int choice;
    int i, j, len1, len2, same;

    while (1) {
        // Displaying the system menu
        printf("\n=============================");
        printf("\n STRING OPERATIONS SYSTEM    ");
        printf("\n=============================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n=============================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        // Consume the leftover newline character from buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                i = 0;
                while ((str1[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str1[i] = '\0'; // Null-terminate the string

                // Calculating length
                len1 = 0;
                while (str1[len1] != '\0') {
                    len1++;
                }
                printf("Length of the string: %d\n", len1);
                break;

            case 2:
                printf("\nEnter the source string to copy: ");
                i = 0;
                while ((str1[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str1[i] = '\0';

                // Copying logic
                i = 0;
                while (str1[i] != '\0') {
                    str2[i] = str1[i];
                    i++;
                }
                str2[i] = '\0'; // Null-terminate target string

                printf("Copied String (Destination): %s\n", str2);
                break;

            case 3:
                printf("\nEnter first string: ");
                i = 0;
                while ((str1[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str1[i] = '\0';

                printf("Enter second string: ");
                i = 0;
                while ((str2[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str2[i] = '\0';

                // Concatenation logic
                i = 0;
                while (str1[i] != '\0') {
                    result[i] = str1[i];
                    i++;
                }
                j = 0;
                while (str2[j] != '\0') {
                    result[i] = str2[j];
                    i++;
                    j++;
                }
                result[i] = '\0'; // Null-terminate concatenated string

                printf("Concatenated String: %s\n", result);
                break;

            case 4:
                printf("\nEnter first string to compare: ");
                i = 0;
                while ((str1[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str1[i] = '\0';

                printf("Enter second string to compare: ");
                i = 0;
                while ((str2[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str2[i] = '\0';

                // Comparison logic
                i = 0;
                same = 1;
                while (str1[i] != '\0' || str2[i] != '\0') {
                    if (str1[i] != str2[i]) {
                        same = 0;
                        break;
                    }
                    i++;
                }

                if (same == 1) {
                    printf("The strings are identical.\n");
                } else {
                    printf("The strings are different.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                i = 0;
                while ((str1[i] = getchar()) != '\n' && i < 99) {
                    i++;
                }
                str1[i] = '\0';

                // Find length first
                len1 = 0;
                while (str1[len1] != '\0') {
                    len1++;
                }

                // Reversal logic using a second array
                j = 0;
                for (i = len1 - 1; i >= 0; i--) {
                    str2[j] = str1[i];
                    j++;
                }
                str2[j] = '\0';

                printf("Reversed String: %s\n", str2);
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid selection! Please enter a option between 1 and 6.\n");
        }
    }
    return 0;
}

