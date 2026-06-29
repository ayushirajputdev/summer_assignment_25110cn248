#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int len1 = 0, len2 = 0;
    int frequency[256] = {0}; 
    int isAnagram = 1;        // 1 means true, 0 means false

    // 1. Take two strings as input from the user
    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // 2. Manually calculate the length of the first string
    while (str1[len1] != '\0') {
        len1++;
    }

    // 3. Manually calculate the length of the second string
    while (str2[len2] != '\0') {
        len2++;
    }

    // 4. Anagram check logic
    if (len1 != len2) {
        isAnagram = 0; // Length mismatch means they cannot be anagrams
    } else {
        // Increment frequency for characters in str1
        // Decrement frequency for characters in str2
        for (int i = 0; i < len1; i++) {
            frequency[(unsigned char)str1[i]]++;
            frequency[(unsigned char)str2[i]]--;
        }

        // Check if any character count is non-zero
        for (int i = 0; i < 256; i++) {
            if (frequency[i] != 0) {
                isAnagram = 0;
                break;
            }
        }
    }

    // 5. Display the final result
    if (isAnagram == 1) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
