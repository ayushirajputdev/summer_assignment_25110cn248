#include <stdio.h>
int main(){
    
    int n, i;
    printf("Enter the number of elements you want to input: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int diff = arr[0] - 0; 
    int missing_found = 0;

    printf("\nMissing elements in the sequence are:\n");
    for (i = 0; i < n; i++) {
        
        if (arr[i] - i != diff) {
            
            while (diff < arr[i] - i) {
                printf("%d ", i + diff);
                diff++;
                missing_found = 1;
            }
        }
    }
    if (!missing_found) {
        printf("None! The sequence is complete.\n");
    } else {
        printf("\n");
    }
    return 0;

}