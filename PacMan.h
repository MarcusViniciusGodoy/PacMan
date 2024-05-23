#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'


void move(char direcao);
int acabou();
int ehdirecao(char direcao);
void fantasmas();
int pra_onde_fantasma_vai(int xatual, int yatual, int* xdestino, int* ydestino);
