#include <stdio.h>

int main() {
    int n, i, target, first, last, middle, found = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d integers in sorted (ascending) order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    
    printf("Enter the value to find: ");
    scanf("%d", &target);

    
    first = 0;
    last = n - 1;

    while (first <= last) {
        middle = first + (last - first) / 2; 

        if (array[middle] == target) {
            printf("Element %d found at index position: %d\n", target, middle);
            found = 1;
            break; 
        }
        else if (array[middle] < target) {
            first = middle + 1; 
        }
        else {
            last = middle - 1; 
        }
    }
    if (!found) {
        printf("Element %d is not present in the array.\n", target);
    }

    return 0;
}
