#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void encontra_mapa(MAPA* m, POSICAO* p, char c){
    for(int i=0; i< m->linhas; i++){
        for(int j=0; j< m->colunas; j++){
            if(m->matriz[i][j] == c){
               p->x = i;
               p->y = j;
               break;
            }
        }
    }
}

void libera_mapa(MAPA* m){
    for(int i=0; i< m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz); 
}

void aloca_mapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for(int i=0; i< (*m).linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}

void le_mapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
       printf("Erro na leitura do mapa.\n");
       exit(1);
    }
    
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
    
    aloca_mapa(m);
    
    for(int i=0; i<5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}

void imprime_mapa(MAPA* m){
    for(int i=0; i<5; i++){
        printf("%s\n", m->matriz[i]);
    }
}

