#include <stdio.h>
 
int reset_a(){
    return 1;
}
int inc_a(int b){
    return b++;
}
int neg_a(int b){
    return (b*-1);
}
int x2a(int b){
    return (b*2);
}
int main() {
    int a=1;
    int ans=0;
    do{
        printf("Jelenleg A: %d\n",a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
       "1. Hozzaad 1-et\n"
       "2. Megforditja az elojelet\n"
       "3. Szorozza 2-vel\n"
       "9. Kilepes\n");
       scanf("%d",&ans);
       switch (ans)
       {
       case 0:
        a=reset_a();
        break;
       case 1:
        a=inc_a(a);
        break;
        case 2:
        a=neg_a(a);
        break;
        case 3:
            a=x2a(a);
            break;
       default:
        break;
       }
    }while(ans!=9);
 
    return 0;
}
