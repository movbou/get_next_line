
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif 


char	*ft_get_lstr(int fd, char *lstr)
char	*ft_get_line(char *lstr)
char	*ft_reset_lstr(char *lstr)
char	*get_next_line(int fd)

#endif
