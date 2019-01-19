/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:31:30 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/28 17:59:27 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

void		start_reading(t_inp *in)
{
	int		rdr;
	char	*tmp;

	in->line = ft_strnew(1);
	if ((rdr = read(0, in->buf, BUFF_SIZE)))
	{
		in->buf[rdr] = '\0';
		tmp = ft_strjoin(in->line, in->buf);
		ft_memdel((void *)&in->line);
		in->line = ft_strdup(ft_strtrim(tmp));
		ft_memdel((void *)&tmp);
	}
	else
		exit(0);
}