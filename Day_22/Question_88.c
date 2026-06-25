#include <stdio.h>

int main() {
    char sentence[1000];
    int i = 0; 
    int j = 0; 

    printf("Enter a string: ");
    
    scanf("%[^\n]s", sentence);

    
    while (sentence[i] != '\0') {
        
        if (sentence[i] != ' ' && sentence[i] != '\t') {
            sentence[j] = sentence[i]; 
            j++; 
        }
        i++;
    }
    
    
    sentence[j] = '\0';

    printf("String after removing spaces: %s\n", sentence);

    return 0;
}
