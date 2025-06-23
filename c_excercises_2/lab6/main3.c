#include <stdio.h>

int main(void){
    char nev[]="Imre";
    int iter=0;
    while(nev[iter]!='\0'){
        printf("%c\n",nev[iter]);
        iter++;
    }
    return 0;
}