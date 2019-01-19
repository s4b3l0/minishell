/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 08:57:53 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 02:46:25 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

void		do_change(char *par, int print)
{
	char	**tmp;
	int		n;

	n = 0;
	if (chdir(par))
	{
		ft_printf("Minishell: cd: %s: No such file or directory\n", par);
	}
	else
	{
		tmp = (char **)malloc(sizeof(char *) * 3);
		tmp[2] = 0;
		n = get_index(g_env, "PWD=");
		tmp[0] = ft_strdup(&g_env[n][4]);
		FREE(g_env[n]);
		tmp[1] = getcwd(NULL, 0);
		g_env[n] = ft_strjoin("PWD=", tmp[1]);
		(print == 1) ? ft_printf("%s\n", tmp[1]) : 0;
		n = get_index(g_env, "OLDPWD=");
		FREE(g_env[n]);
		g_env[n] = ft_strjoin("OLDPWD=", tmp[0]);
		clean_array(&tmp);
	}
}

char		**join_home(char **str, int n)
{
	char	*tmp;

	tmp = ft_strjoin("/home", &str[1][1]);
	FREE(str[1]);
	str[1] = ft_strdup(tmp);
	FREE(tmp);
	return (str);
}

void		alt_dir(void)
{
	int		i;

	if (is_env(g_env, "OLDPWD="))
	{
		i = get_index(g_env, "OLDPWD=");
		do_change(&g_env[i][7], 1);
	}
	else
		ft_printf("minishell: cd: OLDPWD not set\n");
}

void		cd_builtin(t_inp *in)
{
	int		n;
	char	*tmp;

	in->executed = 1;
	n = (is_env(g_env, "HOME=")) ? (get_index(g_env, "HOME=")) : 0;
	if (!in->par[1])
		if (is_env(g_env, "HOME="))
			do_change(&g_env[n][5], 0);
		else 
			ft_printf("minishell: HOME not set\n");
	else if (!in->par[2])
	{
		if (in->par[1][0] == '-')
			alt_dir();
		else
		{
			if (in->par[1][0] == '~')
				in->par = join_home(in->par, n);
			do_change(in->par[1], 0);
		}
	}
	else
		ft_printf("minishell: cd: too many arguments\n");
}
