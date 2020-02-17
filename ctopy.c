#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT 2500

int main(void){
    struct sockaddr_in addrs;
    int adrlen = sizeof(addrs);
    addrs.sin_family = AF_INET;
    addrs.sin_port = htons(PORT);
    addrs.sin_addr.s_addr = INADDR_ANY;
    int client_fd = socket(AF_INET,SOCK_STREAM,0);
    int conn = connect(client_fd,(struct sockaddr*)&addrs,sizeof(addrs));
    while(0 < 1){
        char buffer[1024];
        printf("What to send?\n");
        char c;
        int i = 0;
        scanf("%c",&c);
        while(c != '\n'){
            buffer[i] = c;
            i++;
            scanf("%c",&c);
        }
        buffer[i] = '\0';
        if (i == 0){
            printf("Client closing connection\n");
            close(client_fd);
            exit(0);
        }else{
            while(i < 1024){
                buffer[i] = '\0';
            }
            int sendd = send(client_fd,buffer,sizeof(buffer),0);
            printf("Child sent %s\n",buffer);
        }
    }
}
