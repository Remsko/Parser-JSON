#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "json.h"
#include "debug.h"

# define BUFF_SIZE 4096

char	*strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if (!(ret = (char*)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1))))
			return (NULL);
		strcpy(ret, s1);
		strcat(ret, s2);
	}
	return (ret);
}

char	*read_file(int fd)
{
	int	ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	
	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = NULL;
		if (str)
		{
			tmp = strdup(str);
			free(str);
			str = strjoin(tmp, buf);
			free(tmp);
		}
		else
			str = strdup(buf);
	}
	if (ret == -1)
		free(str);
	return (str);
}

int	main(int ac, char **av)
{
	int		fd;
	char		*full_file;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	full_file = read_file(fd);
	json_print_value(json_parse(full_file));
	printf("\n\n%s\n", full_file);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
