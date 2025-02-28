#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>

#include <linux/types.h>
#include <linux/wireless.h>



struct iwreq iwreq_set_if ( const char *iface ) {
	struct iwreq req;
	/* Initialize struct iwreq with 0s */
	memset(&req, 0, sizeof(struct iwreq));
	/* Set the ifname */
	strncpy(req.ifr_name, iface, IFNAMSIZ);
	return req;
}

void if_set_monitor_mode ( int sockfd, const char *iface ) {
	/* Set interface name */
	struct iwreq req = iwreq_set_if(iface);
	__u32  iwmode;
	
	/* Get current mode */
	if ((iwmode = ioctl(sockfd, SIOCGIWMODE, &req)) == (__u32)-1) {
		perror("SIOCGIWMODE");
		exit(EXIT_FAILURE);
	} /*else if (iwmode = IW_MODE_MONITOR) {
		fprintf(stderr, 
			"radio device already in monitor mode\n");
		exit(EXIT_FAILURE);
	}*/

	/* Set monitor mode */
	req.u.mode = IW_MODE_MONITOR;
	if (ioctl(sockfd, SIOCSIWMODE, &req) == -1) {
		perror("SIOCSIWMODE");
		exit(EXIT_FAILURE);
	}
}

void if_unset_monitor_mode ( int sockfd, const char *iface ) {
	/* Set interface name */
	struct iwreq req = iwreq_set_if(iface);
	__u32  iwmode;
	
	/* Get current mode */
	if ((iwmode = ioctl(sockfd, SIOCGIWMODE, &req)) == (__u32)-1) {
		perror("SIOCGIWMODE");
		exit(EXIT_FAILURE);
	} /*else if (iwmode = IW_MODE_INFRA) {
		fprintf(stderr,
			"radio device already in managed mode\n");
		exit(EXIT_FAILURE);
	}*/

	/* Set AUTO mode.
	 * In this mode, the driver decides what mode to set. */
	req.u.mode = IW_MODE_INFRA;
	if (ioctl(sockfd, SIOCSIWMODE, &req) == -1) {
		perror("SIOCSIWMODE");
		exit(EXIT_FAILURE);
	}
}
