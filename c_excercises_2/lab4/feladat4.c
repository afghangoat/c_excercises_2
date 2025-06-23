#include <stdio.h>
#include <math.h>a
 
int main(void) {
    signed int ketto=1;
    for(int i=0;i<64;i++){
        ketto=ketto<<1;
        printf("%d\n",ketto);
        if(ketto==0){
            printf("A kapott érték %d bites.",(i+1));
            break;
        }
    }
    return 0;
}