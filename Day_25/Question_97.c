#include <stdio.h>

int main() {
    // Declare arrays with sufficient size
    char str1[100], str2[100], merged[200];
    int i = 0, j = 0;

    // Take strings from the user
    printf("Enter the first string: ");
    scanf("%[^\n]%*c", str1); // Reads string with spaces and clears buffer

    printf("Enter the second string: ");
    scanf("%[^\n]%*c", str2);

    // Copy elements of the first array into the merged array
    while (str1[i] != '\0') {
        merged[i] = str1[i];
        i++;
    }

    // Append elements of the second array into the merged array
    while (str2[j] != '\0') {
        merged[i] = str2[j];
        i++;
        j++;
    }

    // Insert the null terminator to mark the end of the merged string
    merged[i] = '\0';

    // Display the result
    printf("\nMerged String: %s\n", merged);

    return 0;
}
