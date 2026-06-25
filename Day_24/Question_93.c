#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int len1 = 0, len2 = 0;
    int isRotation = 0;

   
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    
    while (str1[len1] != '\0') {
        len1++;
    }

    
    while (str2[len2] != '\0') {
        len2++;
    }

   
    if (len1 == len2) {
        
        if (len1 == 0) {
            isRotation = 1;
        }
        else {
           
            for (int j = 0; j < len1; j++) {
                int matchCount = 0;

                
                for (int i = 0; i < len1; i++) {
                    if (str1[(j + i) % len1] == str2[i]) {
                        matchCount++;
                    } else {
                        break; 
                    }
                }

                
                if (matchCount == len1) {
                    isRotation = 1;
                    break;
                }
            }
        }
    }

   
    if (isRotation) {
        printf("Result: The second string IS a rotation of the first string.\n");
    } else {
        printf("Result: The second string IS NOT a rotation of the first string.\n");
    }

    return 0;
}
