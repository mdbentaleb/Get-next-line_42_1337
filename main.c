#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int f = open("med.txt", O_RDONLY);
	if (f == -1)
	{
    	printf("error opening file\n");
    	return 1;
	}

	char *s = get_next_line(f);

	printf("%s\n", s);
}