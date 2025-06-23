#include <stdio.h>
#include <math.h>
double PI=3.1415926;

//FELADAT 5
int main(){
    double magas=0.0;
    double atmero=0.0;
    printf("milyen magas:\n");
    scanf("%lf",&magas);
    printf("milyen atmero:\n");
    scanf("%lf",&atmero);
    //r^2*PI*2+m*r*2*PI
    double radi=0.0;
    radi=atmero/2;
    double area=0.0;
    area=radi*radi*PI*2+magas*radi*2*PI;
    printf("%f|\n",radi);
    area/=2;
    printf("Ennyi veder festek kell:\n");
    printf("%f",area);
}