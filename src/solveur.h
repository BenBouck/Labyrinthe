#include "constants.h"

/*  ~ DernierMvt ~
     *   0 : Droite
     *   1 : Bas
     *   2 : Gauche
     *   3 : Haut
*/

//Renvoient la Hauteur et la Longeur du labyrinthe.
int TrouverLongeur(char tab[TAILLE_MAX][TAILLE_MAX]);
int TrouverHauteur(char tab[TAILLE_MAX][TAILLE_MAX], int Longeur);

//Renvoie la position de la case du départ.
int TrouverDepart(char tab[TAILLE_MAX][TAILLE_MAX],int Longeur);

//Renvoie le nombre de touche directes (droite,gauche,haut,bas) de la case concernée.
int NombreToucheR(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j);

//Sortent le solveur d'une impasse.
void Rembobine(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt);
int TrouveRetour(char gauche, char droite, char haut, char bas);

//Déplacent le solveur dans le labyrinthe.
void Droite(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Descend(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Gauche(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Monte(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);

//Trouve la prochaine direction à prendre pour le solveur en fonction du dernier mouvement et des cases qui l'entourent.
void Deplacement(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt);

//Routine complète de résolution d'un labyrinthe.
void Resolution(char tab[TAILLE_MAX][TAILLE_MAX]);