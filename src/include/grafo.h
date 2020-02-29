#ifndef GRAFO_H
#define GRAFO_H
#define oo 999999

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

class arista;

class vertice{
    vertice *next;
    vertice *anterior = NULL;
    arista *ady;
    string name;
    int temp = oo;
    bool is_final = false;
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
        bool is_empty();
        int tamano();
        vertice *get_vertice(string name);
        void new_arista(vertice *start, vertice *end, int peso);
        void new_vertice(string name);
        void list_ady();
        grafo *dijk(grafo *g, string start_s, string end_s);
        vertice *menor(grafo *g);
        //void delete_vertice(string name);
        //void delete_arista(vertice *start, vertice *end);
};

#endif
