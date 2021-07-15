#include "socket.h"

int create_server_socket(int port_number)
{
    char* ip = "127.0.0.1";
    int e ;
    struct sockaddr_in serv_addr;
    socklen_t addr_size;
    int server_socket_id=socket(AF_INET,SOCK_STREAM,0);
    if (server_socket_id < 0)
    {
        perror("[-]Error in socket");
        exit(1);

    }
    printf("[+]Server socket created successfully.\n");


//giving port and ip address to server
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = port_number;
  serv_addr.sin_addr.s_addr = inet_addr(ip);


//binding the socket to the server address
  e = bind(server_socket_id, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  if(e < 0) {
    perror("[-]Error in bind");
    exit(1);
  }
  printf("[+]Binding successfull.\n");


return server_socket_id;
}

int socket_accept (int sockfd, int max_connect)
{
    int new_sock;
    struct sockaddr_in new_addr;
    socklen_t addr_size;

    if(listen(sockfd, max_connect) == 0){
            printf("[+]Listening....\n");
        }else{
            perror("[-]Error in listening");
            exit(1);
        }

      addr_size = sizeof(new_addr);
      new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);

      return new_sock;
}






int create_client_socket(int port, std::string ip)
{

	int n = ip.length();
    char file_path[n + 1];
    strcpy(file_path, ip.c_str());
	char *Ip =file_path;

	int e;

	int sockfd;
	struct sockaddr_in server_addr;


	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Server socket created successfully.\n");

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(Ip);

	e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(e == -1) {
		perror("[-]Error in socket");
		exit(1);
	}
	printf("[+]Connected to Server.\n");

return sockfd;

}



int recv_files(int recv_socket_id,std::string path,std::string download_path)
{
	    int a1 =::chdir(download_path.c_str());
        //convert string to char array
        int n = path.length();
        // declaring character array
        char file_path[n + 1];
        // copying the contents of the string to char array
        strcpy(file_path, path.c_str());

        FILE* to;
        char c;
        char *path_write =file_path ;
        to = fopen(path_write, "w");

        //we create a dummy int buffer to receive the file length in it
        long long int recv_length_buffer[1];
        int received_length=recv(recv_socket_id,recv_length_buffer,8,0);
        long long int recv_length=recv_length_buffer[0];
        printf("%d\n",recv_length);

        char recv_buff[1];


        for (int i = 0; i < recv_length; i++)
            {
                recv(recv_socket_id,recv_buff,1,0);
                c=recv_buff[0];
                putc(c, to);
            }

        fclose(to);
        printf("The file is now closed.\n");
        return 1;
}


void send_vector_pair(int send_socket_id,std::vector<std::pair<std::string,std::string>> updates)
{
    int updates_size=updates.size();
    int c = htonl(updates_size);
    write(send_socket_id, &c,sizeof(c));
    for(int i=0;i<updates_size;i++)
    {
        std::string name=updates[i].first;
        int string_size=name.length();
        int c = htonl(string_size);
        write(send_socket_id, &c,sizeof(c));
        //convert string to char array
        int n = name.length();
        // declaring character array
        char file_path[n + 1];
        // copying the contents of the string to char array
        strcpy(file_path, name.c_str());
        send(send_socket_id, &file_path, name.length(), 0);
        //float number_to_send = updates[i].first; // Put your value
        //float converted_number = htonl(number_to_send);
        //write(send_socket_id, &converted_number,sizeof(converted_number));
        //send(send_socket_id,&number_to_send,sizeof (number_to_send),0);
        std::string version=updates[i].second;
        int string_size_2=version.length();
        int c2 = htonl(string_size_2);
        write(send_socket_id, &c2,sizeof(c2));
        //convert string to char array
        int n2 = version.length();
        // declaring character array
        char file_path2[n2 + 1];
        // copying the contents of the string to char array
        strcpy(file_path2, version.c_str());
        send(send_socket_id, &file_path2, version.length(), 0);
    }
}

std::string recv_string(int recv_socket_id)
{
    std::string s;
    int string_size=0;
    read(recv_socket_id, &string_size, sizeof(string_size));
    string_size=ntohl(string_size);
    int n;
    char buf[string_size];
    n = recv(recv_socket_id, buf, sizeof(buf), 0);
           s.append(buf, buf + n);
    return s;
}



void send_string (int send_socket_id,std::string s)
{
    int string_size=s.length();
    int c = htonl(string_size);
    write(send_socket_id, &c,sizeof(c));
    //convert string to char array
    int n = s.length();
    // declaring character array
    char file_path[n + 1];
    // copying the contents of the string to char array
    strcpy(file_path, s.c_str());
    send(send_socket_id, &file_path, s.length(), 0);
}

bool Send_Data(ByteVectorType& data, unsigned long long size_,int& data_transfer_socket)
{
    int a2;
    for(auto i=0; i<size_; i++)
    {
        a2=Send_element<BYTE>(data[i],data_transfer_socket);
    }
    return true;
}

bool  Send_operation(operation op,int& data_transfer_socket)
{
 int rec_op =Send_element<operation>(op, data_transfer_socket);
    if(rec_op == true){
   return true;
   }
    else{
    return false;
    }
}

void  recv_int(int a,int& data_transfer_socket)
{
 int rec_op =Recieve_element<int>(a, data_transfer_socket);
}

void close_socket(int& a)
{
    close(a);
}
