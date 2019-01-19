/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:17:13 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/28 18:05:49 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

static void			grab_command(t_inp *in)
{
	in->cmd = ft_strdup(in->par[0]);
}

static void			grab_pars(t_inp *in)
{
	in->par = tokenize(in->line);
}

void				argument_handler(t_inp *in)
{
	grab_pars(in);
	grab_command(in);
}
