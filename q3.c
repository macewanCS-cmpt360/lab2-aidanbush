/* Author: Aidan Bush
 * Lab: 2
 * Question: 3
 * Course: CMPT 360
 * Date: Sept. 25, 18
 * File: q3.c
 * Description: question 3 file
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Question 2
int main(int argc, char **argv)
{
	int pid = fork();

	if (pid < 0) {
		return 1;
	} else if (pid == 0) {
		// child
		printf("Hello\n");
	} else {
		// parent
		wait(NULL);
		printf("Goodbye\n");
	}

	return 0;
}

/* Other questions:
 * Can you do this without calling wait() in the parent?
 *  Yes if you use a method of inter-process communication such as a pipe or
 *  unix domain socket.
 */
