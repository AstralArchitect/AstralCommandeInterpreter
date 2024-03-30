#include <stdio.h>

void touch(char argument[30]) {
    FILE *fichier = fopen(&argument[0], "w+");
    fclose(fichier);
}