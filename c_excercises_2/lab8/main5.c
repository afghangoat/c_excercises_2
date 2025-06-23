#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "debugmalloc.h"

char* beolvas() {
    char* s = (char*)malloc(sizeof(char));
    char cur = ' ';
    int index = 0;
    int size = 1;

    while (cur != '\n') {
        scanf("%c", &cur);

        if (index > size) {
            size++;
            s = (char*)realloc(s, size * sizeof(char));

        }

        s[index] = cur;
        index++;
    }

    s[index - 1] = '\0';
    return s;
}

int main(void) {
    char *c = beolvas();
    int len = strlen(c);

    for (int a = len-1; a >=0; a--) {
        printf("%c", c[a]);
    }

    free(c);
    return 0;
}
