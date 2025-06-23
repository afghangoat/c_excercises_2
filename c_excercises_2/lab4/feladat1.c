#include <stdio.h>
#include <math.h>
 
int main(void) {
    printf("1. %f\n", 1.23456789123456789123456789e40);
    printf("2. %g\n", 1e40);
    printf("3. %s\n", 1e3+1 == 1e3 ? "igaz" : "hamis");
    printf("4. %s\n", 1e30+1 == 1e30 ? "igaz" : "hamis");
    printf("5. %g\n", pow(10, 40) / pow(10, -40));
    printf("6. %g\n", powf(10, 40) / powf(10, -40));
 
    return 0;
}
//az 1. sort floatként írjuk ki.
//a 2, sort a kegrövidebb formába azaz normál alakba írjuk ki.
//A 3. sor azért igaz mert a lebegőpontosan komparálva még meg lehet különbötetni, hogy a 2 számnem egyenlő
//a 4. sor azért hamis, mert akkorák a számok, hogy nem lehet pontotsan elmenteni a 2 különböző számot, így azok ugyanúgy vannak ábrázolva.
//Az 5. sort megint a legrövidebb, normál alakban ábrázoljuk
// A 6. sor végtelen lesz, mert a 10^-40-en már nullaként lesz értelmezve, mert a float nem tud olyan kicsi számot eltárolni