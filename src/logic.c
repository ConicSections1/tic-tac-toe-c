#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "newgame.h"
#include "functions.h"
#include "loadgame.h"
#include "record.h"
#include "logic.h"
#include "constants.h"
#include "display.h"

// Fixed the recursive call in the draw condition and replaced it with a loop.
void game(void) {
    while (1) {
        //Sleep(10);
        //printf("\033[H"); // Clear the screen
        displaygrid();
        int value = -1; // Player number
        int winner = 0; // Winner number

        // Determine whose turn it is
        for (int i = 0; i < 2; i++) {
            if (record->turn == list[i].symbol) {
                value = i; // Update the turn value
            }
        }

        // Input handling
        int row, col;
        while (1) {
            //Sleep(10);
            printf("Player %d's turn (%c):\nEnter the row and column in 'row column' format: ", value + 1, list[value].symbol);
            char array[4];
            char ch='0';
            fgets(array, sizeof(array), stdin); // Read input
            array[strcspn(array, "\n")] = '\0'; // Remove newline if present
            
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer
            row = array[0] - '0'; // Convert char to int
            col = array[2] - '0'; // Convert char to int
            if (row < 0 || row > 2 || col < 0 || col > 2 || record->board[row][col] != ' ') {
                printf("Invalid input. Please enter a valid row and column.\n");
                //Sleep(10);
                continue;
            }
            /*if (scanf("%d %d", &row, &col) != 2 || row < 0 || row > 2 || col < 0 || col > 2 || record->board[row][col] != ' ') {
                printf("Invalid input. Please enter a valid row and column.\n");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }*/
            //Sleep(10);
            break;
        }

        // Update the board and turn
        record->board[row][col] = list[value].symbol;
        record->turn = (record->turn == list[0].symbol) ? list[1].symbol : list[0].symbol;

        // Check for winning condition
        if ((record->board[0][0] == list[value].symbol && record->board[1][1] == list[value].symbol && record->board[2][2] == list[value].symbol) ||
            (record->board[0][2] == list[value].symbol && record->board[1][1] == list[value].symbol && record->board[2][0] == list[value].symbol)) {
            winner = value + 1;
        } else {
            for (int i = 0; i < 3; i++) {
                if ((record->board[i][0] == list[value].symbol && record->board[i][1] == list[value].symbol && record->board[i][2] == list[value].symbol) ||
                    (record->board[0][i] == list[value].symbol && record->board[1][i] == list[value].symbol && record->board[2][i] == list[value].symbol)) {
                    winner = value + 1;
                    break;
                }
            }
        }

        logupdate();

        if (winner != 0) {
            printf("Player %d wins!\n", winner);
            printf("Congratulations %s!\n", list[winner - 1].name);
            update_record(winner);
            cleanup_log(); // Clear the log file
            break;
        }

        // Check for draw condition
        int draw = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (record->board[i][j] == ' ') {
                    draw = 0;
                    break;
                }
            }
            if (!draw) break;
        }

        if (draw) {
            printf("It's a draw!\n");
            update_record(0); // Update record for a draw
            cleanup_log(); // Clear the log file
            printf("Game over. Exiting...\n");
            break;
        }
        //Sleep(10);
    }
}