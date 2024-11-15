//#include "get_next_line.h"
#include "header-main.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*con;
	char		*ptr;
	int			r;

	r = 1;
	ptr = calloc(1, 1);
	if (con)
		ptr = ft_strjoin(con, ptr);
	while (r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		buf[r] = '\0';
		ptr = ft_strjoin(ptr, buf);
		if (new_line(ptr))
			break ;
	}
	con = get_last_line(ptr);
	return (get_line(ptr));
}


int main()
{
	int f = open("med.txt", O_RDONLY);

	char *s = get_next_line(f);
	printf("%s", s);
	s = get_next_line(f);
	printf("%s", s);
}
