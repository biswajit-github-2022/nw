WRITE A TCP CLIENT-SERVER PROGRAM TO CALCULATE ADDITION OF TWO NUMBER
 CLIENT SIDE (tcp_client_add.c)
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
#define PATH "/tmp/mysock"
int main()
{
 int cv,r,sd;
 char buffer[MAX];
 struct sockaddr_un myaddr;
 ssize_t l;
 sd=socket(AF_UNIX,SOCK_STREAM,0);
 if(sd==-1)
 {
 perror("SOCKET_ERROR ");
 exit(0);
 }
 myadd.sun_family=AF_UNIX;
 strncpy(myaddr.sun_path,PATH,sizeof(PATH));
 l=sizeof(myaddr);
 cv=connect(sd,(struct sockaddr*)&myaddr,l);
 if(cv==-1)
 {
 perror("CONNECT_ERROR ");
 exit(0);
 }
 printf("Enter Any Two Numbers In Interger:\n");
 memset(buffer,'\0',MAX);
 r=read(0,buffer,MAX);
 write(sd,buffer,r);
 r=read(0,buffer,MAX);
 write(sd,buffer,r);
 memset(buffer,'\0',MAX);
 r=read(sd,buffer,MAX);
 printf("Recive message from server: \n");
 printf("The addition of two numbers: \n");
 write(1,buffer,r);
 printf(" \n");
 return 0;
}
OUTPUT
 SERVER SIDE (tcp_server_add.c)
#include<stdio.h>
#include<sys/types>
#include<sys/socket>
#include<sys/un.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
#define PATH "/tmp/mysock"
int main()
{
 int a,b,c,av,lv,bv,r,sd;
 char buffer[MAX];
 struct sockaddr_un myaddr;
 socklen_t l;
 unlink(PATH);
 sd=socket(AF_UNIX,SOCK_STREAM,0);
 if(sd==-1)
 { perror("SOCKET_ERROR: ");
 exit(0); }
 myadd.sun_family=AF_UNIX;
 strncpy(myaddr.sun_path,PATH,sizeof(PATH));
 l=sizeof(myaddr);
 bv=bind(sd,(struct sockaddr*)&myaddr,l);
 if(bv==-1)
 { perror("BIND_ERROR: ");
 exit(0); }
 lv=listen(sd,10);
 if(lv==-1)
 { perror("LISTEN_ERROR: ");
 exit(0); }
 while(1)
 {
 printf("waiting for client request……\n"); 
 av=accept(sd,(struct sockaddr*)&myaddr,&l);
 if(av==-1)
 { perror("ACCEPT_ERROR ");
 exit(0); }
 memset(buffer, '\0',MAX);
 r=read(av,buffer,MAX);
 a=atoi(buffer);
 memset(buffer, '\0',MAX);
 r=read(av,buffer,MAX);
 b=atoi(buffer);
 c=a+b;
 gcvt(c,10,buffer);
 printf("The operation had been performed\n");
 write(av,buffer,MAX);
close(av);
}
return 0;
} OUTPUT