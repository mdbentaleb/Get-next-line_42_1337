#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char *s1 = "hello\nworld";
	// char *s2 = "world";
	char *r = after_new_line(s1);
	
	printf("%s", r);
}