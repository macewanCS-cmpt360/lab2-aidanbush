/* Author: Aidan Bush
 * Lab: 2
 * Question: 1
 * Course: CMPT 360
 * Date: Sept. 25, 18
 * File: q1.c
 * Description: question 1 file
 */

#include <stdio.h>
#include <unistd.h>

// Question 1
int main(int argc, char **argv)
{
	int i = 100;

	int pid = fork();

	if (pid < 0) {
		fprintf(stderr, "ERROR in fork %d\n", pid);
		return 1;
	} else if (pid == 0) {
		// child
		printf("I'm the Child and my number is %d!\n", i);
	} else {
		// parent
		printf("I'm the Parent of %d and my number is %d!\n", pid, i);
	}

	return 0;
}

/* Other questions:
 * What value is the variable in the child process?
 *  The variable will have the exact same value as it was assigned before the
 *  child was created.
 * What happens to the variable when both the child and parent change the value
 *  of x?
 *  Since the address space is copied to the child process the child will have
 *  all the same variables and values as it's parent.
 */
