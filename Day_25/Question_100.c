#include <stdio.h>

int main() {
    char str[500];
    char words[100][50];
    int lengths[100];
    int wordCount = 0;
    int r = 0, c = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    while (str[r] != '\0') {
       
        if (str[r] == '\n') {
            str[r] = '\0';
            break;
        }

       
        if (str[r] == ' ') {
            if (c > 0) { 
                words[wordCount][c] = '\0';
                lengths[wordCount] = c;
                wordCount++;
                c = 0; 
            }
        } else {
            words[wordCount][c] = str[r];
            c++;
        }
        r++;
    }
    
    
    if (c > 0) {
        words[wordCount][c] = '\0';
        lengths[wordCount] = c;
        wordCount++;
    }

    
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = 0; j < wordCount - i - 1; j++) {
            if (lengths[j] > lengths[j + 1]) {
                
                // Swap the lengths
                int tempLen = lengths[j];
                lengths[j] = lengths[j + 1];
                lengths[j + 1] = tempLen;

                
                char tempWord[50];
                int k = 0;
                
                
                while (words[j][k] != '\0') {
                    tempWord[k] = words[j][k];
                    k++;
                }
                tempWord[k] = '\0';

                
                k = 0;
                while (words[j + 1][k] != '\0') {
                    words[j][k] = words[j + 1][k];
                    k++;
                }
                words[j][k] = '\0';

               
                k = 0;
                while (tempWord[k] != '\0') {
                    words[j + 1][k] = tempWord[k];
                    k++;
                }
                words[j + 1][k] = '\0';
            }
        }
    }

    
    printf("\nWords sorted by length:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s (Length: %d)\n", words[i], lengths[i]);
    }

    return 0;
}
