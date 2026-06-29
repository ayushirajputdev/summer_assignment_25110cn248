#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, i, element, position, found;

    while (1) {
        // Displaying Menu Options
        printf("\n=============================");
        printf("\n    ARRAY OPERATIONS MENU    ");
        printf("\n=============================");
        printf("\n1. Create / Initialize Array");
        printf("\n2. Display Array");
        printf("\n3. Insert an Element");
        printf("\n4. Delete an Element");
        printf("\n5. Search an Element");
        printf("\n6. Exit");
        printf("\n=============================");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create / Initialize Array
                printf("\nEnter the number of elements to store (max %d): ", MAX_SIZE);
                scanf("%d", &size);

                if (size < 0 || size > MAX_SIZE) {
                    printf("Invalid size! Resetting array size to 0.\n");
                    size = 0;
                } else {
                    printf("Enter %d elements:\n", size);
                    for (i = 0; i < size; i++) {
                        printf("Element [%d]: ", i);
                        scanf("%d", &arr[i]);
                    }
                    printf("Array created successfully.\n");
                }
                break;

            case 2: // Display Array
                if (size == 0) {
                    printf("\nArray is empty! Nothing to display.\n");
                } else {
                    printf("\nArray elements: ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\nTotal elements: %d\n", size);
                }
                break;

            case 3: // Insert an Element
                if (size >= MAX_SIZE) {
                    printf("\nError: Array Overflow! Cannot insert more elements.\n");
                } else {
                    printf("\nEnter the element to insert: ");
                    scanf("%d", &element);
                    printf("Enter the index position (0 to %d): ", size);
                    scanf("%d", &position);

                    if (position < 0 || position > size) {
                        printf("Invalid position! Insertion failed.\n");
                    } else {
                        // Shift elements right to create space
                        for (i = size; i > position; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[position] = element; // Insert element
                        size++; // Increment the active size
                        printf("Element inserted successfully.\n");
                    }
                }
                break;

            case 4: // Delete an Element
                if (size == 0) {
                    printf("\nError: Array Underflow! No element to delete.\n");
                } else {
                    printf("\nEnter the index position to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);

                    if (position < 0 || position >= size) {
                        printf("Invalid position! Deletion failed.\n");
                    } else {
                        printf("Deleted element: %d\n", arr[position]);
                        // Shift elements left to plug the gap
                        for (i = position; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--; // Decrement active size
                        printf("Element deleted successfully.\n");
                    }
                }
                break;

            case 5: // Search an Element (Linear Search)
                if (size == 0) {
                    printf("\nArray is empty! Cannot perform search.\n");
                } else {
                    printf("\nEnter the element to search for: ");
                    scanf("%d", &element);
                    
                    found = -1;
                    for (i = 0; i < size; i++) {
                        if (arr[i] == element) {
                            found = i;
                            break; // Stop loop upon finding target
                        }
                    }

                    if (found != -1) {
                        printf("Element %d found at index position: %d\n", element, found);
                    } else {
                        printf("Element %d not found in the array.\n", element);
                    }
                }
                break;

            case 6: // Exit
                printf("\nExiting system. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid Choice! Please select a valid option between 1 and 6.\n");
        }
    }
    return 0;
}
