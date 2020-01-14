#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define TAILLE_MAX 100
#define Touche2 70
#define Touche3 35
#define Touche4 5

int interdiction1( char gauche, char vertical, char diagoG){
    //Si renvoie 1, le chemin sur cette case est interdit.
    if(diagoG==1 || diagoG==3){if(gauche==1 || gauche==3){if(vertical==1 || vertical==3){return 1;}}}
    else{return 0;}
}

int obligation1(char gauche, char vertical, char gauche2, char vertical2, char diagoG, char diagoD){
    //return 1--> obligé de créer
    if(gauche==1 || gauche==3){
        if(vertical==0){
            if(gauche2==1 || gauche2==3){return 0;}
            if(gauche2==0){
                if(diagoG==1 || diagoG==3){return 0;}
                if(diagoG==0){return 1;}
            }
        }
    }
    if(vertical==1 || vertical==3){
        if(vertical2==1 || vertical2==3){return 0;}
        if(vertical2==0){
            if(diagoG==1 || diagoG==3){return 0;}
            if(diagoG==0){
                if(diagoD==1 || diagoD==3){return 0;}
                if(diagoD==0){return 1;}
            }
        }
    }
    else{return 0;}
}

int obligation2(char vertical, char diagoD){
    //return 1--> obligé de créer
    if(vertical==3 && diagoD==0){return 1;}
    else{return 0;}
}

int obligation3(char *L){
    //return 1--> la ligne est bonne
    int a, i=0;
    while(L[i]!=5){
        if(L[i]==0 || L[i]==3){return 1;}
        i=i+1;
    }
    return 0;
}

int compteurG(char gauche, char gauche2, char diagoG){
    int a=0;
    if(gauche==1 || gauche==3){
        a++;
        if(gauche2==1 || gauche2==3){a++;}
        if(diagoG==1 || diagoG==3){a++;}
    }
    return a;
}

int compteurV(char vertical, char vertical2, char diagoG, char diagoD){
    int a=0;
    if(vertical==1 || vertical==3){
        a++;
        if(vertical2==1 || vertical2==3){a++;}
        if(diagoG==1 || diagoG==3){a++;}
        if(diagoD==1 || diagoD==3){a++;}
    }
    return a;
}

int nombreTouche(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2){
    //retourne le nombre de toouche autour de la case concernée
    int Ng=compteurG( gauche, gauche2, diagoG), Nv=compteurV(vertical, vertical2, diagoG, diagoD);
    if (Nv >= Ng){return Nv;}
    else{return Ng;}
}

int autorisation(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2, int LigneValide){
    //1--> création d'un chemin
    int r=rand() % (101);
    int Nt=nombreTouche(vertical, vertical2, diagoG, diagoD, gauche, gauche2);
    if(LigneValide==0){
        if(obligation2(vertical, diagoD)==1){return 1;}
    }
    if(interdiction1( gauche, vertical, diagoG)==1){return 0;}
    if(obligation1(gauche, vertical, gauche2, vertical2, diagoG, diagoD)==1){return 1;}
    if(Nt=2){
        if(r>=Touche2){return 0;}
        else{return 1;}
    }
    if(Nt=3){
        if(r>=Touche3){return 0;}
        else{return 1;}
    }
    if(Nt=4){
        if(r>=Touche4){return 0;}
        else{return 1;}
    }

}

int derniereLigne(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2, int LigneValide){
    int Nt=nombreTouche(vertical, vertical2, diagoG, diagoD, gauche, gauche2);
    int r=rand() % (101);
    if(LigneValide==0){
        if (obligation2(vertical, diagoD)==1){return 1;}
        if(Nt=2){
            if(r>=Touche2){return 0;}
            else{return 1;}
        }
        if(Nt=3){
            if(r>=Touche3){return 0;}
            else{return 1;}
        }
        if(Nt=4){
            if(r>=Touche4){return 0;}
            else{return 1;}
        }
    }
    else {return 0;}
}


void afficherLabyrinthe(char labyrinthe[TAILLE_MAX][TAILLE_MAX]){
    for (unsigned int j = 0 ; j < TAILLE_MAX ; j++){
        for (unsigned int i = 0 ; i<TAILLE_MAX ; i++){
            switch (labyrinthe[i][j]){
                /* ~ Contenu du tableau ~
                 *   0 : Mur
                 *   1 : Chemin
                 *   2 : Vide
                 *   3 : Chemin connecté directement à une sortie
                 *   4 : /
                 *   5 : Fin de ligne
                 *   6 : Fin de tableau
                 */
                case 0 :
                    printf("%c%c",219,219);
                    break;
                case 1 :
                    printf("  ");
                    break;
                case 2 :
                    printf("E ");
                    break;
                case 3 :
                    printf("~ ");
                    break;
                case 5 :
                    printf("\n");
                    i = TAILLE_MAX + 1;
                    break;
                case 6 :
                    i = TAILLE_MAX + 1;
                    j = TAILLE_MAX + 1;
                    break;
                default :
                    printf("%c%c",219,219);
                    break;
            }
        }
    }
}

void creationLab(char tab[TAILLE_MAX][TAILLE_MAX],int x,int y){
    int vertical2,gauche2,LigneHautValide=0;
    int r=rand() % (x-1) + 1;
    int nbSorties = 0;    

    for(unsigned int i=0;i<x;i++){
        for(unsigned int j=0;j<y;j++){
            tab[i][j] = 2;
        }
    }

    for(unsigned int i=0;i<x;i++){tab[i][0]=0;}
    tab[r][0]=3;
    tab[x][0]=5;
    for(unsigned int j=1;j<y-1;j++){
        tab[0][j]=0;
        tab[0][y-j-1]=0;
        for(unsigned int i=1;i<x-1;i++){
            if(j==1){vertical2=0;}
            else{vertical2=tab[i][j-2];}
            if(i==1){gauche2=0;}
            else{gauche2=tab[i-2][j];}
            if(autorisation(tab[i][j-1], vertical2, tab[i-1][j-1], tab[i+1][j-1], tab[i-1][j], gauche2, LigneHautValide)==1){
                if(tab[i-1][j]==3 || tab[i][j-1]==3){
                    tab[i][j]=3;
                    LigneHautValide=1;
                }
                else{tab[i][j]=1;}
            }
            else{tab[i][j]=0;}
        }
        for (unsigned int i=x-1;i>0;i--){
            if (tab[i][j]==1){
                if (tab[i+1][j]==3){
                    tab[i][j]=3;
                }
            }
        }
        LigneHautValide=0;
        tab[x-1][j]=0;
        tab[x][j]=5;
    }
    tab[0][y-1] = 0;
    for(unsigned int i=1;i<x-1;i++){
        if(i==1){gauche2=0;}
        else{gauche2=tab[i-2][y-2];}
        if(tab[i][y-2]==3){
            if(derniereLigne(tab[i][y-2], tab[i][y-3], tab[i-1][y-2], tab[i+1][y-2], tab[i-1][y-1], gauche2, LigneHautValide)==1){
                tab[i][y-1] = 3;
                nbSorties++;
            }
            else {tab[i][y-1] = 0;}
        } 
        else {tab[i][y-1] = 0;}
    }
    tab[x-1][y-1] = 0;
    tab[x][y-1] = 6;

    r = rand()%(nbSorties)+1;
    nbSorties = 0;
    for(unsigned int i = 0 ; i<x ; i++){
        if (tab[i][y-1]==3){
            nbSorties++;
            if (nbSorties != r){
                tab[i][y-1]=0;
            }
        }
    }

    for(unsigned int i=0;i<x;i++){
        for(unsigned int j=0;j<y;j++){
            if(tab[i][j]==3){tab[i][j]=1;}
        }
    }
}

int main(){
    char tab[TAILLE_MAX][TAILLE_MAX];
    int x,y;
    srand(time(NULL));
    /*printf("Quelle taille de labyrinthe (x*y) ?\n");
    printf("Entrez x : ");
    scanf("%d",&x);
    printf("Entrez y : ");
    scanf("%d",&y);*/
    x=83;
    y=43;

    creationLab(tab,x,y);

    afficherLabyrinthe(tab);

    return 0;
}