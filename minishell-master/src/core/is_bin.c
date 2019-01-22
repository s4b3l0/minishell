/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:44:44 by sankosi           #+#    #+#             */
/*   Updated: 2018/10/28 13:49:12 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

int		is_executable(struct stat f, t_inp *in)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (exec_bin(in));
		else
		{
			ft_putstr("minishell: permission denied: ");
			ft_putendl(in->cmd);
		}
		return (1);
	}
	return (0);
}

char	**get_prog_path(void)
{
	int		n;
	char	**res;
	char	*tmp;

	if (is_env(g_env, "PATH="))
	{
		n = get_index(g_env, "PATH=");
		tmp = ft_strdup(&g_env[n][5]);
		if (tmp)
			res = ft_strsplit(tmp, ':');
		FREE(tmp);
		return (res);
	}
	else
		return (NULL);
}

void	is_bin(t_inp *in, char **paths)
{
	int			i;
	char		*tmp;
	struct stat	f;

	i = 0;
	while (paths && paths[i] != NULL)
	{
		if (ft_strstartswith(in->par[0], paths[i]))
			in->cmd = ft_strdup(in->par[0]);
		else
		{
			tmp = ft_strjoin(paths[i], "/");
			in->cmd = ft_strjoin(tmp, in->par[0]);
			FREE(tmp);
		}
		if (lstat(in->cmd, &f) == -1)
			FREE(in->cmd);
		else
		{
			is_executable(f, in);
			return ;
		}
		i++;
	}
	ft_printf("minishell: command not found: %s\n", in->par[0]);
}
