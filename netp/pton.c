#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char **argv) {
	char *p_addr = argv[1];
	struct in_addr *temp_addr;
	inet_pton(AF_INET, p_addr, &(temp_addr->s_addr));
	temp_addr->s_addr = ntohl(temp_addr->s_addr);
	printf("addr is 0x%2x\n", temp_addr->s_addr);
}