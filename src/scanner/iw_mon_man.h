#ifndef IFMON_MAN_H_
#define IFMON_MAN_H_

struct iwreq iwreq_set_if ( const char *iface );

void if_set_monitor_mode ( int sockfd, const char *iface );
void if_unset_monitor_mode ( int sockfd, const char *iface );

#endif //IFMON_MAN_H_
