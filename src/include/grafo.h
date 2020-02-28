#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>

using namespace std;

class arista;

class vertice{
    vertice *next;
    arista *ady;
    string name;
    friend class grafo;
};


class arista{
    arista *next;
    vertice *ady;
    int peso;
    friend class grafo;
};

class grafo{
    vertice *first;
    public:
        grafo();
        void start();
        bool is_empty();
        int tamano();
        vertice *get_vertice(string name);
        void new_arista(vertice *start, vertice *end, int peso);
        void new_vertice(string name);
        void list_ady();
        //void delete_vertice(string name);
        //void delete_arista(vertice *start, vertice *end);
};

#endif
