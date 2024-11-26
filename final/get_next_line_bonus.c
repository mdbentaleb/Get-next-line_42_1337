/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:50:55 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/26 17:48:55 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_append(char **str, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		br;

	if (!*str)
		*str = ft_strdup("");
	br = 1;
	while (br != 0 && (ft_strchr(*str, '\n') == NULL))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br < 0)
		{
			free(*str);
			return (NULL);
		}
		buffer[br] = '\0';
		*str = ft_strjoin(*str, buffer);
	}
	return (*str);
}

char	*gl(char *line)
{
	char	*tmp;
	int		i;

	if (ft_strlen(line) == 0)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	tmp = ft_substr(line, 0, i);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*dikchi_lib9a(char *rest)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	if (rest[i] == '\0')
	{
		free(rest);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(rest + i) + 1));
	if (!tmp)
		return (NULL);
	while (rest[i])
		tmp[j++] = rest[i++];
	tmp[j] = '\0';
	free(rest);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = read_append(&rest[fd], fd);
	if (!rest[fd])
		return (NULL);
	line = gl(rest[fd]);
	if (!line)
	{
		free(rest[fd]);
		rest[fd] = NULL;
		return (NULL);
	}
	rest[fd] = dikchi_lib9a(rest[fd]);
	return (line);
}
