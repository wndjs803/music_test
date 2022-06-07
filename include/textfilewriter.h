#ifndef MUSIC_TEXTFILEWRITER_H
#define MUSIC_TEXTFILEWRITER_H
#include <stdio.h>

#define MAX_TITLE_SIZE 50

void create_music_titles(FILE* stream);

void read_file(char* file_name);

void write_file(char* file_name);
#endif //MUSIC_TEXTFILEWRITER_H
