#include <stdio.h>
#include <stdlib.h>
#include "PacMan.h"

char** mapa;
int linhas;
int colunas;

void libera_mapa(){
    for(int i=0; i<linhas; i++){
        free(mapa[i]);
    }
    free(mapa); 
}

void aloca_mapa(){
    mapa = malloc(sizeof(char*) * linhas);
    for(int i=0;i<linhas;i++){
        mapa[i] = malloc(sizeof(char) * (colunas+1));
    }
}

void le_mapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
       printf("Erro na leitura do mapa.\n");
       exit(1);
    }
    
    fscanf(f, "%d %d", &linhas, &colunas);
    
    aloca_mapa();
    
    for(int i=0; i<5; i++){
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

int main(){
    le_mapa();
    
    for(int i=0; i<5; i++){
        printf("%s\n", mapa[i]);
    }
    
    libera_mapa();
}
