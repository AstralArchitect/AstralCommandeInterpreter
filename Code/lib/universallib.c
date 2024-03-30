#include <stdio.h>
#include <stdbool.h>

#include "../include/commandes_System/aff.h"
#include "../include/commandes_System/ls.h"
//#include "../Programmes/commandes_System/mv.c" ne marche pas pour l'instant
#include "../include/commandes_System/rm.h"
#include "../include/commandes_System/configure.h"
#include "../include/commandes_System/touch.h"


#ifdef _WIN32
#include <windows.h>

void sleep_ms(DWORD milliseconds) {
    Sleep(milliseconds);
}

#elif _WIN64
#include <windows.h>

void sleep_ms(DWORD milliseconds) {
    Sleep(milliseconds);
}

#else

#include <time.h>

void sleep_ms(unsigned long milliseconds) {
    struct timespec ts;

    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;

    nanosleep(&ts, NULL);
}


#endif

#include <string.h>
#include <stdio.h>

void typedPrint(char *text, char *color, int speed) {
    printf("%s", color);
    for(int i = 0; i < strlen(text); i++){
        printf("%c", text[i]);

        // Nécessaire pour que l'effet marche sous Linux
        fflush(stdout);

        sleep_ms(speed);
    }
    printf("\n");
}

void execute(char *commande) {
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
    else if (commande[0] == 'c' && commande[1] == 'o' && commande[2] == 'n' && commande[3] == 'f' && commande[4] == 'i' && commande[5] == 'g' && commande[6] == 'u' && commande[7] == 'r' && commande[8] == 'e')
    {
        configure(argumment);
    }
    else if (commande[0] == 't' && commande[1] == 'o' && commande[2] == 'u' && commande[3] == 'c' && commande[4] == 'h')
    {
        touch(argumment);
    }
    else{
        printf("commande introuvable.\n");
    }
    
}