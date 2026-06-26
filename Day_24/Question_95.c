#include <stdio.h>

int main() {
    char str[500];
    int i = 0, current_len = 0, max_len = 0;
    int current_start = 0, max_start = 0;

    
    printf("Enter a string: ");
    scanf("%[^\n]s", str);

   
    for (i = 0; str[i] != '\0'; i++) {
       
        if (str[i] != ' ') {
          
            if (current_len == 0) {
                current_start = i;
            }
            current_len++; 
        } 
       
        else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start = current_start;
            }
            current_len = 0; 
        }
    }

    
    if (current_len > max_len) {
        max_len = current_len;
        max_start = current_start;
    }

   
    printf("\nThe longest word is: ");
    for (i = max_start; i < max_start + max_len; i++) {
        printf("%c", str[i]);
    }
    printf("\nLength of the longest word: %d\n", max_len);

    return 0;
}
