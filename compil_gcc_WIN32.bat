gcc ./src/affichage.c -c -o ./bin/WIN32/affichage.o
gcc ./src/creation.c -c -o ./bin/WIN32/creation.o
gcc ./src/fichier.c -c -o ./bin/WIN32/fichier.o
gcc ./src/projet.c -c -o ./bin/WIN32/projet.o
gcc ./src/solveur.c -c -o ./bin/WIN32/solveur.o
gcc ./src/affichage.h -c -o ./bin/WIN32/affichage.h.gch
gcc ./src/constants.h -c -o ./bin/WIN32/constants.h.gch
gcc ./src/creation.h -c -o ./bin/WIN32/creation.h.gch
gcc ./src/fichier.h -c -o ./bin/WIN32/fichier.h.gch
gcc ./src/solveur.h -c -o ./bin/WIN32/solveur.h.gch
gcc -o ./exe/WIN32/projetx ./bin/WIN32/affichage.o ./bin/WIN32/creation.o ./bin/WIN32/fichier.o ./bin/WIN32/projet.o ./bin/WIN32/solveur.o