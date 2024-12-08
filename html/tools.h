#include<stdio.h>
#define MAX_BUFFER 1024

void read_line(FILE* fp, char buffer[]) {
    char ch = 'A';
    short i = -1;
    while (ch != '\n' && i < MAX_BUFFER) {
        ch = fgetc(fp);
        buffer[++i] = ch;
    }
}

void read_word(FILE* fp, char buffer[]) {
    char ch = 'A';
    short i = -1;
    while (ch != ' ' && i < BUFSIZ) {
        ch = fgetc(fp);
        buffer[++i] = ch;
    }
}