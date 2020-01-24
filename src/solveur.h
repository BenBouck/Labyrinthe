#include "constants.h"

int TrouverLongeur(char tab[TAILLE_MAX][TAILLE_MAX]);
int TrouverHauteur(char tab[TAILLE_MAX][TAILLE_MAX], int Longeur);
int TrouverDepart(char tab[TAILLE_MAX][TAILLE_MAX],int Longeur);
int NombreToucheR(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j);
void Rembobine(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt);
int TrouveRetour(char gauche, char droite, char haut, char bas);
void Droite(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Descend(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Gauche(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Monte(char tab[TAILLE_MAX][TAILLE_MAX], int *i, int *j, int *dernierMvt);
void Deplacement(char tab[TAILLE_MAX][TAILLE_MAX],int *i, int *j, int *dernierMvt);
void Resolution(char tab[TAILLE_MAX][TAILLE_MAX]);