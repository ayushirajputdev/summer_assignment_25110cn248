#include <stdio.h>

int main() {
    char sentence[1000];
    int freq[256] = {0}; 
    int i = 0;

    printf("Enter a string: ");
   
    scanf("%[^\n]s", sentence);

   
    while (sentence[i] != '\0') {
       
        freq[(unsigned char)sentence[i]]++;
        i++;
    }

    printf("\nCharacter Frequencies:\n");
    
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
           
            if (i == ' ') {
                printf("' ' (space) : %d\n", freq[i]);
            } else if (i == '\t') {
                printf("'\\t' (tab)  : %d\n", freq[i]);
            } else {
                printf("'%c'         : %d\n", i, freq[i]);
            }
        }
    }

    return 0;
}
