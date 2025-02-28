#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>

#include "scanner/iw_mon_man.h"
#include "scanner/iw_req.h"
#include "scanner/iw_scan.h"


int main (int argc, char **argv) {
	const char *iface;
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	if (argc < 2) {
		fprintf(stderr, "invalid argument count\n");
		exit(EXIT_FAILURE);
	}
	iface = argv[1];

	if_unset_monitor_mode(sockfd, iface);

	close(sockfd);
	return 0;
}
