#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0}; //initial frequency of all ascii character is 0
    int i;
    int found = 0;

    printf("Enter a string or sentence: ");
    fgets(str, sizeof(str), stdin);

   
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;//takes the frequency of characters rather than the whole new line 
        }
    }

  
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && freq[(unsigned char)str[i]] == 1) {
            printf("The first non-repeating character is: '%c'\n", str[i]);
            found = 1;
            break;//to exit the loop after finding the first non repeating character
        }
    }

    
    if (found==0) {
        printf("All characters repeat or no valid characters entered.\n");
    }

    return 0;
}
