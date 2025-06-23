#include <stdio.h>
#include <math.h>

//FELADAT 8
int main(){
    printf("Mekkora vonolat akarsz?: ");
    int b=0;
    scanf("%d",&b);
    printf("\n+");
    for (int i = 0; i < b; i++)
    {
        printf("-");
    }
    printf("+");
    return 0;
}