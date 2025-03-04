#ifndef ARG_PARSER_H_
#define ARG_PARSER_H_

#include <linux/types.h>

/*
 *      Parsed arguments for the program.
 */
struct p_args {
	__u8            verbose;          /* Verbose output */
	__u8            command;          /* start | stop */
	*char           if_name;          /* Wireless interface name */
};

void print_usage ( const char *p_name );

/*
 *      Parse arguments taken from command line.
 */
void parse ( int argc, char **argv );

#endif //ARG_PARSER_H_
