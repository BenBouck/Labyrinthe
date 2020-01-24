#include "constants.h"

/*
 * gauche    : case directement à gauche de la case à remplir.
 * gauche2   : deuxième case à gauche ------------------------
 * vertical  : case directement au dessus --------------------
 * vertical2 : deuxième case au dessus -----------------------
 * diagoG    : case en haut à gauche -------------------------
 * diagoD    : case en haut à droite -------------------------
 */

//Renvoie 1 si la création d'un chemin est interdite.
int interdiction1( char gauche, char vertical, char diagoG);

// Renvoient 1 si une case doit absolument être créée, 0 sinon.
int obligation1(char gauche, char vertical, char gauche2, char vertical2, char diagoG, char diagoD);
int obligation2(char vertical, char diagoD);

//Retournent le nombre de chemins parmi les cases passées en argument.
int compteurG(char gauche, char gauche2, char diagoG);
int compteurV(char vertical, char vertical2, char diagoG, char diagoD);
int nombreTouche(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2);

//Renvoie 1 si un chemin sera créé, 0 sinon.
int autorisation(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2, int LigneValide);

//Renvoie 1 si un chemin sera créé, 0 sinon.
int derniereLigne(char vertical, char vertical2, char diagoG, char diagoD,char gauche, char gauche2, int LigneValide);

//Routine complète de création d'un nouveau labyrinthe.
void creationLab(char tab[TAILLE_MAX][TAILLE_MAX],int x,int y);