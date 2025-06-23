#include <stdio.h>
#include <math.h>
double PI=3.1415926;

//FELADAT 6 (És 9)
void masodofoku(double a, double b, double c){
    int sign=0.0;
    sign=b*b-4*a*c;
    if(sign>=0.0){
        double szam1=0.0;
        double szam2=0.0;
        szam1=(-b+sqrt(sign))/(2*a);
        szam2=(-b-sqrt(sign))/(2*a);
        printf("X1=%f",szam1);
        if(sign!=0){
            printf("X2=%f",szam2);
        }
    } else {
        printf("Nincs valós gyöke");}
}
int main(){
    masodofoku(1,2,10);
    return 0;
}