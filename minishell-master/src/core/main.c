/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:11:31 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/12 10:17:55 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

void	initenv(char **en, t_inp *in)
{
	g_env = dup_array(en);
	(in->started == 0) ? update_shlvl() : NULL;
	in->started = 1;
}

int		main(int c, char **av, char **en)
{
	t_inp		in;

	in.started = 0;
	initenv(en, &in);
	prompt_handler(en, in);
	return (0);
}
