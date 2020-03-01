#include "/home/simon/Cpp/TE_1/TE_1_server/src/include/grafo.h"

grafo::grafo(){
    first=NULL;
}

bool grafo::is_empty(){
    if(first==NULL){
        return true;
    }else{
        return false;
    }
}

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