
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char    *buffer;
	int fd;
	fd = open ("youngfolks.text", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s", buffer);
	free(buffer);
	close(fd);
	return (0);
}
