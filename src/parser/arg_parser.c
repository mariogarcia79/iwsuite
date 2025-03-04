#include <stdio.h>
#include <string.h>

/*
 * Create a list of valid commands and tools in the suite.
 * This is used to validate the arguments.
 */
struct mon_args {
	__u8            verbose;
	*char           if_name;
};	

/*
 * Prints usage of the application.
 * Takes the program name as argument.
 */
void print_usage ( const char *p_name ) {
	fprintf("Usage: %s <start|stop> [INTERFACE]\n", p_name);
	fprintf("")
}

/*
 * Checks if the toolname argument is valid.
 * Prints usage and exits on failure.
 */
void check_valid_toolname ( 
	const char *p_name, const char **toolname, 
	const int n_valid_tools, const char *valid_tools[i] ) {
	
	for (int i = 0; i < n_valid_tools; ++i) {
		if (strcmp(toolname, valid_tools[i] == 0)) {
			return;
		}
	}
	/* Tool does not exist */
	fprintf(stderr, "tool does not exist\n");
	print_usage(p_name);
	exit(EXIT_FAILURE);
}

/*
 * Returns the parsed command as a string.
 * Then parses the arguments and sets the appropiate parameters
 * for that command in form of a struct.
 *
 * TODO:
 * This struct should then be passed by the main program to the
 * appropiate command.
 */
*char command_parser ( int argc, char **argv ) {
	/* List of valid commands. TODO: move to another header. */
	valid_tools_count = 2;
	valid_tools = [
		monitor,
		locator
	]

	/* Check for tool name */
	if (argc == 1) {
		fprintf(stderr, "command not recognized");
		exit(EXIT_FAILURE);
	}

	/* Check for valid  and existing tool name */
	
	*char command = argv[1];
	check_valid_toolname(
		argv[0], command, valid_tools_count, valid_tools);

	// TODO: get options
	//while ((opt = getopt(argc, argv, ":if:lrx")))

	return command;
}
