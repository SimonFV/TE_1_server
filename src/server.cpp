#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
 
using namespace std;
 
int run_server(){
    //Crear el socket
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_socket == -1){
        cerr<<"No se pudo crear el socket, cerrando..."<<endl;
        return -1;
    }

    //Enlaza una ip y un numero de puerto al socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
 
    bind(listen_socket, (sockaddr*)&hint, sizeof(hint));
 
    //Dice Winsock el socket es para listening
    listen(listen_socket, SOMAXCONN);
 
    //Espera una conexion
    cout<<"Esperando cliente..."<<endl;
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
 
    int clientSocket = accept(listen_socket, (sockaddr*)&client, &clientSize);
 
    char host[NI_MAXHOST];      //Nombre remoto del cliente
    char service[NI_MAXSERV];   //Donde se conecta el cliente
 
    memset(host, 0, NI_MAXHOST); //igual que memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);
 
    if(getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
        cout << host << " conectado en el puerto " << service << endl;
    }else{
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " conectado en el puerto " << ntohs(client.sin_port) << endl;
    }
 
    //Cierra el socket para listening
    close(listen_socket);

    // While loop: Acepta y devuelve el mismo mensaje del cliente
    char buf[4096];
 
    while (true){
        memset(buf, 0, 4096);
 
        //Espera que el cliente envie un dato
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1){
            cerr << "Error al recibir el mensaje" << endl;
            break;
        }
 
        if (bytesReceived == 0){
            cout << "Cliente desconectado" << endl;
            break;
        }
        string message = "asd";
        cout << string(buf, 0, bytesReceived) << endl;
 
        //Devuelve el mismo mensaje
        //send(clientSocket, buf, bytesReceived + 1, 0); //retorna el mismo mensaje
        send(clientSocket, message.c_str(), message.size() + 1, 0);
    }
 
    //cierra el socket
    close(clientSocket);
    
    return 0;
}