
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
