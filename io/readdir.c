#include "csapp.h"

int main(int argc, char **argv) {
	DIR *streamp;
	struct dirent *dep;

	streamp = Opendir(argv[1]);

	errno = 0;
	while((dep = readdir(streamp)) != NULL) {
		printf("Found file: %s\n", dep->d_name);
	}
	if (errno != 0)
		unix_error("readfile errors");
	
	Closedir(streamp);
	exit(0);
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n) {
	int cnt;

	while (rp->rio_cnt <= 0) {
		rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
		if (rp->rio_cnt < 0) {
			if (errno != EINTR) 
				return -1;
		} else if (rp->rio_cnt == 0)
			return 0;
		else 
			rp->rio_bufptr = rp->rio_buf
	}
	
	cnt = n;
	if (rp->rio_cnt < n) 
	cnt = rp->rio_cnt;
	memccpy(usrbuf, rp->rio_bufptr, cnt);
	rp->rio_bufptr += cnt;
	rp->rio_cnt -= cnt;
	return cnt;
}