/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:03:18 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 02:02:19 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

int			countspace(char *str)
{
	int		i;

	i = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

void		get_value(char *str)
{
	char	*tmp;
	int		n;

	n = 0;
	tmp = ft_strjoin(str, "=");
	if (is_env(g_env, tmp))
	{
		n = get_index(g_env, tmp);
		ft_printf("%s", ft_strchr(g_env[n], '=') + 1);
	}
	FREE(tmp);
}

void		echo_loop(char *tmp, t_inp *in)
{
	int		i;
	int		n;
	char	*tmp2;

	i = 0;
	n = countspace(ft_strchr(in->line, ' '));
	while (tmp[++i] != '\0')
	{
		n = 0;
		if (tmp[i] == '$')
		{
			i++;
			while (!ft_isspace(tmp[i + n]) && tmp[i + n] != '\0')
				n++;
			tmp2 = ft_strsub(tmp, i, n);
			get_value(tmp2);
			ft_memdel((void *)&tmp2);
			i += (n - 1);
		}
		else
		{
			(tmp[i] != '"') ? (ft_putchar(tmp[i])) : NULL;
		}
	}
}

void		echo_buitin(t_inp *in)
{
	char	*tmp;
	int		n;
	int		i;

	i = -1;
	if (in->par[1])
	{
		tmp = (ft_strchr(in->line, ' '));
		echo_loop(tmp, in);
	}
	ft_putchar('\n');
	in->executed = 1;
}
