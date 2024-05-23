#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
   char** matriz;
   int linhas;
   int colunas;
};

typedef struct mapa MAPA;

struct posicao {
   int x, y;
};

typedef struct posicao POSICAO;

void libera_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
void le_mapa(MAPA* m);
void imprime_mapa(MAPA* m);
int encontra_mapa(MAPA* m, POSICAO* p, char c);

int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void anda_no_mapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m,char personagem, int x, int y);

