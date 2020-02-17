#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#define PORT 2501

int main(void){
    struct sockaddr_in serv_addrs,cl_addrs;
    char *hello = "Hello from server\n";
    int adrlen = sizeof(serv_addrs);
    serv_addrs.sin_family = AF_INET;
    serv_addrs.sin_port = htons(PORT);
    serv_addrs.sin_addr.s_addr = INADDR_ANY;
    int server_fd = socket(AF_INET,SOCK_DGRAM,0);

    int bindd = bind(server_fd,(const struct sockaddr *) &serv_addrs,sizeof(serv_addrs));

    char buffer[1024];

    int len = sizeof(cl_addrs);
    int rec = recvfrom(server_fd,(char *) buffer, 1024,MSG_WAITALL, (struct sockaddr *) &cl_addrs, &len);
    buffer[rec] = '\0';
    printf("Server received: %s\n",buffer);
    sendto(server_fd, (const char *)hello, strlen(hello),  MSG_CONFIRM, (const struct sockaddr *) &cl_addrs, len);
    printf("Server sent %s\n", hello);
}
