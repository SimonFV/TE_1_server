#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

void read(grafo *g1){
    string ver_in, ver_fin, peso;
    ifstream csv_grafo;
    csv_grafo.open("/home/simon/Cpp/TE_1/TE_1_server/src/grafo.csv", ios::in);
    if(csv_grafo.fail()){
        cout<<"Error al abrir el archivo\n";
        exit(1);
    }
    while(!csv_grafo.eof()){
        getline(csv_grafo, ver_in, ',');
        if(!(g1->exists(ver_in))){
            g1->new_vertice(ver_in);
        }
        getline(csv_grafo, ver_fin, ',');
        if(!(g1->exists(ver_fin))){
            g1->new_vertice(ver_fin);
        }
        getline(csv_grafo, peso);
        g1->new_arista(g1->get_vertice(ver_in), g1->get_vertice(ver_fin), stoi(peso));
    }
    csv_grafo.close();

}