#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>

#include <iostream>

using namespace std;

#define MAXSIZE 1024
#define IPADDRESS "127.0.0.1"
#define SERV_PORT 8888
#define FDSIZE 1024
#define EPOLLEVENTS 20

// static void handle_connection(int sockfd);
// static void handle_events(int epollfd,struct epoll_event *events,int num,int
// sockfd,char *buf);
// static void do_read(int epollfd,int fd,int sockfd,char *buf);
// static void do_read(int epollfd,int fd,int sockfd,char *buf);
// static void do_write(int epollfd,int fd,int sockfd,char *buf);
// static void add_event(int epollfd,int fd,int state);
// static void delete_event(int epollfd,int fd,int state);
// static void modify_event(int epollfd,int fd,int state);

void handleErr()
{
  if (errno == EINTR) {
    cout << "EINTR, ignore\n";
  }
  else if (errno == EAGAIN) {
    cout << "EAGAIN, try again\n";
  } else {
    cout << "others, read error\n";
  }
}


int main(int argc, char *argv[])
{



  return 0;
}
