#include <stdio.h>

void checkszam(int a){
    for (int c = 31; c >= 0; c--)
    {
        int k = a >> c;

        if (k & 1)
            printf("#");
        else
            printf(" ");
        

        
    }
    printf("\n");
}

int main(void)
{
    unsigned long szamok[8] = { 129, 130,132,136,16+128,32+128,64, 128 };
    //Ez egy V betűt ír ki.
    //unsigned long szamok[8] = { 0U, 1931988508U, 581177634U, 581374240,581177632U, 581177634U, 1919159836U, 0U };
    for(int i=0;i<8;i++){
        checkszam(szamok[i]);
        szamok[i] = szamok[i] & 65535;
    }
    
    return 0;
}