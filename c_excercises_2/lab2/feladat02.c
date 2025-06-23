#include <stdio.h>
 
int main(void) {
    char betu;
    while (scanf("%c", &betu) == 1)
        printf("betu='%c', betu=%d\n", betu, betu);
 
    return 0;
}
//A program bekér egy karaktert és kiírja a karaktert és az ASCII kódját
//Ha "Kilépő" karaktert kap, akkor abbahagyja a kérdezést.