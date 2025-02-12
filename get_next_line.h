/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achajar <achajar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:43:29 by achajar           #+#    #+#             */
/*   Updated: 2025/02/12 01:43:31 by achajar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7 
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h> 

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_lstr(int fd, char *lstr);
char	*ft_get_line(char *lstr);
char	*ft_reset_lstr(char *lstr);
char	*get_next_line(int fd);

#endif
