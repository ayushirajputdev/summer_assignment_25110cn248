#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define the contact template structure
struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contact_count = 0;
    int choice;
    FILE *file;

    // Temporary variables needed for operations due to no helper functions
    char search_name[50];
    int found_index;
    int i;

    // 1. INITIALIZATION: Load existing records from local text file storage
    file = fopen("contacts.txt", "r");
    if (file != NULL) {
        // Read records sequentially until end of file or max array size
        while (contact_count < MAX_CONTACTS && 
               fscanf(file, " %49[^,],%19[^,],%49[^\n]\n", 
                      contacts[contact_count].name, 
                      contacts[contact_count].phone, 
                      contacts[contact_count].email) == 3) {
            contact_count++;
        }
        fclose(file);
    }

    // 2. MAIN CONSOLE LOOP
    while (1) {
        printf("\n==================================\n");
        printf("    CONTACT MANAGEMENT SYSTEM    \n");
        printf("==================================\n");
        printf("1. Add New Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact By Name\n");
        printf("4. Edit Existing Contact\n");
        printf("5. Delete A Contact\n");
        printf("6. Exit System\n");
        printf("----------------------------------\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nError: Invalid numeric selection.\n");
            // Clear input buffer stream to prevent infinite looping
            while (getchar() != '\n');
            continue;
        }
        // Consume trailing newline character left by scanf
        getchar(); 

        // 3. MONOLITHIC FLOW ROUTING
        if (choice == 1) {
            // === CREATE OPERATION ===
            if (contact_count >= MAX_CONTACTS) {
                printf("\nError: Storage is full. Cannot add more records.\n");
            } else {
                printf("\nEnter Contact Details:\n");
                printf("Name: ");
                fgets(contacts[contact_count].name, sizeof(contacts[contact_count].name), stdin);
                contacts[contact_count].name[strcspn(contacts[contact_count].name, "\n")] = '\0'; // Strip trailing newline

                printf("Phone: ");
                fgets(contacts[contact_count].phone, sizeof(contacts[contact_count].phone), stdin);
                contacts[contact_count].phone[strcspn(contacts[contact_count].phone, "\n")] = '\0';

                printf("Email: ");
                fgets(contacts[contact_count].email, sizeof(contacts[contact_count].email), stdin);
                contacts[contact_count].email[strcspn(contacts[contact_count].email, "\n")] = '\0';

                contact_count++;
                printf("\nSuccess: New contact recorded locally.\n");
            }

        } else if (choice == 2) {
            // === READ OPERATION ===
            if (contact_count == 0) {
                printf("\nNo contact records found.\n");
            } else {
                printf("\n%-5s %-25s %-15s %-25s\n", "S.No", "Name", "Phone", "Email");
                printf("------------------------------------------------------------------------\n");
                for (i = 0; i < contact_count; i++) {
                    printf("%-5d %-25s %-15s %-25s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
                }
            }

        } else if (choice == 3) {
            // === SEARCH OPERATION ===
            if (contact_count == 0) {
                printf("\nNo contact records available to query.\n");
            } else {
                printf("\nEnter target contact name to find: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = '\0';

                found_index = -1;
                for (i = 0; i < contact_count; i++) {
                    if (strcasecmp(contacts[i].name, search_name) == 0) {
                        found_index = i;
                        break;
                    }
                }

                if (found_index != -1) {
                    printf("\n--- Match Located ---\n");
                    printf("Name  : %s\n", contacts[found_index].name);
                    printf("Phone : %s\n", contacts[found_index].phone);
                    printf("Email : %s\n", contacts[found_index].email);
                } else {
                    printf("\nResult: No contact profile matches '%s'.\n", search_name);
                }
            }

        } else if (choice == 4) {
            // === UPDATE OPERATION ===
            if (contact_count == 0) {
                printf("\nNo contacts stored to edit.\n");
            } else {
                printf("\nEnter contact name you want to update: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = '\0';

                found_index = -1;
                for (i = 0; i < contact_count; i++) {
                    if (strcasecmp(contacts[i].name, search_name) == 0) {
                        found_index = i;
                        break;
                    }
                }

                if (found_index != -1) {
                    printf("\nModifying record profile [%s]:\n", contacts[found_index].name);
                    
                    printf("Enter New Name: ");
                    fgets(contacts[found_index].name, sizeof(contacts[found_index].name), stdin);
                    contacts[found_index].name[strcspn(contacts[found_index].name, "\n")] = '\0';

                    printf("Enter New Phone: ");
                    fgets(contacts[found_index].phone, sizeof(contacts[found_index].phone), stdin);
                    contacts[found_index].phone[strcspn(contacts[found_index].phone, "\n")] = '\0';

                    printf("Enter New Email: ");
                    fgets(contacts[found_index].email, sizeof(contacts[found_index].email), stdin);
                    contacts[found_index].email[strcspn(contacts[found_index].email, "\n")] = '\0';

                    printf("\nSuccess: Profile changes compiled successfully.\n");
                } else {
                    printf("\nResult: Record profile '%s' not found.\n", search_name);
                }
            }

        } else if (choice == 5) {
            // === DELETE OPERATION ===
            if (contact_count == 0) {
                printf("\nNo records available to delete.\n");
            } else {
                printf("\nEnter target contact name to delete: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = '\0';

                found_index = -1;
                for (i = 0; i < contact_count; i++) {
                    if (strcasecmp(contacts[i].name, search_name) == 0) {
                        found_index = i;
                        break;
                    }
                }

                if (found_index != -1) {
                    // Shift trailing array indexes leftward to overwrite deleted target
                    for (i = found_index; i < contact_count - 1; i++) {
                        contacts[i] = contacts[i + 1];
                    }
                    contact_count--;
                    printf("\nSuccess: Profile purged from volatile memory.\n");
                } else {
                    printf("\nResult: No matching contact located.\n");
                }
            }

        } else if (choice == 6) {
            // === SAVE AND TERMINATE EXITS ===
            file = fopen("contacts.txt", "w");
            if (file != NULL) {
                for (i = 0; i < contact_count; i++) {
                    fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
                }
                fclose(file);
                printf("\nData successfully synced to 'contacts.txt'.\n");
            } else {
                printf("\nWarning: Execution system failed to cache backup changes.\n");
            }
            printf("Shutting down cleanly. Goodbye!\n");
            break;

        } else {
            printf("\nError: Please make a selection matching numbers 1 through 6.\n");
        }
    }

    return 0;
}
