#include <stdio.h>

int touch(char argument) {
    FILE *fichier = fopen(&argument, "w+");
    fclose(fichier);
}