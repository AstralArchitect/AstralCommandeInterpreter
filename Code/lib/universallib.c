#include <stdio.h>
#include "../Programmes/commandes_System/aff.c"
#include "../Programmes/commandes_System/ls.c"
//#include "../Programmes/commandes_System/mv.c"
#include "../Programmes/commandes_System/rm.c"
#include "../Programmes/configure/main.c"
#include <stdbool.h>
#ifdef _WIN32
#include <windows.h>

void sleep_ms(DWORD milliseconds) {
    Sleep(milliseconds);
}

void execute(char commande[30]) {
    printf("\033[0;37m");
    char *espace = &commande[0];
    while (*espace != ' ')
    {
        espace++;
    }
    espace++;
    char argumment[100];
    char *argummentPointeur = &argumment[0];
    for (int i = 0; i < 30; i++)
    {
        *argummentPointeur = *espace;
        espace++;
        argummentPointeur++;
    }
    if(commande[0] == 'a' && commande[1] == 'f' && commande[2] == 'f')
    {
        aff(argumment);
    }
    else if (commande[0] == 'l' && commande[1] == 's')
    {
        ls(argumment);
    }
    else if (commande[0] == 'r' && commande[1] == 'm')
    {
        rm(argumment);
    }
    else{
        printf("commande introuvable.\n");
    }
    
}

#else

#include <time.h>

void sleep_ms(unsigned long milliseconds) {
    struct timespec ts;

    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;

    nanosleep(&ts, NULL);
}

char *exePath() {
    return "Lin";
}

void execute(char commande[16]) {
    printf("\033[0;37m");
    char exe[100];
    sprintf(exe, "./%s", commande);
    system(exe);
}


#endif

#include <string.h>
#include <stdio.h>

void typedPrint(char text[100], char color[11], int speed) {
    printf("%s", color);
    for(int i = 0; i < strlen(text); i++){
        printf("%c", text[i]);

        // Nécessaire pour que l'effet marche sous Linux
        fflush(stdout);

        sleep_ms(speed);
    }
    printf("\n");
}

void clear() {
    // 2J: Efface l'écran
    // H = 1;1H: Déplace le curseur en haut à gauche
    printf("\033[2J\033[H");
}
