#include <stdio.h>

int main(){
    int n=1;
    int a=1;
    int tomb[]={25,69,54,8,77,6,29,10,3,98};
    printf("A tömb: ");
    int min=tomb[0];
    int mini=0;
    for(int i=0;i<10;i++) {
        if(tomb[i]<min){
            min=tomb[i];
            mini=i;
        }
    }
    for(int i=0;i<10;i++) {
        
        if(mini==i){
            printf("MIN");
        }
        printf("[%d]=%d ",i,tomb[i]);
    }
    printf("\nA minimum: %d | A legkisebb index: %d",min,mini);
    return 0;
}
