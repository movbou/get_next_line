/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <achajar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:43:24 by achajar           #+#    #+#             */
/*   Updated: 2025/02/12 01:43:28 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
char	*ft_reset_lstr(char *lstr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (lstr[i] != 0 && lstr[i] != '\n')
		i++;
	if (lstr[i] == 0)
	{
		free(lstr);
		return (0);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(lstr) - i + 1));
	if (tmp == 0)
		return (0);
	i++;
	j = 0;
	while (lstr[i] != 0)
		tmp[j++] = lstr[i++];
	tmp[j] = '\0';
	free(lstr);
	return (tmp);
}

char	*ft_get_line(char *lstr)
{
	char	*tmp;
	int		i;

	i = 0;
	if (lstr[0] == 0)
		return (0);
	while (lstr[i] != 0 && lstr[i] != '\n')
		i++;
	tmp = (char *)malloc(i + 2);
	if (tmp == 0)
		return (0);
	i = 0;
	while (lstr[i] != 0 && lstr[i] != '\n')
	{
		tmp[i] = lstr[i];
		i++;
	}
	if (lstr[i] == '\n')
	{
		tmp[i] = lstr[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_get_lstr(int fd, char *lstr)
{
	char	*buffer;
	int		result;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == 0)
		return (0);
	result = 1;
	while (ft_strchr(lstr, '\n') == 0 && result != 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[result] = 0;
		lstr = ft_strjoin(lstr, buffer);
	}
	free(buffer);
	return (lstr);
}

char	*get_next_line(int fd)
{
	static char	*lstr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lstr = ft_get_lstr(fd, lstr);
	if (!lstr)
		return (0);
	line = ft_get_line(lstr);
	lstr = ft_reset_lstr(lstr);
	return (line);
}
