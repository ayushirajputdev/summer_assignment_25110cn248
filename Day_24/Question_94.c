#include <stdio.h>

int main() {
    char str[1000];
    int i = 0;

    
    printf("Enter a string to compress: ");
    scanf("%999s", str);

    printf("Compressed string: ");

  
    while (str[i] != '\0') {
        char current_char = str[i];
        int count = 0;

        
        while (str[i] != '\0' && str[i] == current_char) {
            count++;
            i++;
        }

       
        printf("%c%d", current_char, count);
    }

    printf("\n");
    return 0;
}
