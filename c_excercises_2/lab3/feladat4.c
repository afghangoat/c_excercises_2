#include <stdio.h>
typedef struct Pont{
    double x;
    double y;
} Pont;
int main(void) {
    Pont p1={2.2 , 1.6};
    double p2x=0.0;
    double p2y=0.0;
    printf("Adj meg egy (x,y) pontot:\nX:");
    scanf("%lf",&p2x);
    printf("\nY:");
    scanf("%lf",&p2y);
    Pont p2={p2x , p2y};
    Pont fp={(p2.x+p1.x)/2.0,(p2.y+p2.y)/2.0};
    printf("\nFP=x:%f,y:%f",fp.x,fp.y);
    return 0;
}