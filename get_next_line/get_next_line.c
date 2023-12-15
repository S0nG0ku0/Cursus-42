#include <libc.h>
#include "get_next_line.h"



char *get_next_line(int fd)
{
    ssize_t bytes_read;
    char *b = NULL;
	static char *rest = NULL;
	char *tmp = NULL;
    if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(rest);
        return (NULL);
    }
	char *line = malloc(1);
	*line = '\0';
	int i = 0;
	int k = 0;
	bytes_read = 1;
    while (bytes_read > 0)
    {
		b = (char *)calloc((size_t)BUFFER_SIZE + 1, 1);
		bytes_read = read(fd, b, BUFFER_SIZE);
		b[BUFFER_SIZE] = '\0';
		if (rest)
		{
			b = ft_strjoin(rest, b);
			rest = NULL;
			tmp = calloc(ft_strlen(line) + ft_strlen(b) + 1, 1);
			tmp[ft_strlen(line) + ft_strlen(b)] = '\0';
		}
		else
		{
			tmp = malloc(ft_strlen(line) + bytes_read + 1);
			tmp[ft_strlen(line) + bytes_read] = '\0';
		}
		i = 0;
		while (line[i] != '\0')
		{
			tmp[k] = line[i];
			i++;
			k++;
		}
		i = 0;
		while (b[i] != '\0' && b[i] != '\n')
		{
			tmp[k] = b[i];
			i++;
			k++;
		}
		if (b[i] == '\n')
            tmp[k] = '\n';
		free(line);
		line = tmp;
		k = 0;
		if (b[i] == '\n' || bytes_read == 0)
        {
            if (bytes_read == 0 && *line == '\0')
            {
                free(tmp), tmp = NULL;
                free(b), b = NULL;
                return (NULL);
            }
			rest = ft_getleast(b);
			break ;
		}
		free(b), b = NULL;
	}
	return (line);
}
