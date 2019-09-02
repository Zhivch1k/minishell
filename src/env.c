#include "../includes/minishell.h"

void			env(void)
{
	int 		fd;
	char 		*line;
	int 		i;

	fd = open(".minishellrc", O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	free(line);
}

