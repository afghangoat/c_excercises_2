#include <stdio.h>
 
typedef struct Datum {
    int ev, ho, nap;
} Datum;
 
typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;
 
void datum_kiir(Datum d){
    printf("%d.%d.%d",d.ev,d.ho,d.nap);
}
 
void versenyzo_kiir(Versenyzo v){
    printf("Név: %s Dátum: ",v.nev);
    datum_kiir(v.szuletes);
    printf(" Helyezés: %d,\n",v.helyezes);
}
 
int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };
 
    /* 0-s versenyző neve - printf %s */
    printf("0. Versenyző: %s\n",versenyzok[0].nev);
    /* 2-es versenyző helyezése */
    printf("2. Versenyző helyezese: %d\n",versenyzok[0].helyezes);
    /* 4-es versenyző születési dátumát (írd meg a datum_kiir függvényt!) */
    datum_kiir(versenyzok[4].szuletes);
    /* 1-es versenyző nevének kezdőbetűjét (ne feledd, a sztring karaktertömb) */
    printf("1. Versenyző 1. betű: %c\n",versenyzok[1].nev[0]);
    /* az 1-es versenyző dobogós-e? igen/nem, akár ?: operátorral, de egy printf-fel */
     printf("1. Versenyző dobogós-e: %s\n",(versenyzok[1].helyezes<=3?"Igen":"Nem"));
    /* az 4-es versenyző gyorsabb-e, mint a 3-as versenyző? */
    printf("4. Versenyző gyorsabb-e mint 3-as: %s\n",(versenyzok[4].helyezes<versenyzok[3].helyezes?"Igen":"Nem"));
    /* az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? */
    printf("1. Versenyző ugyanabba az évbe születtett mint 2-es: %s\n",(versenyzok[1].szuletes.ev==versenyzok[2].szuletes.ev?"Igen":"Nem"));
    /* egészítsd ki a versenyzo_kiir() függvényt,
     * aztán írd ki az 1-es versenyző összes adatát */
    versenyzo_kiir(versenyzok[1]);
    /* végül listázd ki az összes versenyzőt sorszámozva, összes adatukkal. */
    for(int i=0;i<5;i++){
        printf("%d. ",i);
        versenyzo_kiir(versenyzok[i]);
    }
 
    return 0;
}
