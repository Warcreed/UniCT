#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>

#define SIZE 1024

void handleError(const char* errorElement){
    perror(errorElement);
    exit(1);
}

void setAddr(struct sockaddr_in* server_addr, char* port){
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(atoi(port));
}

int main(int argc, char* argv[]){
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    int sockfd, connect_sockfd;
    int bytes_read = 0;
    char message[SIZE];

    if(argc != 2){
        printf("inserisci la porta");
        exit(0);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        handleError("SOCKET");
    
    setAddr(&server_addr, argv[1]);
    
    int enable = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(enable), sizeof(int)) == -1)
        handleError("setsockopt");
    
    if(bind(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
        handleError("bind");
    
    if(listen(sockfd, 2) == -1)
        handleError("listen");

    while(1){
        if((connect_sockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_len)) == -1){
            close(sockfd);
            handleError("accept");
        }

        while((bytes_read = read(connect_sockfd, message, SIZE - 1)) > 0){
            message[bytes_read] = '\0';
            printf("%s\n", message);

            if(write(connect_sockfd, message, strlen(message) + 1) == -1){
                close(connect_sockfd);
                close(sockfd);
                handleError("Write");
            }
        }        
    }

    exit(0);
}
