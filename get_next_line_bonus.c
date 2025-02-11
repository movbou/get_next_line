#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_reset_lstr(char *lstr)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	// Find the position of the first newline character or null terminator
	while (lstr[i] != 0 && lstr[i] != '\n')
		i++;
	// If the entire string is read without a newline, free the memory and return 0
	if (lstr[i] == 0)
	{
		free(lstr);
		return (0);
	}
	// Allocate memory for the remaining part after the newline
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(lstr) - i + 1));
	if (tmp == 0)
		return (0);  // Return 0 on allocation failure
	i++;  // Skip the newline character
	j = 0;
	// Copy the remaining characters to the new buffer
	while (lstr[i] != 0)
		tmp[j++] = lstr[i++];
	tmp[j] = '\0';  // Null-terminate the new string
	free(lstr);     // Free the old lstr
	return (tmp);   // Return the updated lstr
}
char	*ft_get_line(char *lstr)
{
	char	*tmp;
	int		i;

	i = 0;
	// Return 0 if lstr is empty
	if (lstr[0] == 0)
		return (0);
	// Find the position of the newline character or null terminator
	while (lstr[i] != 0 && lstr[i] != '\n')
		i++;
	// Allocate memory for the extracted line (+2 to account for newline and null terminator)
	tmp = (char *)malloc(i + 2);
	if (tmp == 0)
		return (0);  // Return 0 on allocation failure
	i = 0;
	// Copy characters from lstr up to (but not including) the newline
	while (lstr[i] != 0 && lstr[i] != '\n')
	{
		tmp[i] = lstr[i];
		i++;
	}
	// Include the newline if present
	if (lstr[i] == '\n')
	{
		tmp[i] = lstr[i];
		i++;
	}
	tmp[i] = '\0';  // Null-terminate the string
	return (tmp);   // Return the extracted line
}
char	*ft_get_lstr(int fd, char *lstr)
{
	char	*buffer;
	int		result;

	// Allocate memory for the buffer (+1 for null terminator)
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);  // Return 0 on allocation failure
	result = 1;
	// Keep reading until a newline is found or the read result is 0 (end of file)
	while (ft_strchr(lstr, '\n') == 0 && result != 0)
	{
		// Read from the file descriptor into the buffer
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)  // Handle read errors
		{
			free(buffer);
			return (0);  // Return 0 on read error
		}
		buffer[result] = 0;  // Null-terminate the buffer
		// Append the buffer content to lstr
		lstr = ft_strjoin(lstr, buffer);
	}
	free(buffer);  // Free the buffer after reading
	return (lstr); // Return the updated lstr
}

char	*get_next_line(int fd)
{
	static char	*lstr[1024];
	char		*line;

	// Validate file descriptor and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (0);
	// Read data from file descriptor and store in lstr
	lstr[fd] = ft_get_lstr(fd, lstr[fd]);
	if (!lstr[fd])  // Return 0 if reading failed or there's no data
		return (0);
	// Extract the next line from lstr
	line = ft_get_line(lstr[fd]);
	// Reset lstr to the remaining part after the extracted line
	lstr[fd] = ft_reset_lstr(lstr[fd]);
	return (line);  // Return the extracted line
}
