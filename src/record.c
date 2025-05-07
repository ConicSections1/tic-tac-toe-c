#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "record.h"
#include "constants.h"


void readr(void){
    FILE* fp = fopen(RECFILE, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    char ch='o';
    while (ch!=EOF){
        ch = fgetc(fp);
        if (ch!=EOF){
            printf("%c", ch);
        }
    }
}

void update_record(int winner){
    if (winner < 0 || winner > 2) {
        printf("Invalid winner number: %d\n", winner);
        return;
    }
    else if (winner ==1 || winner ==2){
        FILE* fp = fopen(RECFILE, "a+");
        if (fp == NULL) {
            perror("Error opening file");
            return;
        }
        if (winner == 1) {
            fprintf(fp, "%s wins against %s!\n", list[0].name, list[1].name);
        } else if (winner == 2) {
            fprintf(fp, "%s wins against %s!\n", list[1].name, list[0].name);
        }
         //fprintf(fp, "%s wins against %s!\n", list[winner-1].name, list[winner-2].name);
         //fprintf(fp, "%s wins against %s!\n", list[winner-2].name, list[winner-1].name);
         //fprintf(fp, "%s wins against %s!\n", list[0].name, list[1].name);
         //fprintf(fp, "%s wins against %s!\n", list[1].name, list[0].name);
        //fprintf(fp, "%s wins against %s!\n", list[winner-1].name, list[winner-2].name);
        fclose(fp);
    }
    else {
        FILE* fp = fopen(RECFILE, "a+");
        if (fp == NULL) {
            perror("Error opening file");
            return;
        }
        fprintf(fp, "%s draws with %s!\n", list[0].name, list[1].name);
        fclose(fp);
    }
}