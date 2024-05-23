#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PacMan.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int pra_onde_fantasma_vai(int xatual, int yatual, int* xdestino, int* ydestino){
    int opcoes[4][2] = {
        { xatual, yatual +1},
        { xatual + 1, yatual},
        { xatual, yatual -1},
        { xatual -1, yatual}
    };
    
    srand(time(0));
    for(int i=0; i<10; i++){
        int posicao = rand() % 4;
        
        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
           *xdestino = opcoes[posicao][0];
           *ydestino = opcoes[posicao][1];
           
           return 1;
        }
    }
    return 0;
}

void fantasmas(){
    MAPA copia;
    
    copiamapa(&copia, &m);

     for(int i=0;i<m.linhas;i++){
         for(int j=0;j<m.colunas;j++){
             if(copia.matriz[i][j] == FANTASMA){
                int xdestino, ydestino;
                
                int encontrou = pra_onde_fantasma_vai(i, j, &xdestino, &ydestino);
             
                if(encontrou){
                   anda_no_mapa(&m, i, j, xdestino, ydestino);
                }
             }
         }
     }
   
     libera_mapa(&copia);
}

int acabou(){
    POSICAO pos;
    int perdeu = !encontra_mapa(&m, &pos, HEROI);
    int ganhou = !encontra_mapa(&m, &pos, FANTASMA);
    return ganhou || perdeu;
}

int ehdirecao(char direcao){
     return direcao == 'a' || 
     direcao == 'w' || 
     direcao == 's' || 
     direcao == 'd';
}

void move(char direcao){
    
    if(!ehdirecao(direcao))
    	return;
    
    int proximo_x = heroi.x;
    int proximo_y = heroi.y;
    
    switch(direcao){
       case ESQUERDA:
           proximo_y--;
           break;
       case CIMA:
           proximo_x--;
           break;
       case BAIXO:
           proximo_x++;
           break;
       case DIREITA:
           proximo_y++;
           break;
    }
    
    if(!podeandar(&m, HEROI, proximo_x, proximo_y))
        return;
    
    anda_no_mapa(&m, heroi.x, heroi.y, proximo_x, proximo_y);
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

int main(){
    le_mapa(&m);
    encontra_mapa(&m, &heroi, HEROI);
    
    do{
       imprime_mapa(&m);
       
       char comando;
       scanf(" %c", &comando);
       move(comando);
       fantasmas();
       
    }while(!acabou());
    
    libera_mapa(&m);
}
