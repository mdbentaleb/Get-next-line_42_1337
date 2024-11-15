/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:31:02 by moben-ta          #+#    #+#             */
/*   Updated: 2024/11/15 15:32:56 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen (s1);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ft_memmove(tmp, s1, len);
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	tmp = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, s1_len + 1);
	ft_strlcat(tmp + s1_len, s2, s2_len + 1);
	return (tmp);
}
