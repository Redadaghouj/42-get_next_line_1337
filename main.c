#include "get_next_line.h"

int main()
{
    int fd = open("dummyData.txt", O_CREAT | O_RDWR, 777);
    // char *s = get_next_line(fd);
    printf("%s\n", get_next_line(fd));
    return 0;
}