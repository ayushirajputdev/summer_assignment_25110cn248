#include <stdio.h>

int main() {
    int n, target, found = 0;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum to find: ");
    scanf("%d", &target);
    printf("\n--- Results ---\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the current pair equals the target
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d) at indices [%d] and [%d]\n", arr[i], arr[j], i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No pair found with the sum %d.\n", target);
    }

    return 0;
}
