#include "constants.h"

/* Returns
 * 0 : Exécution correcte
 * 1 : Problème d'ouverture du fichier
 */
int ecrireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier);
int lireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier);