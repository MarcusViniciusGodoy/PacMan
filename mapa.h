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
void encontra_mapa(MAPA* m, POSICAO* p, char c);

