#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define PORT 1500
#define MAX_CON (1200)

static struct epoll_event* events;

int main(int argc, char* argv[])
{
    fd_set master;
    fd_set read_fds;

    struct sockaddr_in serveraddr;
    struct sockaddr_in clientaddr;

    int fdmax;
    int listener;
    int newfd;
    char buff[1024];
    int nbytes;
    int addrlen;

    int yes;
    int epfd = -1;
    int res = -1;

    struct epoll_event ev;
    int i = 0;
    int index = 0;
    int client_fd = -1;
    int SnumOfConnection = 0;
    time_t Sstart, Send;

    if (listener = socket(AF_INET, SOCK_STREAM, 0) == -1) {
        perror("Server socket() error lol!");
        exit(1);
    }

    if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("Server setsocketopt() error lol");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = INADDR_ANY;
    serveraddr.sin_port = htons(PORT);
    memset(&serveraddr.sin_zero, '\0', 8);

    if (bind(listener, (struct sockaddr* )&serveraddr, sizeof(serveraddr)) == -1) {
        perror("Server-bind() erro lol");
        exit(1);
    }

    if (listen(listener, 10) == -1) {
        perror("Server-listern() error lol");
        exit(1);
    }

    fdmax = listener;
    events = calloc(MAX_CON, sizeof(struct epoll_event));
    if ((epfd = epoll_create(MAX_CON)) == -1) {
        perror("epoll_create error lol");
        exit(1);
    }

    ev.events = EPOLLIN;
    ev.data.fd = fdmax;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, fdmax, &ev) < 0 ) {
        perror("epoll_ctril error lol");
        exit(1);
    }

    for (;;) {

        res = epoll_wait(epfd, events, MAX_CON, -1);

        for (index = 0; index < MAX_CON; index++) 
        {
            client_fd = events[index].data.fd;

            if (client_fd == listener) 
            {
                if ((newfd = accept(listener, (struct sockaddr*)&clientaddr, &addrlen)) == -1) 
                {
                    perror("Server-accept() error lol");
                } 
                else {
                    ev.events = EPOLLIN;
                    ev.data.fd = newfd;
                    if (epoll_ctrl(epfd, EPOLL_CTL_ADD, newfd, &ev) < 0) {
                        perror("epoll_ctrl");
                        exit(1);
                    }
                }
                break;
            }
            else
            {
                if (events[index].events & EPOLLHUP) {
                    if (epoll_ctl(epfd, EPOLL_CTL_DEL, client_fd, &ev) < 0) {
                        perror("epoll_ctrl");
                    }
                    close(client_fd);
                    break;
                }

                if (events[index].events & EPOLLIN) {

                    if (nbytes = recv(client_fd, buff, sizeof(buff), 0) <= 0) {
                        if (nbytes == 0) {
                            printf("socket %d hung up\n", client_fd);
                        }
                        else {
                            printf("recv() error lol%d", client_fd);
                            perror("");
                        }

                        if (epoll_ctl(epfd, EPOLL_CTL_DEL, client_fd, &ev) <0) {
                            perror("epoll_ctrl");
                        }
                        close(client_fd);

                    } else {
                        if (send(client_fd, buff, nbytes, 0) == -1) {
                            perror("send() erro lol");
                        }
                    }
                    break;
                }

            }
        }


    }

    return 0;
}