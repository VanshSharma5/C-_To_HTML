typedef struct ATTRIBUTES
{
    char style[512];
    char name[256];
    char id[256];
    char class[256];
    char value[256];

}ATTRIBUTES;

typedef struct BODY
{
    char bgcolor[256];
    char id[256];
    char class[256];
    char style[512];

}BODY;

typedef struct HEAD
{
    char title[256];
    char link[256];
}HEAD;
\
/* this are tags  */
void h(FILE* fp, char *str,short num, ATTRIBUTES attrib ) {
    fprintf(fp,"<H%d style='%s' class='%s' id='%s'>%s</H%d>",num, attrib.style, attrib.class, attrib.id, str, num);
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

void input(FILE* fp,char* type,int size,char* name) {
    fprintf(fp,"<input type=\"%s\" size=\"%d\" name=\"%s\" >", type, size, name );
}
