#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100


struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

int main() {
    struct Book library[MAX_BOOKS];
    int book_count = 0;
    int choice;
    
    int target_id;
    int found;
    int i, j;

    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Delete a Book");
        printf("\n7. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-7): ");
        
       
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid selection input type.");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: 
                if (book_count >= MAX_BOOKS) {
                    printf("\nError: The library inventory is full!\n");
                    break;
                }

                printf("\nEnter Book ID (Integer): ");
                scanf("%d", &target_id);

                
                found = 0;
                for (i = 0; i < book_count; i++) {
                    if (library[i].id == target_id) {
                        found = 1;
                        break;
                    }
                }

                if (found == 1) {
                    printf("\nError: A book with ID %d already exists.\n", target_id);
                } else {
                    library[book_count].id = target_id;
                    
                    
                    getchar(); 

                    printf("Enter Book Title: ");
                    fgets(library[book_count].title, sizeof(library[book_count].title), stdin);
                    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0'; // Remove newline

                    printf("Enter Author Name: ");
                    fgets(library[book_count].author, sizeof(library[book_count].author), stdin);
                    library[book_count].author[strcspn(library[book_count].author, "\n")] = '\0'; // Remove newline

                    library[book_count].is_issued = 0; // Default status is available
                    book_count++;
                    printf("\nSuccess: Book added successfully!\n");
                }
                break;

            case 2: 
                if (book_count == 0) {
                    printf("\nThe library inventory is currently empty.\n");
                    break;
                }

                printf("\n%-10s %-30s %-25s %-15s", "Book ID", "Title", "Author", "Status");
                printf("\n--------------------------------------------------------------------------------");
                for (i = 0; i < book_count; i++) {
                    printf("\n%-10d %-30s %-25s %-15s", 
                        library[i].id, 
                        library[i].title, 
                        library[i].author, 
                        (library[i].is_issued == 1) ? "Issued" : "Available");
                }
                printf("\n");
                break;

            case 3: 
                if (book_count == 0) {
                    printf("\nThe library inventory is empty.\n");
                    break;
                }

                printf("\nEnter Book ID to search: ");
                scanf("%d", &target_id);

                found = 0;
                for (i = 0; i < book_count; i++) {
                    if (library[i].id == target_id) {
                        printf("\n--- Book Found ---");
                        printf("\nID: %d", library[i].id);
                        printf("\nTitle: %s", library[i].title);
                        printf("\nAuthor: %s", library[i].author);
                        printf("\nStatus: %s\n", (library[i].is_issued == 1) ? "Issued" : "Available");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("\nBook with ID %d was not found.\n", target_id);
                }
                break;

            case 4: 
                printf("\nEnter Book ID to issue: ");
                scanf("%d", &target_id);

                found = 0;
                for (i = 0; i < book_count; i++) {
                    if (library[i].id == target_id) {
                        found = 1;
                        if (library[i].is_issued == 1) {
                            printf("\nSorry, this book is already issued to someone else.\n");
                        } else {
                            library[i].is_issued = 1;
                            printf("\nSuccess: Book issued successfully!\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("\nBook with ID %d does not exist.\n", target_id);
                }
                break;

            case 5: 
                printf("\nEnter Book ID to return: ");
                scanf("%d", &target_id);

                found = 0;
                for (i = 0; i < book_count; i++) {
                    if (library[i].id == target_id) {
                        found = 1;
                        if (library[i].is_issued == 0) {
                            printf("\nThis book is already inside the library inventory.\n");
                        } else {
                            library[i].is_issued = 0;
                            printf("\nSuccess: Book returned successfully!\n");
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("\nBook with ID %d does not belong to this library.\n", target_id);
                }
                break;

            case 6: 
                printf("\nEnter Book ID to remove: ");
                scanf("%d", &target_id);

                found = 0;
                for (i = 0; i < book_count; i++) {
                    if (library[i].id == target_id) {
                        found = 1;
                        
                        for (j = i; j < book_count - 1; j++) {
                            library[j] = library[j + 1];
                        }
                        book_count--;
                        printf("\nSuccess: Book removed from system.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("\nBook with ID %d was not found.\n", target_id);
                }
                break;

            case 7: 
                printf("\nExiting Library System. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid Choice! Please pick an option between 1 and 7.\n");
        }
    }
    return 0;
}
