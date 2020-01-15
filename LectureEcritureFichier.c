#include <stio.h>
#include <stdlib.h>

#define TAILLE_MAX 100

/*
 * ~ Retours ~
 * 0 : fichier écrit correctement
 * 1 : Erreut de création ou d'ouverture du fichier
 */
int EcrireLabyrinthe(char lab[TAILLE_MAX][TAILLE_MAX], const char fichier) {
    FILE *StFichier = NULL;

    StFichier = fopen(fichier, "w+");

    if (StFichier != NULL){
        for (unsigned int j = 0 ; j<TAILLE_MAX ; j++){
            for (unsigned int i = 0 ; i<TAILLE_MAX ; i++){
                fprintf(fichier, "%i,", lab[i][j]);
                if (lab[i][j] == 5){
                    i = TAILLE_MAX;
                }
                if (lab[i][j] == 6){
                    i = TAILLE_MAX;
                    j = TAILLE_MAX;
                }
            }
        }

        fclose(fichier);
    }
    else {
        return 1;
    }

    return 0;    
}