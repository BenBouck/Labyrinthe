#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

#include "fichier.h"

/*
 * ~ Retours ~
 * 0 : fichier écrit correctement
 * 1 : Erreut de création ou d'ouverture du fichier
 */
int EcrireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier){
    FILE *StFichier = NULL;

    StFichier = fopen(fichier, "w+");

    if (StFichier != NULL){
        for (unsigned int j = 0 ; j<TAILLE_MAX ; j++){
            for (unsigned int i = 0 ; i<TAILLE_MAX ; i++){
                fprintf(StFichier, "%i,", tab[i][j]);
                if (tab[i][j] == 5){
                    i = TAILLE_MAX;
                }
                if (tab[i][j] == 6){
                    i = TAILLE_MAX;
                    j = TAILLE_MAX;
                }
            }
        }

        fclose(StFichier);
    }
    else {
        return 1;
    }

    return 0;    
}

int lireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier){
    FILE *StFichier = NULL;

    StFichier = fopen(fichier, "r");

    if(StFichier != NULL){
        unsigned int i = 0;
        unsigned int j = 0;
        char c;
        while ((c = fgetc(StFichier))!=EOF){
            switch (c)
            {
            case ',':
                break;
            case '0':
                tab[i][j] = 0;
                i++;
                break;
            case '1':
                tab[i][j] = 1;
                i++;
                break;
            case '4':
                tab[i][j] = 4;
                i++;
                break;
            case '5':
                tab[i][j] = 5;
                i = 0;
                j++;
                break;
            case '6':
                tab[i][j] = 6;
                break;
            default:
                break;
            }
        }
        fclose(StFichier);
    }
    else{
        return 1;
    }

    return 0;
}