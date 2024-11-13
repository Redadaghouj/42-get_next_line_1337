#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// # define BUFFER_SIZE 10

char    *get_next_line(int fd);
size_t	ft_strlen(const char *s);
int     check_line(int byte_read, char buffer[]);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
	

#endif