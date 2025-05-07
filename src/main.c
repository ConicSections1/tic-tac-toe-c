#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "newgame.h"
#include "functions.h"
#include "loadgame.h"
#include "record.h"
#include "logic.h"
#include "constants.h"
#include "display.h"

int main(){
    printf("Welcome to the Game!\n");
    printf("Choose an option:\n");
    initialize_globals(); // Initialize global variables
    int choice = 0;

    while (choice != 4) {
        printf("1. New Game\n");
        printf("2. Load Game\n");
        printf("3. View Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        char ch = getchar();
        choice = ch - '0'; // Convert char to int
        //while (getchar() != '\n'); // Clear the input buffer

        switch (choice) {
            case 1:
                newgame();
                cleanup_globals(); // Clean up global variables
                cleanup_log(); // Clean up log file
                //printf("\033[H");
                break;
            case 2:
            
                loadgame();
                while (getchar() != '\n' && getchar() !=EOF); // Clear the input buffer
                cleanup_globals(); // Clean up global variables
                cleanup_log(); // Clean up log file
                //printf("\033[H");
                break;
            case 3:
                readr();
                while (getchar() != '\n' && getchar() !=EOF); // Clear the input buffer
                printf("\n\n\n\n");
                cleanup_globals(); // Clean up global variables
                cleanup_log(); // Clean up log file
                //printf("\033[H");
                break;
            case 4:
                printf("Exiting the game. Goodbye!\n");
                //printf("\033[H");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                while (getchar() != '\n' && getchar() !=EOF); // Clear the input buffer
                //printf("\033[H");
                break;
        }
    }
    cleanup_globals(); // Clean up global variables
    return 0;
}