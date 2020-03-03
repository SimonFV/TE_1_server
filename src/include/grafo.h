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
#include <fstream>
#include <stdlib.h>

using namespace std;

class arista;

/**
 * @brief Clase que representa los vertices del grafo
 */
class vertice{
    public:
    vertice *next;
    vertice *anterior = NULL;
    arista *ady;
    string name;
    int temp = oo;
    bool is_final = false;
    friend class grafo;
};

/**
 * @brief Clase que representa las aristas del grafo
 */
class arista{
    public:
    arista *next;
    vertice *ady;
    int peso;
    friend class grafo;
};

/**
 * @brief Clase grafo que se construye dinamicamente a partir de vertices y aristas
 */
class grafo{
    public:
        vertice *first;
        grafo();
        ~grafo();
        bool is_empty();
        int tamano();
        vertice *get_vertice(string name);
        bool exists(string name);
        void new_arista(vertice *start, vertice *end, int peso);
        void new_vertice(string name);
        void list_ady();
        string dijk(grafo *g, string start_s, string end_s);
        vertice *menor(grafo *g);
        int get_position(string name);
        void reset();
};

#endif
