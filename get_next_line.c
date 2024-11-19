#include "get_next_line.h"

char	*read_append(char *rest, char *buf, int fd)
{
	char	*tmp;
	int		br;

	br = 1;
	while (br)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
			return (0);
		else if (br == 0)
			break ;
		buf[br] = '\0';
		if (!rest)
			rest = ft_strdup("");
		tmp = rest;
		rest = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (rest);
}

char	*dikchi_lib9a(char *line)
{
	char	*rest;
	size_t	count;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	rest = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (rest[0] == '\0')
	{
		free(rest);
		rest = NULL;
	}
	line[count + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rest;

	if (fd < 0 || fd <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = read_append(rest, buffer, fd);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (0);
	rest = dikchi_lib9a(line);
	return (line);
}
