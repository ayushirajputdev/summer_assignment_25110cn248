#include <stdio.h>

int main() {
    int n, i, j, k;
    char names[100][50];
    char temp[50];

    
    printf("Enter the number of names: ");
    scanf("%d", &n);

    
    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            
            
            k = 0;
            while (names[j][k] != '\0' && names[j + 1][k] != '\0' && names[j][k] == names[j + 1][k]) {
                k++;
            }

            
            if (names[j][k] > names[j + 1][k]) {
                
               
                k = 0;
                while (names[j][k] != '\0') {
                    temp[k] = names[j][k];
                    k++;
                }
                temp[k] = '\0';

                // names[j] = names[j+1]
                k = 0;
                while (names[j + 1][k] != '\0') {
                    names[j][k] = names[j + 1][k];
                    k++;
                }
                names[j][k] = '\0';

                // names[j+1] = temp
                k = 0;
                while (temp[k] != '\0') {
                    names[j + 1][k] = temp[k];
                    k++;
                }
                names[j + 1][k] = '\0';
            }
        }
    }

    
    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
