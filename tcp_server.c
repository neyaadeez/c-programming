#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server , client; 
    
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
        printf("Could not create socket");
        
    puts("Socket created");
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080); 
    //Bind
    if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done"); 
    //Listen
    listen(socket_desc, 3); 
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in); 
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted"); 
    }
    
    int read_size;
    char client_message[2000];
    //Receive a message from client
    while((read_size = recv(socket_desc, client_message, 2000 , 0)) > 0 )
    {
        //Send the message back to client
        write(socket_desc, client_message, strlen(client_message));
    } 
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    } else if(read_size == -1)
            perror("recv failed") ;
    free(socket_desc); 
    return 0;
}

