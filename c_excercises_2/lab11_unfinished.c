#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int w;
    int h;
    char** sorok;
} Lab;

void init_lab(Lab* lab,int sorok, int oszlopok){
    lab->sorok=(char**) malloc (sizeof(char*)*sorok);
    for(int i=0;i<sorok;i++){
        lab->sorok[i]=(char*)malloc(sizeof(char)*(oszlopok+1));
    }
    lab->w=oszlopok;
    lab->h=sorok;
}
void kirajzol_lab(Lab* lab){
    char* cur=lab->sorok[0];
    int iter=0;
    while(iter!=lab->h){
        printf("%s\n",cur);
        iter++;
        cur=lab->sorok[iter];
    }
}
typedef struct{
    int x;
    int y;
} Player;

#define JOBB 0
#define BAL 1
#define FEL 2
#define LE 3
typedef struct{
    int ir;
} Irany;
Player* find_player(Lab* lab){
    Player* p=(Player*)malloc(sizeof(Player));
    for(int x=0;x<lab->w;x++){
        for(int y=0;y<lab->h;y++){
            if(lab->sorok[y][x]=='@'){
                p->x=x;
                p->y=y;
                return p;
            }
        }
    }
}
bool mehet_e(Lab* lab,Irany* ir){
    Player* p=find_player(lab);
    char elem;
    switch(ir->ir){
        case JOBB:
            elem=lab->sorok[p->y][p->x+1];
            if(&elem=="#"||&elem=="\0"){
                return false;
            }
            return true;
            break;
        case BAL:
            if(p->x==0){
                return false;
            }
            elem=lab->sorok[p->y][p->x-1];
            if(&elem=="#"){
                return false;
            }
            return true;
            break;
        case LE:
            if(lab->sorok[p->y+1]==NULL){
                return false;
            }
            elem=lab->sorok[p->y+1][p->x];
            if(&elem=="#"){
                return false;
            }
            return true;
            break;
        case FEL:
            if(p->y==0){
                return false;
            }
            elem=lab->sorok[p->y-1][p->x];
            if(&elem=="#"){
                return false;
            }
            return true;
            break;
    }
    return false;
}

int find_kincs(Lab* lab){
    int db=0;
    Player* p=(Player*)malloc(sizeof(Player));
    for(int x=0;x<lab->w;x++){
        for(int y=0;y<lab->h;y++){
            if(lab->sorok[y][x]=='$'){
                db++;
            }
        }
    }
    return db;
}
void rak_sor(Lab* lab,int sorszam,char* ujsor){
    strcpy(lab->sorok[sorszam],ujsor);
}
//Irany
typedef struct pos{
    int px;
    int py;
    struct pos* kov;
} pos;
void append_pos(pos* bejartak,int px, int py){
    struct pos* jelen=(struct pos*) malloc(sizeof(pos));
    jelen->px=px;
    jelen->py=py;
    jelen->kov=NULL;
    if(bejartak==NULL){
        bejartak=jelen;
        return;
    }
    pos* cur=bejartak;
    while(true){
        if(cur->kov==NULL){
            cur->kov=jelen;
            return;
        }
        cur=cur->kov;
    }
}

bool ment_mar(pos* lista,int px,int py){
    pos* cur=lista;
    if(cur==NULL){
        return false;
    }
    while(cur->kov!=NULL){
        if(cur->px==px&&cur->py==py){
            return true;
        }
        cur=cur->kov;
    }
    return false;
}
typedef struct{
    int px;
    int py;
    bool fel;
    bool le;
    bool jobb;
    bool bal;
    pos_iranyok* kov;
} pos_iranyok;
void try_move(Lab* lab,Player* p,pos_iranyok* irany,pos* bejartak){
    //p->x
    append_pos(pos* bejartak,p->x,p->y);
    if(irany->fel==true){
        lab->sorok[p->y][p->x]=' ';
        lab->sorok[p->y-1][p->x]='$';
        p->y--;
        irany->fel=false;
        return;
    }
    if(irany->le==true){
        lab->sorok[p->y][p->x]=' ';
        lab->sorok[p->y+1][p->x]='$';
        p->y++;
        irany->le=false;
        return;
    }
    if(irany->bal==true){
        lab->sorok[p->y][p->x]=' ';
        lab->sorok[p->y][p->x-1]='$';
        p->x--;
        irany->bal=false;
        return;
    }
    if(irany->jobb==true){
        lab->sorok[p->y][p->x]=' ';
        lab->sorok[p->y][p->x+1]='$';
        p->x++;
        irany->jobb=false;
        return;
    }
}

typedef struct{
    int megszerzett_kincsek;
    pos* bejartak;
    pos_iranyok* todo;
} backtrack;
pos_iranyok* find_end_dir(pos_iranyok* irany){
    pos_iranyok* cur=irany;
    if(cur==NULL){
        return NULL;
    }
    while(cur->kov!=NULL){
        cur=cur->kov;
    }
}
pos_iranyok* van_valid(pos_iranyok* irany){
    pos_iranyok* cur=irany;
    if(cur==NULL){
        return NULL;
    }
    while(cur->kov!=NULL){
        if(cur->jobb==true||cur->bal==true||cur->fel==true||cur->le==true){
            return cur;
        }
        cur=cur->kov;
    }
    return NULL;
}
void find_paths(backtrack* bt,Lab* lab){
    pos_iranyok* ir=find_end_dir(bt->todo,lab);
    pos_iranyok* aa=(pos_iranyok*)malloc(sizeof(pos_iranyok));
    aa->kov=NULL;
    Irany ir;
    ir->ir=BAL;
    aa->bal=mehet_e(lab,*ir);
    ir->ir=JOBB;
    aa->jobb=mehet_e(lab,*ir);
    ir->ir=FEL;
    aa->fel=mehet_e(lab,*ir);
    ir->ir=LE;
    aa->le=mehet_e(lab,*ir);
    ir->kov=aa;
}
void start_backtrack(Lab* lab){
    backtrack bt;
    bt.megszerzett_kincsek=0;
    Player* p_pos=find_player(lab);
    bt.bejartak=(pos*)malloc(sizeof(pos));
    bt.bejartak->px=p_pos->x;
    bt.bejartak->py=p_pos->y;
    bt.bejartak->kov=NULL;
    
    pos_iranyok* v=van_valid(bt.todo);
    while(v!=NULL){
        try_move(lab,p_pos,v,bt.bejartak);
        find_paths(&bt,lab);
    }
    //bool ment_mar(pos* lista,int px,int py);
}
int main(void) {
    Lab labi;
    init_lab(&labi,10,10);
    rak_sor(&labi,0,"###### ###");
    rak_sor(&labi,1,"#$   #   #");
    rak_sor(&labi,2,"#### ### #");
    rak_sor(&labi,3,"#        #");
    rak_sor(&labi,4,"# #### ###");
    rak_sor(&labi,5,"# #    #$#");
    rak_sor(&labi,6,"# ##$# # #");
    rak_sor(&labi,7,"#@ ### # #");
    rak_sor(&labi,8,"#   $#   #");
    rak_sor(&labi,9,"##########");
    Player* p=find_player(&labi);
    kirajzol_lab(&labi);
    start_backtrack(&labi);
    kirajzol_lab(&labi);
    return 0;

}
