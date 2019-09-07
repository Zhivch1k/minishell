/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:29:44 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/09/07 12:29:46 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void			env(void)
{
	int 		fd;
	char 		*line;
	int 		i;

	line = NULL;
	fd = open(".minishellrc", O_RDONLY);
	while ((i = get_next_line(fd, &line)) == 1)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
