#include <stdio.h>

int main() {
    int size;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    int visited[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    int maxElement = arr[0];
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; 
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    printf("\nThe highest frequency element is: %d\n", maxElement);

    printf("It appears %d time(s) in the array.\n", maxCount);
    return 0;


}