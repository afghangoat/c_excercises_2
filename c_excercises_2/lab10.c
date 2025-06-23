#include <stdio.h>
#include <stdlib.h>
 
typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;
 
 
/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;
 
    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}
 
void print_lista(ListaElem* l){
    ListaElem* cur=l;
    while(cur!=NULL){
        printf("%d ",cur->adat);
        cur=cur->kov;
    }
}

int lista_hossz(ListaElem* l){
    ListaElem* cur=l;
    int h=0;
    while(cur!=NULL){
        h++;
        cur=cur->kov;
    }
    return h;
}
void free_lista(ListaElem* l){
    ListaElem* cur=l;
    while(cur!=NULL){
        ListaElem* jelen=cur;
        free(jelen);
        cur=cur->kov;
        jelen=NULL;
    }
}
ListaElem* find_in_lista(ListaElem* l,int mit){
    ListaElem* cur=l;
    while(cur!=NULL){
        if(mit==cur->adat){
            return cur;
        }
        cur=cur->kov;
    }
    return NULL;
}
void beszur_vege(ListaElem* l,int mit){
    ListaElem* cur=l;
    while(cur->kov!=NULL){
        cur=cur->kov;
    }
    ListaElem* n_elem=(ListaElem*) malloc(sizeof(ListaElem));
    n_elem->kov=NULL;
    n_elem_adat=mit;
    if(cur==NULL){
        cur->kov=n_elem;
    } else {
        cur->kov=n_elem;
    }
    
}
void beszur_eleje(ListaElem* l,int mit){
    
    ListaElem* n_elem=(ListaElem*) malloc(sizeof(ListaElem));
    n_elem->kov=l;
    n_elem_adat=mit;
    
}

int main(void) {
    ListaElem *eleje;
    
    eleje = lista_letrehoz();
    
    print_lista(eleje);
    lista_hossz(eleje);
    
    return 0;   
}