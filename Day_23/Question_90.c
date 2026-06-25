#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int length;
    int found = 0;

   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    
    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);

   
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
           
            if (str[i] == str[j] && str[i] != ' ') {
                printf("The first repeating character is: '%c'\n", str[i]);
                found = 1;
                break; 
            }
        }
        if (found) {
            break;
        }
    }

   
    if (!found) {
        printf("No repeating characters found.\n");
    }

    return 0;
}
