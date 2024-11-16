/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:03:20 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/16 17:03:21 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	char	*remain;
	int		br;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	if (remain)
		line = ft_strjoin(remain, line);
	br = 1;
	while (br > 0)
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br < 0)
			return (NULL);
		buffer[br] = '\0';
		line = ft_strjoin(line, buffer);
		if (check_new_line(line))
			break ;
	}
	remain = after_new_line(line);
	return (before_new_line(line));
}
