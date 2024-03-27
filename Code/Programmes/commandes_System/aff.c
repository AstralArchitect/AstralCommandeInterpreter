#include <stdio.h>
#include <string.h>
#define MAX 256

int aff(char arg[100]) {
    FILE *fichier;
    char chemin[MAX];
    strcpy(chemin, arg);
    fichier = fopen(chemin, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier\n");
        fclose(fichier);
        return 1;
    }
    char contenu[MAX];
    rewind(fichier);
    while (fgets(contenu, MAX, fichier) != NULL) {
        printf("%s", contenu);
    }
    printf("\n");
    return 0;
}
