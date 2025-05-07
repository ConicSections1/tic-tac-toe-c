#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "functions.h"
#include "loadgame.h"
#include "record.h"
#include "logic.h"
#include "constants.h"


void loadgame(void){
    selector_loader(2); // Call selector_loader to load the game
    if (record->turn != 'X' && record->turn != 'O') {
        printf("No game data found. Please start a new game.\n");
        return;
    }
    game();

    return;
}