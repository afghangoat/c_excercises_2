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
    }
}
int main(void) {
    char a[]="aaaa";
    print_a(a,0);
    return 0;
}