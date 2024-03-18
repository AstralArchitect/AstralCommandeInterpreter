#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Usage: %s <fileToDelet>\n", argv[0]);
        return 1;
    }
    remove(argv[1]);
}