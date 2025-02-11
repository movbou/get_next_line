
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stddef.h> 
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 7 
#endif 

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_lstr(int fd, char *lstr);
char	*ft_get_line(char *lstr);
char	*ft_reset_lstr(char *lstr);
char	*get_next_line(int fd);

#endif
