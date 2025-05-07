#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"
#include "constants.h"

void logupdate(void){
    FILE* fp = fopen(LOGFILE, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(fp, "Player 1: %s Symbol: %c\n", list[0].name, list[0].symbol);
    fprintf(fp, "Player 2: %s Symbol: %c\n", list[1].name, list[1].symbol);
    fprintf(fp, "Turn: %c\n", record->turn);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            fprintf(fp, "%c ", record->board[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void logread() {
    FILE* fp = fopen(LOGFILE, "r");
    if (fp == NULL) {
        perror("Error opening file");

        return;
    }

    // Read player 1 details
    if (fscanf(fp, "Player 1: %19s Symbol: %c\n", list[0].name, &list[0].symbol) != 2) {
        perror("Error reading Player 1 details");
        fclose(fp);
        return;
    }

    // Read player 2 details
    if (fscanf(fp, "Player 2: %19s Symbol: %c\n", list[1].name, &list[1].symbol) != 2) {
        perror("Error reading Player 2 details");
        fclose(fp);
        return;
    }

    // Read the turn
    if (fscanf(fp, "Turn: %c\n", &record->turn) != 1) {
        perror("Error reading turn");
        fclose(fp);
        return;
    }

    // Read the board state
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (fscanf(fp, " %c", &record->board[i][j]) != 1) {
                perror("Error reading board state");
                fclose(fp);
                return;
            }
        }
    }

    fclose(fp);
}

void selector_loader(int a){
    if (a == 1) { // Gets input for list and record struct and calls logupdate
        printf("Please choose a name for Player 1:\n");
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer


        fgets(list[0].name, PLAYER_NAME_SIZE, stdin); // Get Player 1's name
        list[0].name[strcspn(list[0].name, "\n")] = '\0'; // Remove newline if present
        //while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer
        
        //checking for valid input
        printf("Player 1 name is %s\n", list[0].name);

        printf("Please choose a symbol for Player 1 (X or O):\n");
        char c = '0';
        while (c != 'X' && c != 'O') {
            c = getchar();
            c = toupper(c);
            if (c == 'X' || c == 'O') {
                list[0].symbol = c;
                break;
            } else {
                printf("Please choose a valid symbol (X or O):\n");
                c = '0';
            }
        }
        
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer
        //checking for symbol input
        printf("Player 1 symbol is %c\n", list[0].symbol);

        printf("Please choose a name for Player 2:\n");
        //while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer

        fgets(list[1].name, PLAYER_NAME_SIZE, stdin); // Get Player 2's name
        list[1].name[strcspn(list[1].name, "\n")] = '\0'; // Remove newline if present
        //while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer

        //Checking for valid input
        printf("Player 2 name is %s\n", list[1].name);

        // Assign Player 2's symbol
        list[1].symbol = (list[0].symbol == 'X') ? 'O' : 'X';

        //checking for symbol input
        printf("Player 2 symbol is %c\n", list[1].symbol);

        printf("Player 1: %s Symbol: %c\n", list[0].name, list[0].symbol);
        printf("Player 2: %s Symbol: %c\n", list[1].name, list[1].symbol);
        printf("Turn: %c\n", list[0].symbol);

        // Initialize the board
        record->turn = list[0].symbol;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                record->board[i][j] = ' ';
            }
        }

        logupdate();
    }
    else if (a == 2) {
        logread();
        //return;
    return;
    }
}