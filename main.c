#include "get_next_line.h"

int main()
{
	int fd = open("dummyData.txt", O_CREAT | O_RDWR, 777);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	close(fd);
	return 0;
}