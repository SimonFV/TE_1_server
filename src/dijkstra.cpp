#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

/**
 * @brief Busca el camino mas optimo de un vertice a otro con el algoritmo Dijkstra
 * @param g Puntero del grafo al que se desea aplicar el algoritmo
 * @param start_s Nombre del vertice inicial
 * @param end_s Nombre del vertice final
 * @return Nombres de los vertices que componen la ruta, ademas del peso total
 */
string grafo::dijk(grafo *g, string start_s, string end_s){
    string ruta = "";
    //vertice destino
    vertice *end = g->get_vertice(end_s);
    //vertice inicio
    vertice *start = g->get_vertice(start_s);
    start->temp = 0;
    start->is_final = true;
    //ciclo mientras que no se haya llegado al vertice destino
    while(!(end->is_final)){
        //itera entre sus aristas
        arista *aux = start->ady;
        //asigna un valor temporal a los vertices adyacentes
        while(aux!=NULL){
            if(!(aux->ady->is_final)){
                if(aux->ady->temp > (start->temp + aux->peso)){
                    aux->ady->temp = start->temp + aux->peso;
                    aux->ady->anterior = start;
                }
            }
            aux = aux->next;
        }
        //determina el menor de los pesos para asignarlo como final
        start = menor(g);
    }

    vertice *run = end;
    ruta = " -> " + run->name;
    while(run->anterior!=NULL){
        ruta = " -> " + run->anterior->name + ruta;
        run = run->anterior;
    }
    ruta = ruta + "  ; Peso total: " + to_string(end->temp);
    g->reset();
    return ruta;
}

/**
 * @brief Analiza cual es el vertice con el peso temporal menor para bloquearlo
 * @param g Puntero del grafo al que se desea aplicar el algoritmo
 * @return Puntero al vertice con el menor peso temporal
 */
vertice *grafo::menor(grafo *g){
    vertice *aux = g->first;
    while(aux!=NULL){
        if(!(aux->is_final)){
            if(oo>aux->temp){
                break;
            }
        }
        aux = aux->next;
    }
    vertice *menor = aux;
    while(aux!=NULL){
        if(!(aux->is_final)){
            if(menor->temp>=aux->temp){
                menor = aux;
            }
        }
        aux = aux->next;
    }
    menor->is_final = true;
    return menor;
}