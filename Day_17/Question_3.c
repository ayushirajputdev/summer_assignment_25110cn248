#include <stdio.h>

int main() {
    int n1, n2;
    int i, j, k;
    int isDuplicate, isAlreadyInResult;

    
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter %d elements for the first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter %d elements for the second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    
    int maxSize = (n1 < n2) ? n1 : n2;
    int result[maxSize];
    int resultCount = 0;

    
    for (i = 0; i < n1; i++) {
        
        isDuplicate = 0;
        for (k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate) {
            continue; 
        }

        
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                
                
                isAlreadyInResult = 0;
                for (k = 0; k < resultCount; k++) {
                    if (result[k] == arr1[i]) {
                        isAlreadyInResult = 1;
                        break;
                    }
                }

                
                if (!isAlreadyInResult) {
                    result[resultCount] = arr1[i];
                    resultCount++;
                }
                break; 
            }
        }
    }

    
    if (resultCount == 0) {
        printf("\nNo common elements found. Intersection is empty.\n");
    } else {
        printf("\nIntersection of the two arrays: ");
        for (i = 0; i < resultCount; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    return 0;
}
