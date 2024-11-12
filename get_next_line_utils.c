#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2, int byte_read)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = -1;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && *s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0' && byte_read == 0)
		str[i++] = *s2++;
	while (++j < byte_read)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	// size_t	size;
	char	*str;

	if (start > ft_strlen(s) || s[0] == '\0')
		return (ft_strdup(""));
	// size = ft_strlen(s + start);
	// if (len > size)
	// 	len = size;
	str = (char *) malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}