#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "constants.h"
#include "display.h"

void displaygrid(void){
    printf("_________________\n");
    for(int i=0; i<3; i++){
        printf("||");
        for (int j=0; j<3; j++){
            printf(" %c ||", record->board[i][j]);
        }
        printf("\n");
        printf("_________________\n");
    }
}