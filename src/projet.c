#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "constants.h"
#include "creation.h"
#include "affichage.h"
#include "fichier.h"
#include "solveur.h"

void copyLab(char tab[TAILLE_MAX][TAILLE_MAX], char tab2[TAILLE_MAX][TAILLE_MAX]){
    for(int i = 0 ; i < TAILLE_MAX ; i++){
        for(int j = 0 ; j<TAILLE_MAX ; j++){
            tab2[i][j] = tab[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    
    unsigned int choix = 0;
    char tab[TAILLE_MAX][TAILLE_MAX];
    char tabResolu[TAILLE_MAX][TAILLE_MAX];
    char tabInM = 0;
    char tabResoluInM = 0;
    char choix2 = 0;
    char nom[100];
    int x, y;

    printf("Bienvenue !\n");

    do{
        printf("Veuillez selectionner une fonctionnalite :\n\t- 0 : Quitter le programme\n\t- 1 : Generer un labyrinthe\n\t- 2 : Sauvegarder un labyrinthe (necessite qu'un labyrinthe ait ete genere ou charge)\n\t- 3 : charger un labyrinthe\n\t- 4 : resoudre un labyrinthe\n\t- 5 : afficher un labyrinthe\n\n\nVotre choix : ");
        scanf("%i", &choix);

        switch (choix){
        case 0:     //Quitte le while
            break;
        case 1:     //Génère un labyrinthe
            do{
                printf("Saisir la largeur (< 1000): ");
                scanf("%d", &x);
            }while (x>=1000 || x <= 0);
            do{
                printf("Saisir la hauteur (< 1000): ");
                scanf("%d", &y);
            }while (y>=1000 || y <= 0);
            tabInM = 1;
            creationLab(tab, x, y);
            break;
        case 2:     //Sauvegarde un labyrinthe
            if(tabInM == 1){
                printf("Veuillez saisir un chemin de destination suivi du nom de fichier \n(exemple : ""/lab/ex1"" enregistera un fichier nomme ""ex1.txt"" dans le dossier ""lab1"") \n(attention, si un fichier du meme nom existe deja, il sera ecrase)\n");
                scanf("%s", &nom);
                if (ecrireLabyrinthe(tab, strcat(nom, ".txt")) == 1){
                    printf("Un probleme est survenu, veuillez verifier le nom de fichier fourni.\n");
                }
                if(tabResoluInM == 1){
                    ecrireLabyrinthe(tabResolu, strcat(nom, "_SOLVED.txt"));
                }
            }
            else{
                printf("Veuillez generer ou charger un labyrinthe.\n");
            }
            break;
        case 3:     //Charge un labyrinthe
            printf("Veuillez saisir l'emplacement et le nom du fichier (sans extension): ");
            scanf("%s", &nom);
            if(lireLabyrinthe(tab, strcat(nom, ".txt")) == 1){
               printf("Un probleme est survenu, veuillez vérifier le nom de fichier fourni.\n");
            } else {
                tabInM = 1;
                if(lireLabyrinthe(tabResolu, strcat(nom, "_SOLVED.txt")) == 0){tabResoluInM = 1;}
            }
            break;
        case 4:     //Résout un labyrinthe
            if(tabInM == 1){
                copyLab(tab, tabResolu);
                Resolution(tabResolu);
                tabResoluInM = 1;
            }
            else{
                printf("Veuillez generer ou charger un labyrinthe.\n");
            }
            break;
        case 5:     //Affiche un labyrinthe
            if(tabInM == 1){
                if(tabResoluInM == 1){
                    do{
                        printf("Que souhaitez-vous afficher ?\n\t- 0 : labyrinthe vierge\n\t- 1 : labyrinthe resolu\n\t- 2 : les deux\n\n\nVotre choix : ");
                        scanf("%i", &choix2);
                    } while(choix2 != 0 && choix2 != 1 && choix2 != 2);
                }
                switch (choix2)
                {
                case 0:
                    afficherLabyrinthe(tab);
                    break;
                case 1:
                    afficherLabyrinthe(tabResolu);
                    break;
                case 2:
                    afficherLabyrinthe(tab);
                    printf("\n\n");
                    afficherLabyrinthe(tabResolu);
                    break;
                }
                printf("\n\n\n");
            }
            else {
                printf("Veuillez generer ou charger un labyrinthe.\n");
            }
            break;
        default:
            printf("Veuillez saisir l'une des valeurs proposees.\n");
            break;
        }

    }while (choix != 0);
   
    return 0;
}