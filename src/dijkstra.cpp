#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

grafo *grafo::dijk(grafo *g, string start_s, string end_s){
    //Lista de los nombres de los vertices que componen la ruta mas eficiente
    grafo *ruta = new grafo;

    //vertice destino
    vertice *end = g->get_vertice(end_s);
    
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
    cout<<run->name<<" -> ";
    while(run->anterior!=NULL){
        cout<<run->anterior->name<<" -> ";
        run = run->anterior;
    }
    return ruta;
}

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