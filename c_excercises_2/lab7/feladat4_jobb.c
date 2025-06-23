#include <stdio.h>
#include <stdio.h>
 
void print_a(char tomb[],int iter){
    if(tomb[iter]=='\0'){
        return;
    }
    printf("%c",tomb[iter]);
    print_a(tomb,(iter+1));
}
void print_b(char tomb[]){
    int iter=0;
    while(tomb[iter]!='\0'){
        printf("%c",tomb[iter]);
        iter++;
    }
}
void print_bh(char tomb[],int meret){
    int iter=0;
    char rev[meret];
    while(tomb[iter]!='\0'){
        rev[meret-iter]=tomb[iter];
        iter++;
    }
    printf("%s",tomb);
}
void print_ah(char tomb[],int iter,int meret){
    if(meret-tomb[iter]=='\0'){
        return;
    }
    printf("%c",tomb[iter]-meret);
    print_ah(tomb,(iter+1),meret);
}
int main(void) {
    char a[]="aaaa";
    print_a(a,0);
    return 0;
}