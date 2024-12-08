#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<limits.h>

typedef FILE* HTML;

FILE* hopen(char* file_name) {
    return fopen(file_name, "w");
}

void h(FILE* fp, char *str,short num ) {
    fprintf(fp,"<H%d>%s</H%d>",num,str,num);
}

void p(FILE* fp, char *str) {
    fprintf(fp,"<p>%s</p>",str);
}

void hr(FILE* fp) {
    fprintf(fp,"<HR>");
}

void br(FILE* fp) {
    fprintf(fp,"<BR>");
}

void printh(FILE* fp, char* str) {
    fprintf(fp, "%s", str);
}

void input(FILE* fp,char* type,int size,char* name) {
    fprintf(fp,"<input type=\"%s\" size=\"%d\" name=\"%s\" >", type, size, name );
}

void show_file(FILE* fp) {
    char BASE_DIR[PATH_MAX] ;
    short i, j;
    char ch = 'A';
    fclose(fp);
    //printf("almost there over index\n");
    if(getcwd(BASE_DIR,sizeof(BASE_DIR)) == NULL) {
        //printf("almost there inside if\n");
        perror("File not found Error !!");
    }
    else {
        printf("almost there inside else\n");
        char query[256] = "start chrome ";
        char file[16] = "/index.html";
        for(i = 13, j = 0 ; ch != '\0' ; i++ ) {
            ch = BASE_DIR[j++];
            query[i] = ch;
        }
        i--;
        for(j = 0 ; j <= 10 ; i++ ) {
            query[i] = file[j++];
        }
        //printf("%s",query);
        system(query);
    }
}
    
int main() {
    HTML f;
    int i = 0;
    f = hopen("index1.html");
    h(f,"hellow world!",2);
    hr(f);
    p(f, "this day is so great");
    br(f);
    printh(f,"<hr size=5 color=red >");
    input(f,"text",20,"value");
    br(f);
    input(f, "checkbox",15,"true");
    for( i = 0 ; i <= 10 ; i++){
        p(f, "this day is so great");
        br(f);
    }
    //printf("almost there in main \n");
    show_file(f);

}
