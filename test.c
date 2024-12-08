#include "html/basic.h"


int main() {
    HTML html;
    int i, j;
    ATTRIBUTES att_h2 = {"color:red;background-color:blue"};
    html = hopen("first.html");
    h(html,"this is first project", 1, att_h2);
    br(html);
    hr(html);
    hr(html);
    for(j = 0 ; j < 100 ; j++) {
        printh(html,"<select for='");
        printint(html,j+1);
        printh(html,"'>");
        for(i = 0 ; i <= 10 ; i++) {
            printh(html,"<option>");
            printint(html,i);
            printh(html,"</option>");
        }
        printh(html,"</select>");
    }
    show_file(html, -1);


    return 0;
}