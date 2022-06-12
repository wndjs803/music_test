#include "../include/textfilewriter.h"
#include "../include/linkedlist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void create_music_titles(FILE* stream) {
    int NUM_OF_MUSIC = 0;
    static char str[10][MAX_TITLE_SIZE];
    fscanf(stream, "%d\n", &NUM_OF_MUSIC);

    for (int i = 0; i < NUM_OF_MUSIC; i++) {
        fscanf(stream, "%s", str[i]);
        append_left(strlen(str[i]), str[i]);
    }
}


void read_file(char* file_name) {
    FILE *fp;
    fp = fopen(file_name, "r");
    create_music_titles(fp);
    fclose(fp);
}
void write_file(char* file_name) {
    FILE *fp;
    fp = fopen(file_name, "w");

    print_file(fp);

    fclose(fp);
}
