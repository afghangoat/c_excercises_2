#include <stdio.h>

int main(void)
{
    int n, c, k;
    n=0;
    printf("Kérek egy számot aminek megmutatom a 2.es számrendszer beli ábrázolását.\n\n");
    scanf("%d", &n);

    for (c = 31; c >= 0; c--)
    {
        k = n >> c;

        if (k & 1)
            printf("1");
        else
            printf("0");
        
        printf("\n");
    } 
    return 0;
}