/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaghouj <mdaghouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:24:11 by mdaghouj          #+#    #+#             */
/*   Updated: 2024/11/21 09:24:02 by mdaghouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_newline(char **stored, int end_line, char **buffer, int flag)
{
	char	*tmp_buff;
	char	*line;

	if (flag)
	{
		tmp_buff = ft_substr(*buffer, 0, end_line + 1);
		line = ft_strjoin(*stored, tmp_buff);
		free(tmp_buff);
		tmp_buff = ft_substr(*buffer, end_line + 1,
				ft_strlen(*buffer) - end_line - 1);
	}
	else
	{
		line = ft_substr(*stored, 0, end_line + 1);
		tmp_buff = ft_substr(*stored, end_line + 1,
				ft_strlen(*stored) - end_line - 1);
	}
	free(*stored);
	*stored = tmp_buff;
	free(*buffer);
	return (line);
}

char	*end_of_file(char **buffer, char **stored)
{
	char	*tmp_buff;

	free(*buffer);
	if (*stored && **stored == '\0')
	{
		free(*stored);
		*stored = NULL;
		return (NULL);
	}
	tmp_buff = *stored;
	*stored = NULL;
	return (tmp_buff);
}

char	*free_vars(char **stored, char **buffer, int flag)
{
	char	*tmp_buff;

	if (flag)
	{
		free(*stored);
		*stored = NULL;
		free(*buffer);
	}
	else
	{
		tmp_buff = ft_strjoin(*stored, *buffer);
		free(*stored);
		*stored = tmp_buff;
	}
	return (NULL);
}

int	check_error(char **buffer, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	*buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*buffer == NULL)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*stored[10240];
	int			end_line;
	char		*buffer;

	end_line = -1;
	if (!check_error(&buffer, fd))
		return (NULL);
	while (1)
	{
		if (stored[fd])
			end_line = check_line(ft_strlen(stored[fd]) - 1, stored[fd]);
		if (end_line != -1)
			return (find_newline(&stored[fd], end_line, &buffer, 0));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_vars(&stored[fd], &buffer, 1));
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			return (end_of_file(&buffer, &stored[fd]));
		end_line = check_line(bytes_read, buffer);
		if (end_line != -1)
			return (find_newline(&stored[fd], end_line, &buffer, 1));
		free_vars(&stored[fd], &buffer, 0);
	}
}
