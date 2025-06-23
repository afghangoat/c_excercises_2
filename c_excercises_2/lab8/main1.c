#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n=0;
    printf("Hány szmáot szeretnél beolvasni?:\n");
    scanf("%d",&n);
    double *szamok= (double*) malloc(sizeof(double)*n);
    for(int i=0;i<n;i++){
        double v=0.0;
        scanf("%lf",&v);
        szamok[i]=v;
    }
    for(int i=0;i<n;i++){
        printf("%lf",szamok[n-i-1]);
    }
    return 0;
}
