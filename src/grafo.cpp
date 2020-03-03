#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

/**
 * @brief Constructor de la clase grafo
 */
grafo::grafo(){
    first=NULL;
}

/**
 * @brief Destructor de la clase grafo
 */
grafo::~grafo(){
    delete this;
}

/**
 * @brief Consulta si el grafo esta vacio
 * @return Retorna true si el grafo esta vacio
 */
bool grafo::is_empty(){
    if(first==NULL){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Analiza la cantidad de vertices que posee el grafo
 * @return Tamano del grafo
 */
int grafo::tamano(){
    int cont = 0;
    vertice *aux;
    aux = first;
    while(aux!=NULL){
        cont++;
        aux = aux->next;
    }
    return cont;
}

/**
 * @brief Reestablece los valores de todos los vertices
 */
void grafo::reset(){
    vertice *aux;
    aux = first;
    while(aux!=NULL){
        aux->is_final = false;
        aux->temp = oo;
        aux = aux->next;
    }
}

/**
 * @brief Busca un vertice con el mismo nombre en el grafo
 * @param id Nombre del vertice
 * @return Puntero al vertice solicitado
 */
vertice *grafo::get_vertice(string id){
    vertice *aux;
    aux = first;
    while(aux!=NULL){
        if(aux->name==id){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

/**
 * @brief Analiza el grafo para comprobar la existencia de un vertice
 * @param name_s Nombre del vertice
 * @return Retorna true si el grafo existe
 */
bool grafo::exists(string name_s){
    vertice *aux;
    aux = first;
    while(aux!=NULL){
        if(aux->name==name_s){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

/**
 * @brief Analiza la posicion (como entero) del vertice en la lista
 * @param name Nombre del vertice
 * @return Valor de posicion en la lista
 */
int grafo::get_position(string name){
    int position = 1;
    vertice *aux;
    aux = first;
    while(aux!=NULL){
        if(aux->name==name){
            return position;
        }
        aux = aux->next;
        position++;
    }
    return -1;
}

/**
 * @brief Agrega un nuevo vertice al grafo con el nombre solicitado
 * @param id Nombre del vertice
 */
void grafo::new_vertice(string id){
    vertice *add = new vertice;
    add->name = id;
    add->next = NULL;
    add->ady = NULL;
    if(is_empty()){
        first = add;
    }else{
        vertice *aux;
        aux = first;
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = add;
    }
}

/**
 * @brief Agrega una nueva arista conectando dos vertices
 * @param start Vertice inicial
 * @param end Vertice destino
 * @param peso Peso de la arista
 */
void grafo::new_arista(vertice *start, vertice *end, int peso){
    arista *add = new arista;
    add->ady = NULL;
    add->next = NULL;
    add->peso = peso;
    if(start->ady == NULL){
        start->ady = add;
        add->ady = end;
    }else{
        arista *aux;
        aux = start->ady;
        while(aux->next!=NULL){
            aux = aux->next;
        }
        aux->next = add;
        add->ady = end;
    }
}

/**
 * @brief Imprime por consola la lista de vertices y sus aristas
 */
void grafo::list_ady(){
    vertice *temp;
    arista *aux;
    temp = first;

    while(temp!=NULL){
        cout<<temp->name<<"[";
        aux = temp->ady;
        while(aux!=NULL){
            cout<<"ar -> "<<aux->ady->name<<"; ";
            aux = aux->next;
        }
        cout<<"]\n";
        temp = temp->next;
    }
}