#include <stdio.h>
void kocka_ter(double a, double* ker, double* ter){
    *ker=6*a*a;
    *ter=a*a*a;
}
int main(void){
    double aker;
    double ater;
    kocka_ter(2.7,&aker,&ater);
    printf("%lf %lf",aker,ater);
    return 0;
}