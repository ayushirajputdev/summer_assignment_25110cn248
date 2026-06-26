#include <stdio.h>

int main() {
    
    char str1[100], str2[100], merged[200];
    int i = 0, j = 0;

    
    printf("Enter the first string: ");
    scanf("%[^\n]%*c", str1); 

    printf("Enter the second string: ");
    scanf("%[^\n]%*c", str2);

    
    while (str1[i] != '\0') {
        merged[i] = str1[i];
        i++;
    }

    
    while (str2[j] != '\0') {
        merged[i] = str2[j];
        i++;
        j++;
    }

    
    merged[i] = '\0';

   
    printf("\nMerged String: %s\n", merged);

    return 0;
}
