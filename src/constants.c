#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

player *list = NULL;
rec *record = NULL;

void initialize_globals() {
    list = (player*)calloc(2, sizeof(player));
    if (list == NULL) {
        perror("Failed to allocate memory for list");
        exit(EXIT_FAILURE);
    }

    record = (rec*)calloc(1, sizeof(rec));
    if (record == NULL) {
        perror("Failed to allocate memory for record");
        free(list); // Free previously allocated memory
        exit(EXIT_FAILURE);
    }
}

void cleanup_globals() {
    if (list != NULL) {
        free(list);
        //list = NULL;
    }

    if (record != NULL) {
        free(record);
        //record = NULL;
    }
}

void cleanup_log(void){
    FILE* fp = fopen(LOGFILE, "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fclose(fp);
    return;
}