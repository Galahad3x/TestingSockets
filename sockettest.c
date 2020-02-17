#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>

#define PORT 1050

int main(void){
    int server_fd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addrs;
    int adrlen = sizeof(addrs);
    addrs.sin_family = AF_INET;
    addrs.sin_port = htons(PORT);
    addrs.sin_addr.s_addr = INADDR_ANY;
    int bindc = bind(server_fd,(struct sockaddr*)&addrs,sizeof(addrs));
    int lis = listen(server_fd,3);
    int pid = fork();
    if(pid == 0){
        int client_fd = socket(AF_INET,SOCK_STREAM,0);
        int conn = connect(client_fd,(struct sockaddr*)&addrs,sizeof(addrs));
        char buffer[] = "Marselo agachate i conoselo";
        int sendd = send(client_fd,buffer,sizeof(buffer),0);
        printf("Child sent %s\n",buffer);
        close(client_fd);
        return 0;
    }
    char buffer2[1024];
    sleep(1);
    int newsock = accept(server_fd,(struct sockaddr *)&addrs,(socklen_t*)&adrlen);
    int reading = recv(newsock,buffer2,1024,0);
    printf("Parent received %s\n",buffer2);
    close(server_fd);
}
