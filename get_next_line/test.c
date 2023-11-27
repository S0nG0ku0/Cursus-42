#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	BUFFER_SIZE = 30;

int	main(void)
{
	int 	fd;
	ssize_t bytes_read;
	char 	b[BUFFER_SIZE + 1];
	int 	i;

	fd = open("./text.txt", O_RDONLY);
	i = 0;
	while ((bytes_read = read(fd, b, BUFFER_SIZE)) > 0)
	{
		for (int j = 0; j < bytes_read; j++)
		{
			if (b[j] != '\n')
			{
				write(1, &b[j], 1);
			}
		}
		close(fd);
	}
}
