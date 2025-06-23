#include <stdio.h>
#include <stdio.h>
void base_to(int num,int tobase){
    if(num<tobase){
        printf("%d",num);
        return;
    }
    base_to(num/tobase,tobase);
    base_to(num%tobase,tobase);
}
void ezres_szam(int num){
    if(num<1000){
        printf("%d ",num);
        return;
    }
    ezres_szam(num/1000);
    ezres_szam(num%1000);
}
int main(void) {
    base_to(10,2);
    printf("\n");
    ezres_szam(888110);
    return 0;
}