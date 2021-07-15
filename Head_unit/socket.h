#ifndef SOCKET_H
#define SOCKET_H
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <iostream>
#include <vector>

using namespace std;
typedef unsigned char BYTE;
typedef std::vector<BYTE> ByteVectorType;


enum operation {TransferStart=1,TransferData=2 ,ProcessSwPackage  = 3 ,TransferExit = 4,TransferDelete =5,GetHistory=6,GetSwClusterInfo=7,GetSwPackages=8,Activate=9,Finish=10,Rollback=11};


int create_client_socket(int port, std::string ip);
int recv_files(int recv_socket_id,std::string path,std::string download_path);
void send_vector_pair(int send_socket_id,std::vector<std::pair<std::string,std::string>> updates);
std::string recv_string(int recv_socket_id);
int create_server_socket(int port_number);
void close_socket(int& a);
int socket_accept (int sockfd, int max_connect);
void send_string (int send_socket_id,std::string s);
bool Send_Data(ByteVectorType& data, unsigned long long size_,int& data_transfer_socket);
bool  Send_operation(operation op,int& data_transfer_socket);
void  recv_int(int a,int& data_transfer_socket);


template <typename T>
int Send_element(T element,int& a) {
    //.........for send data.............//
 int x1=write(a, &element, sizeof(T));

    //.........for recieve ack...........//
    // int ack=0;
     //int x2=read(a, &ack, sizeof(int));
     return (x1);

}


template <typename T>
int Recieve_element(T &element, int& a) {
    //........for recieve data............//
     int x1=read(a, &element, sizeof(T));
    //........for send ack........//
    // int ack=1;
     //int x2=write(a, &ack, sizeof(int));
     return x1;
}

#endif
