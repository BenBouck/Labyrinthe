#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#include "solveur.h"

int TrouverLongeur(char tab[TAILLE_MAX][TAILLE_MAX]){
    int i=0, cpt=0;
    while(tab[i][0]!=5){
        cpt++;
        i++;
    }
    return cpt;
}

int TrouverHauteur(char tab[TAILLE_MAX][TAILLE_MAX], int Longeur){
    int j=0, cpt=0;
    while(tab[Longeur][j]!=6){
        cpt++;
        j++;
    }
    return cpt;
}

int TrouverDepart(char tab[TAILLE_MAX][TAILLE_MAX],int Longeur){
    for(unsigned int i=0;i<Longeur;i++){
        if(tab[i][0]==1){return i;}
    }
}

int NombreToucheR(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j){
    int cpt=0;
    if(tab[*i-1][*j]==1){cpt++;}
    if(tab[*i+1][*j]==1){cpt++;}
    if(tab[*i][*j-1]==1){cpt++;}
    if(tab[*i][*j+1]==1){cpt++;}
    return cpt;
}

void Rembobine(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt){
    while(NombreToucheR(tab,i,j)<2){
        //printf("%d\\%d, %d", *i, *j, *dernierMvt);
        //scanf("%d", &tmp);
        tab[*i][*j]=1;
        switch (TrouveRetour(tab[*i-1][*j], tab[*i+1][*j], tab[*i][*j-1], tab[*i][*j+1]))
        {
        case 0:
            (*i)--;
            break;
        case 1:
            (*j)--;
            break;
        case 2:
            (*i)++;
            break;
        case 3:
            (*j)++;
            break;
        default:
            break;
        }
    }

}

int TrouveRetour(char gauche, char droite, char haut, char bas){
    if (gauche == 4){return 0;}
    if (haut == 4){return 1;}
    if (droite == 4){return 2;}
    if (bas == 4){return 3;}
}

void Droite(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt){
    tab[*i][*j]=4;
    (*i)++;
    *dernierMvt=0;
}

void Descend(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt){
    tab[*i][*j]=4;
    (*j)++;
    *dernierMvt=1;
}

void Gauche(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt){
    tab[*i][*j]=4;
    (*i)--;
    *dernierMvt=2;
}

void Monte(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt){
    tab[*i][*j]=4;
    (*j)--;
    *dernierMvt=3;
}


void Deplacement(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt){
    /*  ~ DernierMvt ~
     *   0 : Droite
     *   1 : Bas
     *   2 : Gauche
     *   3 : Haut
    */
    int tmp;
    if(*dernierMvt==0){
        if(tab[*i][*j+1]==1){
            Descend(tab,i,j,dernierMvt);
        }
        else if(tab[*i+1][*j]==1){
            Droite(tab,i,j,dernierMvt);
        }
        else if(tab[*i][*j-1]==1){
            Monte(tab,i,j,dernierMvt);
        }
        else{Rembobine(tab,i,j,dernierMvt);}
    }
    if(*dernierMvt==1){
        if(tab[*i-1][*j]==1){
            Gauche(tab,i,j,dernierMvt);
        }
        else if(tab[*i][*j+1]==1){
            Descend(tab,i,j,dernierMvt);
        }
        else if(tab[*i+1][*j]==1){
            Droite(tab,i,j,dernierMvt);
        }
        else{Rembobine(tab,i,j,dernierMvt);}
    }
    if(*dernierMvt==2){
        if(tab[*i][*j-1]==1){
            Monte(tab,i,j,dernierMvt);
        }
        else if(tab[*i-1][*j]==1){
            Gauche(tab,i,j,dernierMvt);
        }
        else if(tab[*i][*j+1]==1){
            Descend(tab,i,j,dernierMvt);
        }
        else{Rembobine(tab,i,j,dernierMvt);}
    }
    if(*dernierMvt==3){
        if(tab[*i+1][*j]==1){
            Droite(tab,i,j,dernierMvt);
        }
        else if(tab[*i][*j-1]==1){
            Monte(tab,i,j,dernierMvt);
        }
        else if(tab[*i-1][*j]==1){
            Gauche(tab,i,j,dernierMvt);
        }
        else{Rembobine(tab,i,j,dernierMvt);}
    }
}

void Resolution(char tab[TAILLE_MAX][TAILLE_MAX]){
    unsigned int i,j,x,y,DernierMvt;
    x=TrouverLongeur(tab);
    y=TrouverHauteur(tab,x);
    i=TrouverDepart(tab,x);
    j=0;
    DernierMvt=1;
    while(j!=y){
        Deplacement(tab,&i,&j,&DernierMvt);
    }
    tab[i][j] = 4;
}
