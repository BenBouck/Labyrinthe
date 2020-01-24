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

int main(){
    srand(time(NULL));
    
    unsigned char choix = 0;
    char tab[TAILLE_MAX][TAILLE_MAX];
    char tabResolu[TAILLE_MAX][TAILLE_MAX];
    char tabInM = 0;
    char tabResoluInM = 0;

    printf("Bienvenu !\n");

    do{
        printf("Veuillez sélectionner une fonctionnalité :\n\t- 0 : Quitter le programme\n\t- 1 : Générer un labyrinthe\n\t- 2 : Sauvegarder un labyrinthe (nécessite qu'un labyrinthe ait été généré ou chargé)\n\t- 3 : charger un labyrinthe\n\t- 4 : résoudre un labyrinthe\n\t- 5 : afficher un labyrinthe\n\n\nVotre choix : ");
        scanf("%i", &choix);

        switch (choix){
        case 0:     //Quitte le while
            break;
        case 1:     //Génère un labyrinthe
            int x, y;            
            do{
                printf("Saisir la largeur (< 1000): ");
                scanf("%d", &x);
            }while (x>=1000 || x <= 0);
            do{
                printf("Saisir la hauteur (< 1000): ");
                scanf("%d", &y);
            }while (y>=1000 || y <= 0);
            if (tabInM == 0){tabInM = 1;}
            creationLab(tab, x, y);
            break;
        case 2:     //Sauvegarde un labyrinthe
            char nom[100];
            if(tabInM){
                printf("Veuillez saisir un chemin de destination suivi du nom de fichier \n(exemple : ""/lab/ex1"" enregistera un fichier nommé ""ex1.txt"" dans le dossier ""lab1"") \n(attention, si un fichier du même nom existe déjà, il sera écrasé)\n"):
                scanf("%s", nom);
                if (ecrireLabyrinthe(tab, strcat(nom, ".txt"))){
                    printf("Un probleme est survenu, veuillez vérifier le nom de ficier fourni.")
                }
                if(tabResoluInM){
                    ecrireLabyrinthe(tabResolu, strcat(nom, "_SOLVED.txt"));
                }
            }
            else{
                printf("Veuillez générer ou charger un labyrinthe.\n");
            }
            break;
        case 3:     //Charge un labyrinthe
            char nom[100];
            printf("Veuillez saisir l'emplacement et le nom du fichier (sans extension): ");
            scanf("%s", &nom);
            if(lireLabyrinthe(tab, strcat(nom, ".txt"))){
               printf("Un probleme est survenu, veuillez vérifier le nom de ficier fourni.")
            } else {
                if (tabInM == 0){tabInM = 1;}
                if(!lireLabyrinthe(tabResolu, strcat(nom, "_SOLVED.txt"))){tabResoluInM = 1;}
            }
            break;
        case 4:     //Résout un labyrinthe
            if(tabInM){
                ecrireLabyrinthe(tab, "tmp.txt");
                lireLabyrinthe(tabResolu, "tmp.txt");
                remove("tmp.txt");
                Resolution(tabResolu);
                tabResoluInM = 1;
            }
            else{
                printf("Veuillez générer ou charger un labyrinthe.\n");
            }
            break;
        case 5:     //Affiche un labyrinthe
            char choix2 = 0;
            if(tabInM){
                if(tabResoluInM){
                    do{
                        printf("Que souhaitez-vous afficher ?\n\t- 0 : labyrinthe vierge\n\t- 1 : labyrinthe résolu\n\t- 2 : les deux\n\n\nVotre choix : ");
                        scanf("%i", &choix2);
                    } while(choix2 != 0 && choix2 != 1 && choix != 2);
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
            }
            else {
                printf("Veuillez générer ou charger un labyrinthe.\n");
            }
            break;
        default:
            printf("Veuillez saisir l'une des valeurs proposées.\n")
            break;
        }

    }while (choix != 0);
   
    return 0;
}