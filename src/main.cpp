#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

void run_server(grafo *g1);
void read(grafo *g1);

int main(int argc, char const *argv[]){
    grafo *g1 = new grafo;
    /**
     * @note lee el archivo csv y genera el grafo
     */
    read(g1);

    /**
     * @note inicia el servidor
     */
    run_server(g1);
    return 0;
}