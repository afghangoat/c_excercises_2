#include <stdio.h>
#include <string.h>
char[] trim(char[] what){
    char new[100];
    int ir=0;
    int index =0;
    int index2=strlen(what);
    while(what[index]!=' '){
        index++;
    }
    for(int i=index2-1;i>1;i--){
        index2--;
        if(what[i]!=' '){
            break;
        }
    }
    let curindex=0;
    for(int i=index;i<index2;i++){
        new[curindex]=what[i];
        curindex++;
    }
    new[curindex+1]='\0';
    return new;
}
int main(void){
    char nev[]="   Imre  ";
    int iter=0;
    while(nev[iter]!='\0'){
        printf("%c\n",nev[iter]);
        iter++;
    }
    return 0;
}