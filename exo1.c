#include <stdio.h>

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

    for (int j = 0; j < 5; j++) {
        if (grille[ligne][j] == valeur) {
            return 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (grille[i][colonne] == valeur) {
            return 0;
        }
    }

    return 1;
}
void rempgrille(int grille[5][5]) {
    int ligne, colonne, valeur;

    while (1) {
        printf_s("Entrez le numero de la ligne (0 a 4): ");
        scanf_s("%d", &ligne);

        printf_s("Entrez le numero de la colonne (0 a 4): ");
        scanf_s("%d", &colonne);

        if (ligne >= 0 && ligne < 5 && colonne >= 0 && colonne < 5) {
            printf_s("Donnez votre valeur : ");
            scanf_s("%d", &valeur);

            if (valeur >= 1 && valeur <= 5 && Validite(grille, ligne, colonne, valeur)) {
                grille[ligne][colonne] = valeur;
                printf_s("Grille modifiee:\n");
                affGrille(grille, 5);
            }
            else {
                printf_s("Valeur invalide ou deja presente dans la ligne ou colonne.\n");
            }
        }
        else {
            printf_s("Ligne ou colonne invalide.\n");
        }
    }
}
int main() {
    int grille[5][5];
    initGrille(grille, 5);
    printf_s("Grille initialisee\n");
    affGrille(grille, 5);
    rempgrille(grille);
    return 0;
}

