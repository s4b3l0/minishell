/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:23:35 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 01:23:11 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

int			get_len(char **arr)
{
	int		n;

	n = -1;
	while (arr[++n] != NULL)
		;
	return (n);
}

char		**arr_pushup(char **env, int n)
{
	char	**tmp;
	int		i;
	int		len;

	len = -1;
	i = -1;
	R_ISNULL(env, n);
	len += get_len(env);
	tmp = (char **)malloc(sizeof(char *) * (len + 1));
	tmp[len] = NULL;
	len = 0;
	while (env[++i] != NULL)
	{
		if (i != n)
		{
			tmp[len] = ft_strdup(env[i]);
			len++;
		}
	}
	clean_array(&env);
	return (tmp);
}

void		start_unset(t_inp *in)
{
	int		env_index;
	char	*tmp1;

	tmp1 = ft_strjoin(in->par[1], "=");
	if (is_env(g_env, tmp1))
	{
		env_index = get_index(g_env, tmp1);
		if (g_env[env_index])
		{
			g_env = arr_pushup(g_env, env_index);
		}
	}
	FREE(tmp1);
	return ;
}

void		unsetenv_builtin(t_inp *in)
{
	if (!in->par[1])
		ft_printf("Usage: %s %s", in->par[0], GUIDE);
	else if (!in->par[2])
		start_unset(in);
	else
		ft_printf("Usage: %s %s", in->par[0], GUIDE);
	in->executed = 1;
}
