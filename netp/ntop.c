#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	//char *n_addr = argv[1];
	struct in_addr *temp;
	scanf("%x", &(temp->s_addr));
	char des[16];
	temp->s_addr = htonl(temp->s_addr);
	inet_ntop(AF_INET, &(temp->s_addr), des, 16);
	printf("addr is %s\n", des);
}