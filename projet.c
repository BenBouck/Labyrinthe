#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#include "constants.h"
#include "creation.h"
#include "affichage.h"
#include "fichier.h"
#include "solveur.h"

int main(){
    char tab[TAILLE_MAX][TAILLE_MAX];
    int x,y;
    srand(time(NULL));
    
    x=10;
    y=10;

    //creationLab(tab,x,y);

    //EcrireLabyrinthe(tab,"text.txt");

    lireLabyrinthe(tab,"text.txt");

    afficherLabyrinthe(tab);
    
    printf("\n");

    Resolution(tab);

    afficherLabyrinthe(tab);
   
    return 0;
}