WRITE A UDP CLIENT-SERVER PROGRAM TO CALCULATE SQUARE OF A NUMBER
 CLIENT SIDE (udp_client_square.c)
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#define PATH "/tmp/mysock"
#define MAX 100
int main()
{
 int sd,bv,r;
 char buffer[MAX];
 socklen_t sl,cl;
 struct sockaddr_un server_addr,client_addr;
 unlink(PATH);
 sd=socket(AF_UNIX,SOCK_DGRAM,0);
 if(sd==-1)
 {
 perror("SOCKET_ERROR: ");
 exit(0);
 }
 client_addr.sun_family=AF_UNIX;
 cl=sizeof(client_addr);
 bv=bind(sd,(struct sockaddr*)&client_addr,cl);
 if(bv==-1)
 {
 perror("BIND_ERROR: ");
 exit(0);
 }
 printf("Enter any Number in integers:\n");
 memset(buffer,'\0',MAX);
 r=read(0,buffer,MAX);
 server_addr.sun_family=AF_UNIX;
strncpy(server_addr.sun_path,PATH,sizeof(PATH));
 sl=sizeof(server_addr);
 printf("From server:\n");
 printf("The square of the number:\n");
 sendto(sd,buffer,r,0,(struct 
sockaddr*)&server_addr,sl);
 memset(buffer,'\0',MAX);
 recvfrom(sd,buffer,MAX,0,(struct 
sockaddr*)&server_addr,&sl);
 write(1,buffer,MAX);
 printf("\n");
 return 0;
} OUTPUT
 SERVER SIDE (udp_server_square.c)
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#define PATH "/tmp/mysock"
#define MAX 100
int main()
{
 int sd,bv,a;
 char buffer[MAX];
 socklen_t sl,cl;
 struct sockaddr_un server_addr,client_addr;
 unlink(PATH);
 sd=socket(AF_UNIX,SOCK_DGRAM,0);
 if(sd==-1)
 {
 perror("SOCKET_ERROR: ");
 exit(0);
 }
 server_addr.sun_family=AF_UNIX;
 strncpy(server_addr.sun_path,PATH,sizeof(PATH));
 sl=sizeof(server_addr);
 bv=bind(sd,(struct sockaddr*)&server_addr,sl);
 if(bv==-1)
 { perror("BIND_ERROR: ");
 exit(0); }
 while(1)
 {
 printf("waiting for client request ....\n")
 cl=sizeof(client_addr);
 recvfrom(sd,buffer,MAX,0,(struct 
sockaddr*)&client_addr,&cl);
 a=atoi(buffer);
 a=a*a;
 gcvt(a,10,buffer);
 printf("The operation had been 
performed.\n");
 sendto(sd,buffer,MAX,0,(struct 
sockaddr*)&client_addr,cl);
write(1,buffer,r);
printf("\n");
 }
 return 0;
} OUTPUT