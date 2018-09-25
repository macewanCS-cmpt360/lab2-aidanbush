/* Author: Aidan Bush
 * Lab: 2
 * Question: 7
 * Course: CMPT 360
 * Date: Sept. 25, 18
 * File: q7.c
 * Description: question 7 file
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Question 7
int main(int argc, char **argv)
{
	int pid = fork();

	if (pid < 0) {
		return 1;
	} else if (pid == 0) {
		// child
		close(STDOUT_FILENO);
		printf("Child printing\n");
	} else {
		// parent
		printf("Parent printing\n");
	}

	return 0;
}

/* Questions:
 * What happens if the child calls printf() to print some output after closing
 *  the descriptor?
 *  Nothing is printed and it fails silently.
 */
