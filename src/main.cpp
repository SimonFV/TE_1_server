#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

using namespace std;

void run_server();

int main(int argc, char const *argv[]){

    grafo *g1 = new grafo;
    g1->new_vertice("ver1");
    g1->new_vertice("ver2");
    g1->new_vertice("ver3");
    g1->new_vertice("ver4");
    g1->new_vertice("ver5");
    g1->new_vertice("ver6");

    g1->new_arista(g1->get_vertice("ver1"), g1->get_vertice("ver4"), 20);
    g1->new_arista(g1->get_vertice("ver4"), g1->get_vertice("ver2"), 78);
    g1->new_arista(g1->get_vertice("ver2"), g1->get_vertice("ver3"), 31);
    g1->new_arista(g1->get_vertice("ver3"), g1->get_vertice("ver5"), 2000);
    g1->new_arista(g1->get_vertice("ver2"), g1->get_vertice("ver1"), 56);
    g1->new_arista(g1->get_vertice("ver1"), g1->get_vertice("ver3"), 13);
    g1->new_arista(g1->get_vertice("ver4"), g1->get_vertice("ver5"), 13);
    g1->new_arista(g1->get_vertice("ver2"), g1->get_vertice("ver6"), 13);

    g1->dijk(g1, "ver1", "ver6");
    //g1->list_ady();
    //run_server();
    return 0;
}