#include "get_next_line.h"

int check_line(int bytes_read, char buffer[])
{
	int i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return -1;
}

char    *get_next_line(int fd)
{
	int         bytes_read;
	char        *line;
	static char *stored_line;
	int         end_line;
	char        buffer[BUFFER_SIZE + 1];
	char		*tmp_buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
	while(1)
	{
		end_line = check_line(ft_strlen(stored_line) - 1, stored_line);
		if (end_line != -1)
		{
			line = ft_substr(stored_line, 0, end_line + 1);
			tmp_buffer = ft_substr(stored_line, end_line + 1, ft_strlen(stored_line) - end_line - 1);
			free(stored_line);
            stored_line = tmp_buffer;
			return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (stored_line)
				free(stored_line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
        if (bytes_read == 0)
        {
			if (stored_line && *stored_line == '\0')
			{
				free(stored_line);
				stored_line = NULL;
				return (NULL);
			}
            tmp_buffer = stored_line;
            stored_line = NULL;
            return (tmp_buffer);
        }
		end_line = check_line(bytes_read, buffer);
		if (end_line != -1)
		{
			tmp_buffer = ft_substr(buffer, 0, end_line + 1);
			line = ft_strjoin(stored_line, tmp_buffer);
			free(tmp_buffer);
			tmp_buffer = ft_substr(buffer, end_line + 1, ft_strlen(buffer) - end_line - 1);
			free(stored_line);
			stored_line = tmp_buffer;
			return (line);
		}
		tmp_buffer = ft_strjoin(stored_line, buffer);
		free(stored_line);
		stored_line = tmp_buffer;
	}
}
