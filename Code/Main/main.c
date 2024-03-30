#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/universallib.h"

#define MAX_INPUT_SIZE 100
#define INVITE_MAX_SIZE 30

//fonction pour vider le buffer
void viderBuffer()
{
  int c = 0;
  while (c != '\n' && c != EOF)
  {
    c = getchar();
  }
}

int System() {
  while (1)
  {
    char commande[MAX_INPUT_SIZE + 1];
    printf("\033[0;33m$ \033[0;37m");
    fgets(commande, MAX_INPUT_SIZE, stdin);
    //créer un pointeur qui servira à chercher le caractère '\n'
    char *positionEntree = NULL;
    //chercher le caractère '\n' dans la liste commande
    positionEntree = strchr(commande, '\n');
    //si le caractère éxiste...
    if (positionEntree != NULL)
    {
      //alors, le remplacer par '\0'
      *positionEntree = '\0';
    }
    //sinon...
    else
    {
      //l'utilisateur a entré une chaine de caractères trop grande. Il faut vider le buffer
      viderBuffer();
    }
    if(strcmp(commande, "exit") == 0 || strcmp(commande, "logout") == 0){
      typedPrint("Sortie du mode systeme...", "\033[0;35m", 25);
      sleep_ms(1000);
      printf("\033[0;37m");
      return 0;
    }
    else{
      char exe[100];
      sprintf(exe, "%s", commande);
      system(exe);
    }
  }
}

int getColor(char color) {
  switch (color)
  {
  case 'r':
    return 31; 
    break;
  case 'g':
    return 32; 
    break;
  case 'y':
    return 33; 
    break;
  case 'b':
    return 34; 
    break;
  case 'p':
    return 35; 
    break;
  case 'B':
    return 36; 
    break;
  case 'w':
    return 37; 
    break;
  default:
    return 0;
    break;
  }
}

int main() {
  char color1, color2;
  int charColor, textColor;
  int ShowUserName;
  char text[INVITE_MAX_SIZE + 1];
  FILE *fichier = NULL;
  #ifdef _WIN32
    fichier = fopen(".\\astral.conf", "r");
  #elif _WIN64
    fichier = fopen(".\\astral.conf", "r");
  #else
    fichier = fopen("./astral.conf", "r");
  #endif
  printf("\033[2J\033[H");
  if(fichier != NULL){
    fscanf(fichier, "%c, %c, %d, ", &color1, &color2, &ShowUserName);
    fgets(text, INVITE_MAX_SIZE, fichier);
    charColor = getColor(color1);
    textColor = getColor(color2);
    fclose(fichier);
  }
  else{
    printf("creation de astral.conf...\n");
    #ifdef _WIN32
    fichier = fopen(".\\astral.conf", "w+");
    #elif _WIN64
    fichier = fopen(".\\astral.conf", "w+");
    #else
    fichier = fopen("./astral.conf", "w+");
    #endif
    fprintf(fichier, "g, w, 1, $");
    fclose(fichier);
    #ifdef _WIN32
    fichier = fopen(".\\astral.conf", "r");
    #elif _WIN64
    fichier = fopen(".\\astral.conf", "r");
    #else
    fichier = fopen("./astral.conf", "r");
    #endif
    fscanf(fichier, "%c, %c, %d, ", &color1, &color2, &ShowUserName);
    fgets(text, INVITE_MAX_SIZE, fichier);
    charColor = getColor(color1);
    textColor = getColor(color2);
    fclose(fichier);
  }
  #ifdef _WIN32
  FILE *us = fopen(".\\us.conf", "r");
  #elif _WIN64
  FILE *us = fopen(".\\us.conf", "r");
  #else
  FILE *us = fopen("./us.conf", "r");
  #endif
  char UserName[100];
  if(us != NULL){
    fgets(UserName, 99, us);
    fclose(us);
  }
  else{
    printf("\033[0;31mimpossible d'ouvrir us.conf.\033[0;37m\n");
    printf("Quel est votre nom d'utilisateur ?:");
    fgets(UserName, 99, stdin);
    char *retour = strchr(UserName, '\n');
    if(retour != NULL){
      *retour = '\0';
    }
    else{
      viderBuffer();
    }
    #ifdef _WIN32
      us = fopen(".\\us.conf", "w+");
    #elif _WIN64
      us = fopen(".\\us.conf", "w+");
    #else
      us = fopen("./us.conf", "w+");
    #endif
    fprintf(us, "%s", UserName);
    fclose(us);
  }
  typedPrint("Bienvenu dans l'AstralCommandeInterpreter,", "\033[0;37m", 50);
  while(1){
    char commande[MAX_INPUT_SIZE + 1];
    printf("\033[0;%dm", charColor);
    if(ShowUserName){
      if(us != NULL){
        printf("%s:%s ", UserName, text);
      }
    }
    else{
      printf("%s ", text);
    }
    printf("\033[0;%dm", textColor);
    fgets(commande, MAX_INPUT_SIZE, stdin);
    //créer un pointeur qui servira à chercher le caractère '\n'
    char *positionEntree = NULL;
    //chercher le caractère '\n' dans la liste commande
    positionEntree = strchr(commande, '\n');
    //si le caractère éxiste...
    if (positionEntree != NULL)
    {
      //alors, le remplacer par '\0'
      *positionEntree = '\0';
    }
    //sinon...
    else
    {
      //l'utilisateur a entré une chaine de caractères trop grande. Il faut vider le buffer
      viderBuffer();
    }
    if(strcmp(commande, "exit") == 0 || strcmp(commande, "logout") == 0){
      typedPrint("arret de AstralCommandeInterpreter...", "\033[0;31m", 25);
      sleep_ms(1000);
      printf("\033[0;37m");
      return 0;
    }
    else if(strcmp(commande, "reload") == 0){
      //recharger AstralConfig
      fichier = fopen("./astral.conf", "r");
      if(fichier != NULL){
        fscanf(fichier, "%c, %c, %d, ", &color1, &color2, &ShowUserName);
        fgets(text, INVITE_MAX_SIZE, fichier);
        charColor = getColor(color1);
        textColor = getColor(color2);
        fclose(fichier);
      }
      else{
        printf("\033[0;31merreur, le fichier Astral.conf n'a pas pus etre ouvert.\n\033[0;37m");
      }
      //recharger us.conf
      #ifdef _WIN32
        us = fopen(".\\us.conf", "r");
      #elif _WIN64
        us = fopen(".\\us.conf", "r");
      #else
        us = fopen("./us.conf", "r");
      #endif
      char UserName[100];
      if(us != NULL){
        fgets(UserName, 99, us);
        fclose(us);
      }
      else{
        printf("\e[0;31mle fichier us.conf est introuvable.\e[0;37m\n");
      }
    }
    else if (strcmp(commande, "sys") == 0)
    {
      System();
    }
    else{
      execute(commande);
    }
  }
}
