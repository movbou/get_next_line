
char	*ft_get_lstr(int fd, char *lstr)
{
	char	*buffer;
	int		result;

	// Allocate memory for the buffer (+1 for null terminator)
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	static char	*lstr;
	char		*line;

	// Validate file descriptor and buffer size
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// Read data from file descriptor and store in lstr
	lstr = ft_get_lstr(fd, lstr);
	if (!lstr)  // Return 0 if reading failed or there's no data
		return (0);
	// Extract the next line from lstr
	line = ft_get_line(lstr);
	// Reset lstr to the remaining part after the extracted line
	lstr = ft_reset_lstr(lstr);
	return (line);  // Return the extracted line
}
