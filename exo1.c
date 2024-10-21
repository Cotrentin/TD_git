#include <stdio.h>

void initGrille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = 0;
        }
    }
}

void affGrille(int grille[9][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf_s("%d ", grille[i][j]);
        }
        printf_s("\n");
    }

}
int main() {
    int grille[5][5];
    initGrille(grille, 5);
    affGrille(grille, 5);
    return 0;
}



