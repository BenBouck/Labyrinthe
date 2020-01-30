#include<stdio.h>
#include "affichage.h"

void afficherLabyrinthe(char labyrinthe[TAILLE_MAX][TAILLE_MAX]){
    for (unsigned int j = 0 ; j < TAILLE_MAX ; j++){
        for (unsigned int i = 0 ; i<TAILLE_MAX ; i++){
            switch (labyrinthe[i][j]){
                /* ~ Contenu du tableau ~
                 *   0 : Mur
                 *   1 : Chemin
                 *   2 : Vide
                 *   3 : Chemin connecté directement à une sortie
                 *   4 : Chemin solution
                 *   5 : Fin de ligne
                 *   6 : Fin de tableau
                 */
                case 0 :
                    printf("##");
                    break;
                case 1 :
                    printf("  ");
                    break;
                case 2 :
                    printf("E ");
                    break;
                case 3 :
                    printf("  ");
                    break;
                case 4 :
                    printf("//");
                    break;
                case 5 :
                    printf("\n");
                    i = TAILLE_MAX + 1;
                    break;
                case 6 :
                    i = TAILLE_MAX + 1;
                    j = TAILLE_MAX + 1;
                    break;
            }
        }
    }
}
