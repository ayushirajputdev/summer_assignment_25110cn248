#include <stdio.h>

int main() {
    char str1[256];
    char str2[256];
    int checked[256] = {0}; 
    int i, j;

   
    printf("Enter the first string: ");
    scanf("%[^\n]%*c", str1); 

    printf("Enter the second string: ");
    scanf("%[^\n]%*c", str2); 

    printf("Common characters are: ");

    
    for (i = 0; str1[i] != '\0'; i++) {
        
        
        if (str1[i] == ' ') {
            continue;
        }

       
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j]) {
                
               
                int ascii_val = (int)str1[i];

              
                if (checked[ascii_val] == 0) {
                    printf("%c ", str1[i]);
                    checked[ascii_val] = 1; 
                }
                break; 
            }
        }
    }
    printf("\n");

    return 0;
}
