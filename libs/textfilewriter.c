#include "textfilewriter.h"

void create_music_titles(FILE* stream) {
	char buffer[MAX_TITLE_SIZE] = { 0, };
	char w_buffer[MAX_TITLE_SIZE] = { 0, };

	fread(buffer, 1, MAX_TITLE_SIZE, stream);
	int j = 0;
	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == ' ') {
			w_buffer[j] = '\0';
			//append_left
			append_left(j - 1, w_buffer);
			//clear w_buffer
			j = 0;
			continue;
		}
		w_buffer[j] = buffer[i];
		j++;
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
