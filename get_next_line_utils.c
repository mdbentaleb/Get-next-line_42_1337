/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:02:59 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/16 19:47:17 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*memalloc(size_t count, size_t size)
{
	void	*tmp;

	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*tmp;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len == 0 && s2_len == 0)
		return (NULL);
	tmp = memalloc(s1_len + s2_len + 1, 1);
	i = 0;
	while (i < s1_len)
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < s1_len + s2_len)
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char	*before_new_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	tmp = memalloc(i + 2, 1);
	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
	{
		tmp[j] = line[j];
		j++;
	}
	if (line[j] == '\n')
	{
		tmp[j] = '\n';
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*after_new_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[j] != '\0')
		j++;
	if (j - i <= 0)
		return (NULL);
	tmp = memalloc((j - i) + 1, 1);
	k = 0;
	while (line[i] != '\0')
		tmp[k++] = line[i++];
	tmp[k] = '\0';
	return (tmp);
}
