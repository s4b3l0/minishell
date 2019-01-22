/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:38:14 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 01:03:08 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

int			is_env(char **env, char *tmp1)
{
	char	*tmp2;
	int		n;

	n = 0;
	while (env[n])
	{
		tmp2 = get_substr(env[n], tmp1);
		if (ft_strequ(tmp1, tmp2))
		{
			FREE(tmp2);
			return (1);
		}
		FREE(tmp2);
		n++;
	}
	return (0);
}

char		**add_elem_array(char **env, char *elem)
{
	int		i;
	char	**d_env;

	i = -1;
	while (env[++i])
		;
	i++;
	d_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
	{
		d_env[i] = ft_strdup(env[i]);
	}
	d_env[i] = ft_strdup(elem);
	d_env[++i] = NULL;
	clean_array(&env);
	return (d_env);
}

int			get_index(char **env, char *tmp1)
{
	char	*tmp2;
	int		n;

	n = 0;
	while (env[n])
	{
		tmp2 = get_substr(env[n], tmp1);
		if (ft_strequ(tmp1, tmp2))
		{
			FREE(tmp2);
			return (n);
		}
		FREE(tmp2);
		n++;
	}
	return (n);
}

void		start_set(t_inp *in)
{
	int		env_index;
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(in->par[1], "=");
	if (is_env(g_env, tmp1))
	{
		env_index = get_index(g_env, tmp1);
		if (g_env[env_index])
		{
			FREE(g_env[env_index]);
			g_env[env_index] = ft_strjoin(tmp1, in->par[2]);
		}
	}
	else
	{
		tmp2 = ft_strjoin(tmp1, in->par[2]);
		g_env = add_elem_array(g_env, tmp2);
		FREE(tmp2);
	}
	FREE(tmp1);
}

void		setenv_builtin(t_inp *in)
{
	if (!in->par[1])
	{
		env_builtin(in);
		in->executed = 1;
		return ;
	}
	else if (in->par[1] || in->par[2])
	{
		start_set(in);
		in->executed = 1;
		return ;
	}
	else
		ft_printf("Usage: %s %s", in->par[0], GUIDE);
	in->executed = 1;
}
