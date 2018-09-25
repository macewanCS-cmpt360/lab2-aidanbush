/* Author: Aidan Bush
 * Lab: 2
 * Question: 2
 * Course: CMPT 360
 * Date: Sept. 25, 18
 * File: q2.c
 * Description: question 2 file
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

// Question 2
int main(int argc, char **argv)
{
	int fd = open("del", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	int pid = fork();

	if (pid < 0) {
		fprintf(stderr, "ERROR in fork %d\n", pid);
		return 1;
	} else if (pid == 0) {
		// child
		printf("I'm the Child, I will write to the file!\n");
		dprintf(fd, "Child writing to file\n");
	} else {
		// parent
		printf("I'm the Parent of %d, I will write to the file!\n",
			pid);
		dprintf(fd, "Parent writing to file\n");
	}

	fsync(fd);
	close(fd);

	return 0;
}

/* Other questions:
 * Can both the child and parent access the file descriptor returned by open()?
 *  Both the parent and child can access the file descriptor.
 * What happens when they are writing to the file concurrently, i.e., at the
 *  same time?
 *  When both the parent and child are writing to the same file descriptor they
 *  can run into a threading issue where the writes and intertwined. It may be
 *  possible to limit the effects of this by using a single write call for each
 *  message you want not intertwined with another write.
 */
