#include <stdio.h>

int main() {
    char str[500];
    char words[50][50];
    int lengths[50];
    int i = 0, wordCount = 0, charIndex = 0;

    // 1. Get string input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // 2. Extract words and calculate their lengths manually
    while (str[i] != '\0') {
        // If character is not a space, newline, or tab, it belongs to the current word
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            words[wordCount][charIndex] = str[i];
            charIndex++;
        } 
        // If a word boundary is hit and we have accumulated characters
        else if (charIndex > 0) {
            words[wordCount][charIndex] = '\0'; // Null-terminate the word
            lengths[wordCount] = charIndex;     // Store the word length
            wordCount++;
            charIndex = 0;                      // Reset character index for next word
        }
        i++;
    }
    // Handle the last word if the string doesn't end with a space/newline
    if (charIndex > 0) {
        words[wordCount][charIndex] = '\0';
        lengths[wordCount] = charIndex;
        wordCount++;
    }

    // 3. Sort words by length using Bubble Sort
    for (int step = 0; step < wordCount - 1; step++) {
        for (int curr = 0; curr < wordCount - step - 1; curr++) {
            // Compare lengths of adjacent words
            if (lengths[curr] > lengths[curr + 1]) {
                
                // Swap lengths
                int tempLen = lengths[curr];
                lengths[curr] = lengths[curr + 1];
                lengths[curr + 1] = tempLen;

                // Swap strings character by character
                char tempWord[50];
                int k = 0;
                
                // Copy words[curr] to tempWord
                while (words[curr][k] != '\0') {
                    tempWord[k] = words[curr][k];
                    k++;
                }
                tempWord[k] = '\0';

                // Copy words[curr+1] to words[curr]
                k = 0;
                while (words[curr + 1][k] != '\0') {
                    words[curr][k] = words[curr + 1][k];
                    k++;
                }
                words[curr][k] = '\0';

                // Copy tempWord to words[curr+1]
                k = 0;
                while (tempWord[k] != '\0') {
                    words[curr + 1][k] = tempWord[k];
                    k++;
                }
                words[curr + 1][k] = '\0';
            }
        }
    }

    // 4. Print the sorted words
    printf("Words sorted by length:\n");
    for (int w = 0; w < wordCount; w++) {
        int c = 0;
        while (words[w][c] != '\0') {
            putchar(words[w][c]);
            c++;
        }
        putchar(' '); // Space separation between words
    }
    putchar('\n');

    return 0;
}
