#include "../includes/minishell.h"

static void			free_tokens(char **tokens)
{
	int 			i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		tokens[i] = NULL;
		i++;
	}
	free(tokens);
	tokens = NULL;
}

static bool			manage_echo(char **coms, int i)
{
	char 			*l;

	l = delete_leading_zeros_and_tabs(coms[i]);
	if (!ft_strncmp(l, "echo ", 5) || !ft_strncmp(l, "echo\t", 5) ||
		!ft_strcmp(l, "echo"))
	{
		echo(l);
		return (1);
	}
	return (0);
}

static void			exec_coms(char **coms, t_data *data)
{
	int				i;
	char			**tokens;

	i = -1;
	while (coms[++i])
	{
		if (manage_echo(coms, i))
			continue ;
		tokens = parse_one_command(coms[i]);
		if (!tokens)
			return ;
		execute_command(tokens, data);
		free_tokens(tokens);
	}
}

static void			main_loop(t_data *data)
{
	char 			*line;
	char			**coms;

	while (1)
	{
		pwd(1, data);
		write(1, "$ ", 2);
		get_next_line(STDIN_FILENO, &line);
		coms = ft_strsplit(line, ';');
		exec_coms(coms, data);
		free(line);
	}
}

int	main(void)
{
	t_data	data;

	initialize(&data);
	tell_no_warranty();
	main_loop(&data);
	return (0);
}
