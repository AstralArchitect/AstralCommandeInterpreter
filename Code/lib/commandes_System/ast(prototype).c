#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichier = fopen("installTest/install.install", "r");
    if(fichier != NULL){
        printf("fichier ouvert avec succes!\n");
        char afficher[30];
        fgets(afficher, 30, fichier);
        printf("%s\n", afficher);
    }
    return 0;
}