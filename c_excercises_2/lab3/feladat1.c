#include <stdio.h>
#include <stdbool.h>
 
int main(void) {
    double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
    bool indexek[10]={false,false,false,false,false,false,false,false,false,false};
    /* Az eredeti tömb kiírása */
    printf("Összesen %d szám van.\n", 10);
    for (int i = 0; i < 10; ++i){
        printf("[%d]=%g ", i, szamok[i]);
        printf("\n\n");
 
    /* Negatívak indexeinek kigyűjtése */
        if(szamok[i]<0.0){
            indexek[i]=true;
        }
    }
    printf("A negatív számok:\n");
    /* Negatívak kiírása */
    for(int i=0;i<10;i++){
        if(indexek[i]==true){
            printf("[%d]=%d ",i,szamok[i]);
        }
    }
    return 0;
}