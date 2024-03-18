#include <stdio.h>
#include <string.h>
#define MAX 256

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE *fichier;
    char chemin[MAX];
    strcpy(chemin, argv[1]);
    fichier = fopen(chemin, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier\n");
        fclose(fichier);
        return 0;
    }
    char contenu[MAX];
    rewind(fichier);
    while (fgets(contenu, MAX, fichier) != NULL) {
        printf("%s", contenu);
    }
    printf("\n");
}
