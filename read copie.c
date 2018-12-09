#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char **line;
	int fd;
	int i;

	argc = 1;
	i = 1;
	line = (char**)malloc(sizeof(char*));
	*line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, line))
			printf("%d, %s.\n", i++, *line);
	return (0);
}
