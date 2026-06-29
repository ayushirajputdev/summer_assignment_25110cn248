#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

int main() {
    // Arrays acting as our data store for the inventory attributes
    int ids[MAX_ITEMS];
    char names[MAX_ITEMS][50];
    int quantities[MAX_ITEMS];
    float prices[MAX_ITEMS];
    
    int itemCount = 0; // Tracks total items currently in the system
    int choice;        // Tracks user's menu selection

    // Continuous loop for our menu interface
    while (1) {
        printf("\n===================================\n");
        printf("    INVENTORY MANAGEMENT SYSTEM    \n");
        printf("===================================\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Stock\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Terminate the system
        if (choice == 6) {
            printf("\nExiting program. Thank you!\n");
            break;
        }

        switch (choice) {
            // ===================================
            // 1. ADD NEW ITEM
            // ===================================
            case 1: {
                if (itemCount >= MAX_ITEMS) {
                    printf("\nError: Inventory space is completely full!\n");
                    break;
                }

                int newId;
                int duplicateFound = 0;

                printf("\nEnter Product ID (Integer): ");
                scanf("%d", &newId);

                // Validation check for unique ID allocation
                for (int i = 0; i < itemCount; i++) {
                    if (ids[i] == newId) {
                        duplicateFound = 1;
                        break;
                    }
                }

                if (duplicateFound) {
                    printf("\nError: An item with ID %d already exists.\n", newId);
                } else {
                    ids[itemCount] = newId;
                    printf("Enter Product Name: ");
                    scanf(" %[^\n]s", names[itemCount]); // Accepts spaces in names
                    printf("Enter Quantity: ");
                    scanf("%d", &quantities[itemCount]);
                    printf("Enter Price: ");
                    scanf("%f", &prices[itemCount]);

                    itemCount++;
                    printf("\nSuccess: Item added successfully!\n");
                }
                break;
            }

            // ===================================
            // 2. DISPLAY ALL ITEMS
            // ===================================
            case 2: {
                if (itemCount == 0) {
                    printf("\nInventory is empty. No items to display.\n");
                } else {
                    printf("\n-------------------------------------------------------------\n");
                    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
                    printf("---------------------------------------------------\n");
                    for (int i = 0; i < itemCount; i++) {
                        printf("%-10d %-25s %-10d $%-9.2f\n", ids[i], names[i], quantities[i], prices[i]);
                    }
                    printf("-------------------------------------------------------------\n");
                }
                break;
            }

            // ===================================
            // 3. SEARCH ITEM BY ID
            // ===================================
            case 3: {
                if (itemCount == 0) {
                    printf("\nInventory is empty.\n");
                    break;
                }

                int searchId, foundIndex = -1;
                printf("\nEnter the Product ID to search: ");
                scanf("%d", &searchId);

                for (int i = 0; i < itemCount; i++) {
                    if (ids[i] == searchId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("\nItem Found:\n");
                    printf("ID: %d\n", ids[foundIndex]);
                    printf("Name: %s\n", names[foundIndex]);
                    printf("Quantity: %d\n", quantities[foundIndex]);
                    printf("Price: $%.2f\n", prices[foundIndex]);
                } else {
                    printf("\nError: Item with ID %d not found.\n", searchId);
                }
                break;
            }

            // ===================================
            // 4. UPDATE ITEM STOCK
            // ===================================
            case 4: {
                if (itemCount == 0) {
                    printf("\nInventory is empty.\n");
                    break;
                }

                int updateId, foundIndex = -1;
                printf("\nEnter the Product ID to update: ");
                scanf("%d", &updateId);

                for (int i = 0; i < itemCount; i++) {
                    if (ids[i] == updateId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("\nCurrent details -> Name: %s | Current Stock: %d\n", names[foundIndex], quantities[foundIndex]);
                    printf("Enter new Quantity: ");
                    scanf("%d", &quantities[foundIndex]);
                    printf("Enter new Price: ");
                    scanf("%f", &prices[foundIndex]);
                    printf("\nSuccess: Stock records updated successfully!\n");
                } else {
                    printf("\nError: Item with ID %d not found.\n", updateId);
                }
                break;
            }

            // ===================================
            // 5. DELETE ITEM
            // ===================================
            case 5: {
                if (itemCount == 0) {
                    printf("\nInventory is empty. Nothing to delete.\n");
                    break;
                }

                int deleteId, foundIndex = -1;
                printf("\nEnter the Product ID to delete: ");
                scanf("%d", &deleteId);

                for (int i = 0; i < itemCount; i++) {
                    if (ids[i] == deleteId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    // Shift all elements after the deleted item one position leftward
                    for (int i = foundIndex; i < itemCount - 1; i++) {
                        ids[i] = ids[i + 1];
                        strcpy(names[i], names[i + 1]);
                        quantities[i] = quantities[i + 1];
                        prices[i] = prices[i + 1];
                    }
                    itemCount--; // Reduce tracking counter by one
                    printf("\nSuccess: Item deleted successfully from tracking storage!\n");
                } else {
                    printf("\nError: Item with ID %d not found.\n", deleteId);
                }
                break;
            }

            // Invalid menu choice error handling
            default:
                printf("\nInvalid selection! Please input an operational step from 1 to 6.\n");
        }
    }

    return 0;
}
