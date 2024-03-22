#include <stdio.h>
#include <stdlib.h>

FILE *openAge(char mode[4]){
	#ifdef _WIN32
	return fopen("..\\etc\\age\\age.txt", mode);
	#elif _WIN64
	return fopen("..\\etc\\age\\age.txt", mode);
	#else
	return fopen("../etc/age/age.txt", mode);
}

int main() {
	//création du pointeur du fichier
   	FILE* fichier = NULL;
	//ouverture du fichier en lecture seule
   	fichier = openAge("r");

	//si le fichier éxiste alors...
   	if (fichier != NULL) {

		//lire le contenu du fichier et l'enregistrer dans la variable age
		int age;
		fscanf(fichier, "%d", &age);
		//afficher l'age
    	printf("ancien age :%d\n", age);
		//fermer le fichier
		fclose(fichier);

		//réouvrir le fichier en mode écriture et éffacer son contenu
		fichier = openAge("w+");
		//demander l'age à l'utilisateur et enregistrer la réponse dans la variable age
		printf("Quel age avez vous ?:");
		scanf("%i", &age);
		//enregistrer l'age dans le fichier age.txt et fermer le fichier
		fprintf(fichier, "%d", age);
		fclose(fichier);
 
		//réouvrir le fichier en lecture seule
    	fichier = openAge("r");
		//lire le contenu du fichier et l'enriegistrer dans la variable age
        fscanf(fichier, "%d", &age);
		//affiche age et fermer le fichier
        printf("\nnouvel age :%d\n", age);
        fclose(fichier);
	
	//sinon...
   	}else {
		//créer le fichier
		printf("creation du fichier age.txt...\n");
		fichier = openAge("w+");
		//mettre l'age à zero
		fprintf(fichier, "0");
		fclose(fichier);
		//fermer le programme
		exit(0);
    }
}