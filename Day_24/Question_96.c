#include <stdio.h>

int main() {
    char str[1000];
    int exists[256] = {0}; 
    int i = 0;             
    int j = 0;            
   
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

   
    while (str[i] != '\0') {
       
        if (str[i] == '\n') {
            i++;
            continue;
        }

       
        unsigned char ch = str[i];

        
        if (exists[ch] == 0) {
            exists[ch] = 1;     // Mark as seen
            str[j] = str[i];    // Keep the character
            j++;                // Advance writer index
        }
        i++;                    // Advance reader index
    }
    
   
    str[j] = '\0';

    
    printf("String after removing duplicates: %s\n", str);

    return 0;
}
