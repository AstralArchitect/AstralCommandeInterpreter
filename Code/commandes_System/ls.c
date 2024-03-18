#include <dirent.h>
#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    struct dirent *dir;
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    char dossier[100];
    strcpy(dossier, argv[1]);
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
    return 0;
}
