#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("med.txt", O_RDONLY);
	char *s ;
	while (s != '\0')
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
}