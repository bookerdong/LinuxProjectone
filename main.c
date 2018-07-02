#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


#define PORT 8080  
#define SERVER_ADDR "192.168.9.60"

int main()
{
	int socket_fd = -1;
	struct sockaddr_in server_addr;  
   	struct hostent *host;  
	int fd = -1;
	char send_buf[] = "abcd";
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd < 0)
	{
		perror("socket");
	}

	bzero(&server_addr, sizeof(server_addr));  
	server_addr.sin_family = AF_INET;  
   	server_addr.sin_port = htons(PORT);  
   	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	printf("sin_family = %d\n",server_addr.sin_family);
	printf("sin_port = %d\n",server_addr.sin_port);	
	printf("sin_addr = %d\n",server_addr.sin_addr.s_addr);
	fd =connect(socket_fd, (struct sockaddr *)(&server_addr), sizeof(struct sockaddr));
	if (fd < 0)
	{
		perror("connect");
	}
	
	while(1)
	{
		send(socket_fd,send_buf,sizeof(send_buf),0);
		printf("client send!\n");
		sleep(1);
	}
	return 0;
}
