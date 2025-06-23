#include <stdio.h>
#include <math.h>
double kob(double a){
    return a*a*a;
}
double abszolut(double a){
    if(a>=0){
        return a;
    }
    return -a;
}
int main(void) {
    //a, a3, absa, sina
    for(double i=-1.0;i<1.0;i+=0.1){
        printf("a=%f a^3=%f |a|=%f sin(a)=%f\n",i,kob(i),abszolut(i),sin(i));
    }
    return 0;
}