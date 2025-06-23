#include <stdio.h>
#include <stdbool.h>
bool maganhangzo(char a){
    switch(a){
        case 'a':case 'e':case 'i':case 'o':case 'u':
            return true;
    }
    return false;
}
int main(void) {
    char c;
    while (scanf("%c", &c) != EOF) {
        if (maganhangzo(tolower(c))==true)
            printf("%cv%c", c, c);
        else
            printf("%c", c);
    }
 
    return 0;
}