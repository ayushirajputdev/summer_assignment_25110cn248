#include <stdio.h>

int main() {
    char names[100][100];
    char temp[100];
    int n, i, j, k;

    // 1. Take the number of names from the user
    printf("Enter the number of names: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Clear the input buffer newline character
    while (getchar() != '\n');

    // 2. Read the names from the user
    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        // Read string including spaces until newline
        j = 0;
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            if (j < 99) {
                names[i][j++] = ch;
            }
        }
        names[i][j] = '\0'; // Manually null-terminate the string
    }

    // 3. Sort the names alphabetically using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            
            // Inline comparison (Manual implementation of strcmp)
            k = 0;
            while (names[j][k] != '\0' && names[j + 1][k] != '\0' && names[j][k] == names[j + 1][k]) {
                k++;
            }

            // If the current name is alphabetically greater, swap them
            if (names[j][k] > names[j + 1][k]) {
                
                // Inline string copy (Manual implementation of strcpy)
                // Step A: Copy names[j] to temp
                k = 0;
                while (names[j][k] != '\0') {
                    temp[k] = names[j][k];
                    k++;
                }
                temp[k] = '\0';

                // Step B: Copy names[j+1] to names[j]
                k = 0;
                while (names[j + 1][k] != '\0') {
                    names[j][k] = names[j + 1][k];
                    k++;
                }
                names[j][k] = '\0';

                // Step C: Copy temp to names[j+1]
                k = 0;
                while (temp[k] != '\0') {
                    names[j + 1][k] = temp[k];
                    k++;
                }
                names[j + 1][k] = '\0';
            }
        }
    }

    // 4. Output the sorted names
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
