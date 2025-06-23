#include <stdio.h>
int fin_tomb(double what,double tomb[],int meret){
    for(int i=0;i<meret;i++){
        if(tomb[i]==what){
            return i;
        }
    }
    return -1;
}
int main(void){
    double atomb[5]={4.2,2.3,1.2,1.2,1.2};
    int meret=5;
    int it=fin_tomb(4.2,&atomb,meret);
    if(it==-1){
        printf("Nincs ilyen elem!");
    } else {
        printf("%d",it);
    }
    return 0;
}