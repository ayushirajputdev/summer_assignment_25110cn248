#include <stdio.h>
#include <string.h>

// Define a structure to store book data
struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued; // 0 = Available, 1 = Issued
};

int main() {
    struct Book library[100]; // Array holding up to 100 books
    int book_count = 0;       // Track total books in library
    int choice;               // Track user menu selection

    // Main program loop
    while (1) {
        // Display Menu System
        printf("\n==================================\n");
        printf("   MINI LIBRARY MANAGEMENT SYSTEM \n");
        printf("==================================\n");
        printf("1. Add a New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit System\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        // Terminate program cleanly
        if (choice == 6) {
            printf("\nExiting library system. Goodbye!\n");
            break;
        }

        // Process options without custom user functions
        switch (choice) {
            case 1: // Add a New Book
                if (book_count >= 100) {
                    printf("\nError: Library database is full!\n");
                } else {
                    int duplicate = 0;
                    printf("\nEnter Unique Book ID (Integer): ");
                    scanf("%d", &library[book_count].id);

                    // Check for unique ID constraint
                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == library[book_count].id) {
                            duplicate = 1;
                            break;
                        }
                    }

                    if (duplicate) {
                        printf("\nError: A book with this ID already exists!\n");
                    } else {
                        // Clear remaining newline from input buffer
                        while (getchar() != '\n'); 

                        printf("Enter Book Title: ");
                        fgets(library[book_count].title, sizeof(library[book_count].title), stdin);
                        library[book_count].title[strcspn(library[book_count].title, "\n")] = 0; // Strip newline

                        printf("Enter Author Name: ");
                        fgets(library[book_count].author, sizeof(library[book_count].author), stdin);
                        library[book_count].author[strcspn(library[book_count].author, "\n")] = 0; // Strip newline

                        library[book_count].is_issued = 0; // Default status is Available
                        book_count++;
                        printf("\nSuccess: Book added successfully!\n");
                    }
                }
                break;

            case 2: // Display All Books
                if (book_count == 0) {
                    printf("\nThe library contains no books right now.\n");
                } else {
                    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
                    printf("-------------------------------------------------------------------------\n");
                    for (int i = 0; i < book_count; i++) {
                        printf("%-10d %-30s %-25s %-15s\n", 
                               library[i].id, 
                               library[i].title, 
                               library[i].author, 
                               (library[i].is_issued == 1) ? "Issued" : "Available");
                    }
                }
                break;

            case 3: // Search Book by ID
                if (book_count == 0) {
                    printf("\nThe library contains no books to search.\n");
                } else {
                    int search_id, found = 0;
                    printf("\nEnter Book ID to search: ");
                    scanf("%d", &search_id);

                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == search_id) {
                            printf("\n--- Book Found ---\n");
                            printf("ID: %d\n", library[i].id);
                            printf("Title: %s\n", library[i].title);
                            printf("Author: %s\n", library[i].author);
                            printf("Status: %s\n", (library[i].is_issued == 1) ? "Issued" : "Available");
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nError: Book ID %d not found.\n", search_id);
                    }
                }
                break;

            case 4: // Issue a Book
                if (book_count == 0) {
                    printf("\nNo books available to issue.\n");
                } else {
                    int issue_id, found = 0;
                    printf("\nEnter Book ID to issue: ");
                    scanf("%d", &issue_id);

                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == issue_id) {
                            found = 1;
                            if (library[i].is_issued == 1) {
                                printf("\nError: This book is already issued to someone else.\n");
                            } else {
                                library[i].is_issued = 1;
                                printf("\nSuccess: Book '%s' has been successfully issued.\n", library[i].title);
                            }
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nError: Book ID %d does not exist.\n", issue_id);
                    }
                }
                break;

            case 5: // Return a Book
                if (book_count == 0) {
                    printf("\nNo books are currently managed by this library.\n");
                } else {
                    int return_id, found = 0;
                    printf("\nEnter Book ID to return: ");
                    scanf("%d", &return_id);

                    for (int i = 0; i < book_count; i++) {
                        if (library[i].id == return_id) {
                            found = 1;
                            if (library[i].is_issued == 0) {
                                printf("\nError: This book was never issued; it's already in the library.\n");
                            } else {
                                library[i].is_issued = 0;
                                printf("\nSuccess: Book '%s' returned successfully.\n", library[i].title);
                            }
                            break;
                        }
                    }
                    if (!found) {
                        printf("\nError: Book ID %d does not match our records.\n", return_id);
                    }
                }
                break;

            default:
                printf("\nInvalid Selection! Please choose an option between 1 and 6.\n");
        }
    }

    return 0;
}
