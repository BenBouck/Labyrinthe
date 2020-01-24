# Labyrinthe

*OBLED Thomas*

*BOUCKAERT Benoît*

Ce projet permet la création, l'affichage en console, la sauvegarde, le chargement et la résolution de labyrinthes de dimention maximale 1000*1000.

## Compilation

Le programme est divisé en 5 fonctionnalités, et donc 10 fichiers *.c* et *.h* :

* projet.c : *fichier contenant la fonction `main()`*
* constants.h : *fichier définissant des constantes*.
* creation.c : *fichier contenant les fonctions de création*
* creation.h : *fichier contenant les prototypes des fonctions de creation.c*
* affichage.c : *fichier contenant les fonctions d'affichage du labyrinthe*
* affichage.h : *fichier contenant les prototypes des fonctions de affichage.c*
* fichier.c : *fichier contenant les fonction propres à la sauvegarde et le chargement des labyrinthes*
* fichier.h : *fichier contenant les prototypes des fonctions de fichier.c*
* solveur.c : *fichier contenant les fonction de résolution des labyrinthes*
* solveur.h : *fichier contenant les prototypes des fonctions de solveur.c*

Les fichiers *.c* et *.h* sont disponibles dans le répertoire */src* du projet.

Les fichiers objets compilés sous windows avec GCC sont également disponibles dans le répertoire */bin/WIN32*, ainsi que le fichier exécutable sous windows dans le répertoire */exe/WIN32*.

## Utilisation

L'utilisation du programme est guidée via une interface console basique.

Les principales fonctions sont les suivantes :

* `creationLab()` : crée un labyrinthe.
    * **prototype** : `void creationLab(char tab[TAILLE_MAX][TAILLE_MAX],int x,int y);`
    * **arguments** : 
        * `char labyrinthe[TAILLE_MAX][TAILLE_MAX]` : tableau de `char` de dimention `TAILLE_MAX` par `TAILLE_MAX` où le labyrinthe sera stocké.
        * `int x` : nombre de colonnes du labyrinthe
        * `int y` : nombre de lignes du labyrinthe
* `afficherLabyrinthe` : affiche un labyrinthe.
    * **prototype** : `void afficherLabyrinthe(char labyrinthe[TAILLE_MAX][TAILLE_MAX])`
    * **argument** : `char labyrinthe[TAILLE_MAX][TAILLE_MAX]` : tableau de `char` de dimention `TAILLE_MAX` par `TAILLE_MAX` où le labyrinthe à afficher est stocké.
* `ecrireLabyrinthe()` : écrit un labyrinyhe dans un fichier *.txt*.
    * **prototype** : `int ecrireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier)`
    * **arguments** :
        * `char labyrinthe[TAILLE_MAX][TAILLE_MAX]` : tableau de `char` de dimention `TAILLE_MAX` par `TAILLE_MAX` où le labyrinthe à sauvegarder est stocké.
        * `const char *fichier` : nom et emplacement du fichier __sans extension__. *N.B.: le fichier sera ouvert aver le paramètre `"w"`, ce qui écrasera son contenu si il existe déjà.*
* `lireLabyrinthe()` : lit un labyrinthe sauvegardé dans un fichier *.txt*.
    * **prototype** : `int lireLabyrinthe(char tab[TAILLE_MAX][TAILLE_MAX], const char *fichier)`
    * **arguments** :
        * `char labyrinthe[TAILLE_MAX][TAILLE_MAX]` : tableau de `char` de dimention `TAILLE_MAX` par `TAILLE_MAX` où le labyrinthe à ouvrir sera stocké.
        * `const char *fichier` : nom et emplacement du fichier __sans extension__.
* `Resolution()` : résout un labyrinthe.
    * **prototype** : `void Resolution(char tab[TAILLE_MAX][TAILLE_MAX])`
    * **argument** : `char labyrinthe[TAILLE_MAX][TAILLE_MAX]` : tableau de `char` de dimention `TAILLE_MAX` par `TAILLE_MAX` où le labyrinthe à résoudre est stocké.
    
## Exemples de labyrinthes

Les labyrinthes présentés en exemple sont disponibles dans le répertoire */lab* du projet.

### lab1.txt

```
████  ██████████████
██    ██          ██
████  ██  ██████████
████  ██████      ██
██            ██████
██████  ████  ██████
████    ████      ██
████  ██    ████████
████  ██████████  ██
████  ██████████████
```

### lab2.txt
### lab3.txt
### lab4.txt
### lab5.txt