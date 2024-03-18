#include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #define MAX 256

  int main(int argc, char *argv[]) {
        if(argc != 3){
                printf("\033[0;31mUsage: %s <source> <destination>\n\033[0;37m", argv[0]);
                exit(0);
        }
        int ch;
        FILE *fp1, *fp2;

        char source[MAX], target[MAX];
        strcpy(source, argv[1]);
        strcpy(target, argv[2]);
        printf("%s vers %s\n", source, target);

        /* open the source file in read mode */
        fp1 = fopen(source, "r");
        /* open the destination file in write mode */
        fp2 = fopen(target, "w+");

        /* error handling */
        if (!fp1) {
                printf("\033[0;31mImpossible d'ouvrir la source en lecture !!\033[0;37m\n");
                fclose(fp2);
                return 0;
        }

        if (!fp2) {
                printf("\033[0;31mImpossible d'ouvrir la destination en ecriture !!\033[0;37m\n");
                return 0;
        }
        /* copying contents of source file to target file */
        while ((ch = fgetc(fp1)) != EOF) {
                fputc(ch, fp2);
        }

        /* closing the opened files */
        fclose(fp1);
        fclose(fp2);

        /* removing the source file */
        remove(source);
        return 0;
  }