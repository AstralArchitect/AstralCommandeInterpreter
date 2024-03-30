#include <dirent.h>
#include <stdio.h>
#include <string.h>
 
void ls(char arg[100])
{
    struct dirent *dir;
    char dossier[100];
    strcpy(dossier, arg);
    DIR *d = opendir(dossier); 
    if (d)
    {
        printf("\033[0;33m%s:\n\033[0;37m", dossier);
        while ((dir = readdir(d)) != NULL)
        {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
        printf("\n");
    }else{
        printf("impossible d'ouvrir le dossier %s.\n", dossier);
    }
}
