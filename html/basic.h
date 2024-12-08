#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
#include<string.h>
#include "tools.h"
#include "tags_list/tags.h"

typedef FILE* HTML;
char FILE_NAME[BUFSIZ];

FILE* hopen(char file_name[]) {
    strcpy(FILE_NAME, file_name);
    FILE* file;
    file = fopen(file_name, "w");
    fprintf(file,"<!DOCTYPE html><HTML lang='en'>");
    return file;
}

void printh(FILE* fp, char* str) {
    fprintf(fp, str);
}

void printint(FILE* fp, int args) {
    fprintf(fp, "%d", args);
}

void head(FILE* fp,HEAD atrib) {
    fprintf(fp,"<HEAD> <TITLE>%s</TITLE><LINK rel='stylesheet' href='%s'></HEAD>",atrib.title, atrib.link );
}

void show_file(FILE* fp,int flag) {
    char BASE_DIR[PATH_MAX] ;
    char ch = 'A';
    fprintf(fp,"</HTML>");
    fclose(fp);
    //printf("almost there over index\n");
    if(getcwd(BASE_DIR,sizeof(BASE_DIR)) == NULL) {
        //printf("almost there inside if\n");
        perror("File not found Error !!");
    }
    else {
        char query[512] = "start chrome ";
        strcat(query,BASE_DIR);
        strcat(query,"/");
        strcat(query,FILE_NAME);
        system(query);
    }
}