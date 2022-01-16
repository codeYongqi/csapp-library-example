#include "csapp.h"
#define N 10

int main(int argc, char const *argv[])
{
	int status, i;

	pid_t pid[N], repid;

	for (i = 0; i < N; i++) {
		if ((pid[i]= Fork()) == 0)
			exit(100+i);
	}

	i = 0;
	while ((repid = waitpid(pid[i++], &status, 0)) > 0) {
		if (WIFEXITED(status))
			printf("child %d terminated normally with exit status=%d\n", repid, WEXITSTATUS(status));
		else 
			printf("child %d terminated abnormally\n", repid);
	}

	if (errno != ECHILD)
		unix_error("waitpid error");
	
	return 0;
}

