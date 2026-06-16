#include <stdio.h>
int main(){
    int arr[100], visited[100] = {0},n, i, j,hasDuplicates = 0;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nDuplicate elements in the given array are: \n");

    for (i = 0; i < n; i++) {
        
        if (visited[i] == 1) {
            continue;
        }
        int isDuplicate = 0;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                visited[j] = 1; 
            }
        }
        if (isDuplicate == 1) {
            printf("%d ", arr[i]);
            hasDuplicates = 1;
        }
    }

    if (!hasDuplicates) {
        printf("None (All elements are unique)");
    }

    printf("\n");
    return 0;
}