#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../commandes_System/universallib.h"

#define MAX_INPUT_SIZE 100
#define INVITE_MAX_SIZE 30
#define PATH_SIZE 30

//fonction pour vider le buffer
void viderBuffer()
{
  int c = 0;
  while (c != '\n' && c != EOF)
  {
    c = getchar();
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
    break;
  }
}

int main() {
  FILE *Path = NULL;
  char path[PATH_SIZE];
  Path = fopen("../../etc/PATH", "r");
  if(Path != NULL){
    fgets(path, PATH_SIZE, Path);
    fclose(Path);
  }
  else{
    printf("\033[0;31m Erreur ! PATH introuvable.\n \033[0;37m");
    exit(0);
  }
  FILE *fichier = NULL;
  fichier = fopen("../../etc/astral.conf", "r");
  char color1, color2;
  int charColor, textColor;
  char text[INVITE_MAX_SIZE + 1];
  clear();
  if(fichier != NULL){
    fscanf(fichier, "%c, %c, ", &color1, &color2);
    fgets(text, INVITE_MAX_SIZE, fichier);
    charColor = getColor(color1);
    textColor = getColor(color2);
    fclose(fichier);
  }
  else{
    printf("creation de astral.conf...\n");
    fichier = fopen("../../etc/astral.conf", "w+");
    fprintf(fichier, "g, w, $");
    fclose(fichier);
    fichier = fopen("../../etc/astral.conf", "r");
    fscanf(fichier, "%c, %c, ", &color1, &color2);
    fgets(text, INVITE_MAX_SIZE, fichier);
    charColor = getColor(color1);
    textColor = getColor(color2);
    fclose(fichier);
  }
  typedPrint("Bienvenu dans l'AstralCommandeInterpreter,", "\033[0;37m", 50);
  while(1){
    char commande[MAX_INPUT_SIZE + 1];
    printf("\033[0;%dm", charColor);
    printf("%s ", text);
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
    if((commande[0] == 'e' && commande[1] == 'x' && commande[2] == 'i' && commande[3] == 't') || (commande[0] == 'l' && commande[1] == 'o' && commande[2] == 'g' && commande[3] == 'o' && commande[4] == 'u' && commande[5] == 't')){
      typedPrint("arret de AstralCommandeInterpreter...", "\033[0;31m", 25);
      sleep_ms(1000);
      printf("\033[0;37m");
      return 0;
    }
    else if(commande[0] == 'r' && commande[1] == 'e' && commande[2] == 'l' && commande[3] == 'o' && commande[4] == 'a' && commande[5] == 'd'){
      //recharger AstralConfig
      fichier = fopen("../../etc/astral.conf", "r");
      if(fichier != NULL){
        fscanf(fichier, "%c, %c, ", &color1, &color2);
        fgets(text, INVITE_MAX_SIZE, fichier);
        charColor = getColor(color1);
        textColor = getColor(color2);
        fclose(fichier);
      }
      else{
          printf("\033[0;31merreur, le fichier Astral.conf n'a pas pus etre ouvert.\n\033[0;37m");
      }
      //recharger le PATH
      Path = fopen("../../etc/PATH", "r");
      if(Path != NULL){
        fgets(path, PATH_SIZE, Path);
        fclose(Path);
      }
      else{
        printf("\033[0;31m Erreur ! PATH introuvable.\n \033[0;37m");
        exit(0);
      }
    }
    else{
      execute(path, commande);
    }
  }
}
