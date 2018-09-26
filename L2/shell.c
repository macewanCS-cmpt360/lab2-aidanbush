/* Author: Aidan Bush
 * Lab: 2
 * Question: shell.c
 * Course: CMPT 360
 * Date: Sept. 25, 18
 * File: shell.c
 * Description: interactive shell file
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include <sys/wait.h>

#define MAX_CMD_LEN 1024

int main(void)
{
	bool done = false;
	bool back;
	int i, pid;
	char *cmdline;
	char *token = NULL;
	char *args[10];

	cmdline = calloc(1, MAX_CMD_LEN);

	while (!done) {
		i = 0;
		back = false;

		printf("prompt> ");
		fgets(cmdline, MAX_CMD_LEN, stdin);

		token = strtok(cmdline, "\n ");
		while (token != NULL) {
			args[i++] = strdup(token);
			token = strtok(NULL, "\n ");
		}

		args[i] = NULL;

		// if no command entered reprompt
		if (i == 0)
			continue;

		// if put in background set back to true, and remove & from args
		if (strnlen(args[i-1], MAX_CMD_LEN) == 1
			&& args[i-1][0] == '&') {
			back = true;
			args[i-1] = NULL;
		}

		//fork
		pid = fork();

		if (pid < 0) {
			// error
			fprintf(stderr, "Cannot create process\n");
			return 1;
		} else if (pid == 0) {
			// child
			execvp(args[0], args);
			return 1;
		}
		// parent

		// check if need to wait for it to complete
		if (!back)
			wait(NULL);
	}
	free(cmdline);
}
