/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:27:16 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/28 14:00:50 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

void	do_prompt(void)
{
	static	int started = 0;

	if (started == 0)
	{
		write(STDERR_FILENO, CLEAR_TERM, 12);
		started = 1;
	}
	ft_printf("$> ");
}

void	out(char ***lines)
{
	clean_array(&g_env);
	clean_array(lines);
	exit(EXIT_SUCCESS);
}

void	prompt_handler(char **en, t_inp in)
{
	int			res;
	char		**lines;
	int			n;

	do_prompt();
	n = 0;
	start_reading(&in);
	if (in.line && ft_strlen(in.line) > 0)
	{
		lines = ft_strsplit(in.line, ';');
		FREE(in.line);
		while (lines && lines[n] != NULL)
		{
			in.line = ft_strdup(lines[n]);
			argument_handler(&in);
			res = exec(&in);
			tidy_up(&in);
			(res == -1) ? out(&lines) : NULL;
			n++;
		}
		clean_array(&lines);
	}
	(res != -1) ? (prompt_handler(en, in)) : NULL;
}
