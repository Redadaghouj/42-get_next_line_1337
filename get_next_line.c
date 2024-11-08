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

// char *extract_line(char *next_line, char buffer[], int end_line)
// {
//     char *line = ft_substr(buffer, 0, end_line);
//     return (line);
// }

void get_ready()
{}

char    *get_next_line(int fd)
{
    int byte_read;
    char *line;
    static char *next_line;
    int end_line;

    char buffer[BUFFER_SIZE];
    *next_line = '\0';
    byte_read = read(fd, buffer, BUFFER_SIZE);
    while(1)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        end_line = check_line(byte_read, buffer);
        if (end_line != -1)
        {
            // line = extract_line(next_line, buffer, end_line);
            // get_ready();
            return (ft_substr(buffer, 0, end_line));
            // break;
        }
        
    }
    return line;
}