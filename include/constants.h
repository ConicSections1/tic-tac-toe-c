#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>
#include <stdlib.h>

#define LOGFILE "log.txt"
#define RECFILE "record.txt"
#define PLAYER_NAME_SIZE 20
#define BOARD_SIZE 3

typedef struct {
    char name[PLAYER_NAME_SIZE];
    char symbol;
} player;

typedef struct {
    char turn;
    char board[BOARD_SIZE][BOARD_SIZE];
} rec;

extern player *list;
extern rec *record;
void initialize_globals(void);
void cleanup_globals(void);
void cleanup_log(void);

#endif