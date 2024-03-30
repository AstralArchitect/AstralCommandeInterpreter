#include <stdio.h>
#include <string.h>

int configure(char argument[]) {
    
    #ifdef _WIN32
    FILE *fichier = fopen(".\\us.conf", "w+");
    #elif _WIN64
    FILE *fichier = fopen(".\\us.conf", "w+");
    #else
    FILE *fichier = fopen("./us.conf", "w+");
    #endif
    if(fichier != NULL){
        printf("Entrez un nom d'utilisateur:");
        char username[100];
        fgets(username, 99, stdin);
        char *EL = strchr(username, '\n');
        if(EL != NULL){
            *EL = '\0';
        }
        printf("nom d'utilisateur: %s\n", username);
        fprintf(fichier, "%s", username);
        fclose(fichier);
        return 0;
    }else{
        printf("\033[0;31mImpossible d'ouvrir le fichier us.conf.\033[0;37m\n");
        return 1;   
    }
    
}