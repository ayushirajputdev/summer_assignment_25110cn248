#include <stdio.h>

int main() {
    char str1[256];
    char str2[256];
    int checked[256] = {0}; // Array to keep track of already printed characters
    int i, j;

    // 1. Take two strings as input from the user
    printf("Enter the first string: ");
    scanf("%[^\n]%*c", str1); // Reads string with spaces and clears newline

    printf("Enter the second string: ");
    scanf("%[^\n]%*c", str2); 

    printf("Common characters are: ");

    // 2. Outer loop to iterate through the first string character by character
    for (i = 0; str1[i] != '\0'; i++) {
        
        // Skip spaces to focus only on visible characters
        if (str1[i] == ' ') {
            continue;
        }

        // 3. Inner loop to compare current character with the second string
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                
                // Get the ASCII integer value of the character
                int ascii_val = (int)str1[i];

                // 4. Check if this common character was already printed
                if (checked[ascii_val] == 0) {
                    printf("%c ", str1[i]);
                    checked[ascii_val] = 1; // Mark as printed
                }
                break; // Move to the next character in str1
            }
        }
    }
    printf("\n");

    return 0;
}
