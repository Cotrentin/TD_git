// NOTE : 11/20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//on voulait pouvoir choisir une taille entre 1 et 9 pas 1 et 5
void initGrille(int grille[5][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}
void affGrille(int grille[5][5], int n) {
    printf_s("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grille[i][j] == 0) {
                printf_s("   ");
            }
            else {
                printf_s("%2d ", grille[i][j]);
            }

            if (j < n - 1) {
                printf_s("| ");
            }
        }
        printf_s("\n");

        if (i < n - 1) {
            for (int k = 0; k < n; k++) {
                printf_s("----");
            }
            printf_s("\n");
        }
    }
    printf_s("\n");
}
int Validite(int grille[5][5], int ligne, int colonne, int valeur) {
    // il faut passer la taille de la grille en parametre, on voulait pouvoir choisir une taille entre 1 et 9
    for (int j = 0; j < 5; j++) { // une seule boucle est suffisante
        if (grille[ligne][j] == valeur || grille[j][colonne] == valeur) {
            return 0;
        }
    }


    return 1;
}
void RemplirGrille_random(int grille[5][5], int niveau) {
    // idem il faut passer la taille de la grille en parametre
    int n = 5;
    int casesARemplir;

    switch (niveau) {
    case 1: casesARemplir = (n * n) / 2; break;
    case 2: casesARemplir = (n * n) / 3; break;
    case 3: casesARemplir = (n * n) / 4; break;
    default: return;
    }

    srand(time(NULL));

    while (casesARemplir > 0) {
        int ligne = rand() % n;
        int colonne = rand() % n;
        int valeur = (rand() % n) + 1;


        if (Validite(grille, ligne, colonne, valeur)) {
            grille[ligne][colonne] = valeur;
            casesARemplir--;
        }
    }
}
void rempgrille(int grille[5][5]) {
    // idem il faut passer la taille de la grille en parametre
    int ligne, colonne, valeur;

    while (1) { // boucle infinie, aucun break pour arrêter le while
        printf_s("Entrez le numero de la ligne (0 a 4): ");
        scanf_s("%d", &ligne);

        printf_s("Entrez le numero de la colonne (0 a 4): ");
        scanf_s("%d", &colonne);

        if (ligne >= 0 && ligne < 5 && colonne >= 0 && colonne < 5) {
            printf_s("Donnez votre valeur (entre 1 et 5): ");
            scanf_s("%d", &valeur);

            if (valeur >= 1 && valeur <= 5 && Validite(grille, ligne, colonne, valeur)) {
                grille[ligne][colonne] = valeur;
                printf_s("Grille modifiee:\n");
                affGrille(grille, 5);
            }
            else {
                printf_s("Valeur invalide ou deja presente dans la ligne ou colonne. Essayez encore.\n");
            }
        }
        else {
            printf_s("Ligne ou colonne invalide.\n");
        }
    }
}

int main() {
    int grille[5][5];
    int choix, niveau;

    while (1) {
        printf_s("\nMenu:\n");
        printf_s("1. Initialiser la grille\n");
        printf_s("2. Generer la grille aleatoirement\n");
        printf_s("3. Resoudre la grille\n");
        printf_s("4. Afficher la grille\n");
        printf_s("5. Quitter\n");
        printf_s("Entrez votre choix: ");
        scanf_s("%d", &choix);

        switch (choix) {
        case 1:
            initGrille(grille, 5);
            printf_s("Grille initialisee.\n");
            break;
        case 2:
            printf_s("Choisissez le niveau de remplissage (1: 50%%, 2: 33%%, 3: 25%%): ");
            scanf_s("%d", &niveau);
            RemplirGrille_random(grille, niveau);
            printf_s("Grille generee aleatoirement.\n");
            break;
        case 3:
            rempgrille(grille);
            break;
        case 4:
            affGrille(grille, 5);
            break;
        case 5:
            printf_s("Au revoir !\n");
            return 0;
        default:
            printf_s("Choix invalide. Veuillez reessayer.\n");
        }
    }
    return 0;
}
