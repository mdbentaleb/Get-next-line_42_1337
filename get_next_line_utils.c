#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

int	check_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line)
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*after_new_line(char *line)
{
	char	*tmp;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (!(tmp = malloc(i + 2)))
		return NULL;
	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
	{
		tmp[j] = line[j];
		j++:
	}
	if (line[j] == '\n')
	{
		tmp[j] = '\n';
		j++;
	}
	tmp[j] = '\0';
	free(line);
	return (tmp);
}
