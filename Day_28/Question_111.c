#include <stdio.h>
#include <string.h>

int main() {
    // Configuration
    int total_seats = 10;
    
    // Arrays tracking seat availability and customer names
    int seat_status[10] = {0}; // 0 = Available, 1 = Booked
    char passenger_names[10][50];
    
    // Control variables
    int choice;
    int seat_num;
    int loop_control = 1;
    int i; // Iterator for loops

    printf("=== Welcome to the Ticket Booking System ===\n");

    // Main program loop running without external execution threads or functions
    while (loop_control == 1) {
        printf("\n-----------------------------------\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. Exit System\n");
        printf("-----------------------------------\n");
        printf("Enter your choice (1-4): ");
        
        // Input validation protection
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. System shutting down securely.\n");
            break;
        }

        switch (choice) {
            case 1:
                // View Layout
                printf("\n--- Seating Map Status ---\n");
                for (i = 0; i < total_seats; i++) {
                    if (seat_status[i] == 0) {
                        printf("[ Seat %d : AVAILABLE ]\n", i + 1);
                    } else {
                        printf("[ Seat %d : BOOKED by %s ]\n", i + 1, passenger_names[i]);
                    }
                }
                break;

            case 2:
                // Book Ticket
                printf("\nEnter desired seat number (1-10): ");
                scanf("%d", &seat_num);

                // Validation bounds check
                if (seat_num < 1 || seat_num > total_seats) {
                    printf("Error: Invalid seat selection. Choose between 1 and 10.\n");
                } 
                else if (seat_status[seat_num - 1] == 1) {
                    printf("Error: Seat %d is already booked!\n", seat_num);
                } 
                else {
                    // Update index array matching real numbers to zero-index indicators
                    seat_status[seat_num - 1] = 1;
                    printf("Enter passenger name (No spaces): ");
                    scanf("%s", passenger_names[seat_num - 1]);
                    printf("Success: Seat %d has been successfully booked for %s!\n", seat_num, passenger_names[seat_num - 1]);
                }
                break;

            case 3:
                // Cancel Ticket
                printf("\nEnter seat number to cancel reservation (1-10): ");
                scanf("%d", &seat_num);

                // Validation bounds check
                if (seat_num < 1 || seat_num > total_seats) {
                    printf("Error: Invalid seat choice.\n");
                } 
                else if (seat_status[seat_num - 1] == 0) {
                    printf("Notice: This seat is already empty.\n");
                } 
                else {
                    // Clear records natively
                    seat_status[seat_num - 1] = 0;
                    printf("Success: Reservation for seat %d (Passenger: %s) has been cancelled.\n", seat_num, passenger_names[seat_num - 1]);
                    strcpy(passenger_names[seat_num - 1], ""); // Wipe layout record
                }
                break;

            case 4:
                // Terminate operation natively without using exit functions
                printf("\nThank you for using the Ticket Booking System. Goodbye!\n");
                loop_control = 0; 
                break;

            default:
                printf("Error: Option unrecognised. Please pick a number from 1 to 4.\n");
                break;
        }
    }

    return 0;
}
