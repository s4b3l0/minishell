/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:07:18 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/27 16:48:13 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

char	*get_substr(char *str, char *tmp)
{
	int		len;

	len = 0;
	while (str[len] != '=')
		len++;
	return (ft_strsub(str, 0, len + 1));
}

void	update_shlvl(void)
{
	char	*strlvl;
	int		ind;
	char	*strlvl2;
	int		n;
	char	*tmp;

	n = 0;
	strlvl = ft_strdup("SHLVL=");
	ind = get_index(g_env, strlvl);
	if (g_env[ind])
	{
		n = (ft_atoi(&g_env[ind][6])) + 1;
		FREE(g_env[ind]);
		strlvl2 = ft_itoa(n);
		tmp = ft_strjoin(strlvl, strlvl2);
		g_env[ind] = ft_strdup(tmp);
		FREE(tmp);
	}
	FREE(strlvl);
	FREE(strlvl2);
}
