/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:10:23 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 01:37:14 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"
#include <string.h>

int			exec_bin(t_inp *in)
{
	in->pid = fork();
	if (in->pid == 0)
		execve(in->cmd, in->par, g_env);
	else if (in->pid < 0)
	{
		ft_printf("Fork fail");
		return (-1);
	}
	wait(&in->pid);
	return (42);
}

int			ex_builtins(t_inp *in)
{
	in->executed = 0;
	if (ft_strequ(in->cmd, "exit"))
		return (-1);
	else if (ft_strequ(in->cmd, "env"))
		env_builtin(in);
	else if (ft_strequ(in->cmd, "echo"))
		echo_buitin(in);
	else if (ft_strequ(in->cmd, "setenv"))
		setenv_builtin(in);
	else if (ft_strequ(in->cmd, "unsetenv"))
		unsetenv_builtin(in);
	else if (ft_strequ(in->cmd, "cd"))
		cd_builtin(in);
	return (0);
}

int			exec(t_inp *in)
{
	int			ret;
	char		**paths;
	struct stat	f;

	ret = 0;
	ret = ex_builtins(in);
	if (in->executed != 1 && ret != -1 && in->par[0])
	{
		paths = get_prog_path();
		if (lstat(in->cmd, &f) != -1)
			is_executable(f, in);
		else if (paths)
		{
			FREE(in->cmd);
			is_bin(in, paths);
			(paths) ? clean_array(&paths) : 0;
			return (ret);
		}
		else
			ft_printf("minishell: command not found: %s\n", in->par[0]);
	}
	in->executed = 0;
	return (ret);
}
