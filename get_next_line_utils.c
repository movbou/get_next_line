#include "get_next_line.h"
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != (char)c)
	{
		if (*ptr == 0)
			return (NULL);
		ptr++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ss = (char *)malloc(len);
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, s1, ft_strlen(s1) + 1);
	ft_strlcat(ss, s2, len);
	return (ss);
}
