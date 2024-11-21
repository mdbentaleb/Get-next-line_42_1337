#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd1 = open("test-1.txt", O_RDONLY);
	// int fd2 = open("test-2.txt", O_RDONLY);
	// int fd3 = open("test-3.txt", O_RDONLY);

	char *s;

	s = get_next_line(fd1);
	printf("%s", s);
	free (s);


	s = get_next_line(fd1);
	printf("%s", s);
	free (s);




	s = get_next_line(fd1);
	printf("%s", s);
	free (s);




	s = get_next_line(fd1);
	printf("%s", s);
	free (s);




}