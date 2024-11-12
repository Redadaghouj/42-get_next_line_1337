#include "get_next_line.h"

int check_line(int byte_read, char buffer[])
{
	int i;

	i = 0;
	while (i < byte_read)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return -1;
}

char    *get_next_line(int fd)
{
	int         byte_read;
	char        *line;
	char        *what_left_line;
	static char *save_lines;
	int         end_line;
	char        buffer[BUFFER_SIZE];

	while(1)
	{
		end_line = check_line(ft_strlen(save_lines) - 1, save_lines);
		if (end_line != -1)
		{
			line = ft_substr(save_lines, 0, end_line + 1);
			save_lines = ft_substr(save_lines, end_line + 1, ft_strlen(save_lines));
			return (line);
		}
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == 0)
			return (save_lines);
		end_line = check_line(byte_read, buffer);
		if (end_line != -1)
		{
			what_left_line = ft_substr(buffer, end_line + 1, ft_strlen(buffer));
			line = ft_substr(buffer, 0, end_line + 1);
			line = ft_strjoin(save_lines, line, ft_strlen(line));
			save_lines = ft_strdup(what_left_line);
			what_left_line = ft_strdup("");
			break ;
		}
		save_lines = ft_strjoin(save_lines, buffer, byte_read);
	}
	return (line);
}
