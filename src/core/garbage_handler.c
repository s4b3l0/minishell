/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:07:43 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/24 19:13:34 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

void		arr_del(char **arr)
{
	while (*arr != NULL)
	{
		(*arr) ? ft_memdel((void *)arr) : NULL;
		arr++;
	}
}

void		clean_array(char ***str)
{
	if (str)
		arr_del(*str);
	ft_memdel((void *)str);
}

void		tidy_up(t_inp *in)
{
	ft_memdel((void *)&in->line);
	(in->cmd) ? ft_memdel((void *)&in->cmd) : 0;
	clean_array(&in->par);
}
