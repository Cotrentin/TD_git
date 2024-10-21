#include <stdio.h>

void initGrille(int grille[5][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}

void affGrille(int grille[5][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grille[i][j]);
        }
        printf_s("\n");
    }
}

void rempgrille(int grille[5][5]) {
    int ligne, colonne, valeur;

    while (1) {
        printf_s("Entrez le num de la ligne (0 a 4): ");
        scanf_s("%d", &ligne);

        printf_s("Entrez le num de la colonne (0 a 4): ");
        scanf_s("%d", &colonne);

        if (ligne >= 0 && ligne < 5 && colonne >= 0 && colonne < 5) {
            printf_s("donner votre valeur: ");
            scanf_s("%d", &valeur);

            grille[ligne][colonne] = valeur;

            printf_s("Grille mise a jour:\n");
            affGrille(grille, 5);
        }
        else {
            printf_s("Erreur: ligne ou colonne invalide.\n");
        }
    }
}

int main() {
    int grille[5][5];
    initGrille(grille, 5);
    affGrille(grille, 5);
    rempgrille(grille);
    return 0;
}



