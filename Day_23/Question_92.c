#include <stdio.h>

int main() {
    char str[1000];
    int freq[256] = {0}; 
    int i = 0;
    int max_count = 0;
    char max_char = ' ';

    printf("Enter a string: ");
   
    fgets(str, sizeof(str), stdin);

    
    while (str[i] != '\0') {
       
        if (str[i] != '\n') {
            freq[(unsigned char)str[i]]++;
        }
        i++;
    }

    
    i = 0;
    while (str[i] != '\0') {
        if (str[i] != '\n') {
            int current_char_count = freq[(unsigned char)str[i]];
            
            if (current_char_count > max_count) {
                max_count = current_char_count;
                max_char = str[i];
            }
        }
        i++;
    }

    if (max_count > 0) {
        printf("\nMaximum occurring character is '%c', appearing %d times.\n", max_char, max_count);
    } else {
        printf("\nThe string is empty.\n");
    }

    return 0;
}
