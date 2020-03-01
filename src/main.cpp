#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

using namespace std;

void run_server();
void read(grafo *g1);

int main(int argc, char const *argv[]){

    grafo *g1 = new grafo;
    read(g1);
    g1->list_ady();

    g1->dijk(g1, "v1", "v4");

    return 0;
}