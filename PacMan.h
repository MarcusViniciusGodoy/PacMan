void libera_mapa();
void aloca_mapa();
void le_mapa();
void move(char direcao);
int acabou();
void imprime_mapa();

struct mapa {
   char** matriz;
   int linhas;
   int colunas;
}
