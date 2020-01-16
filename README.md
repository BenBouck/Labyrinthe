# Labyrinthe

*OBLED Thomas*

*BOUCKAERT Benoît*

Ce projet permet la création, l'affichage en console, la sauvegarde, le chargement et la résolution de labyrinthes de dimention maximale 1000*1000.

## Fonctions de création

### Interdiction1

*"Il est interdit de créer un chemin si la case directement à gauche, directement au dessus, et dans le coin supérieur gauche sont des chemins"*

#### Arguments

* __gauche *(char)*__ : Case de gauche
* __vertical *(char)*__ : Case du dessus
* __diagoG *(char)*__ : Case supérieure gauche

#### Retours 

* __0__ : Un chemin peut être créé.
* __1__ : Un chemin ne peut pas être créé.

### Obligation1

#### Arguments

* __gauche *(char)*__ : Case directement à gauche
* __gauche2 *(char)*__ : Deuxieme case à gauche
* __vertical *(char)*__ : Case directement au dessus
* __vertical2 *(char)*__ : Deuxième case au dessus
* __diagoG *(char)*__ : Case supérieure gauche
* __diagoD *(char)*__ : Case supérieure droite

#### Retours

* __0__ : Un chemin *doit* être créé.
* __1__ : Un chemin *peut* être créé.