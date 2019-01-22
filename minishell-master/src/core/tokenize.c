/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:18:22 by sankosi           #+#    #+#             */
/*   Updated: 2018/11/06 01:02:54 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

static int		ft_countwords(char const *s)
{
	int				it_s;
	unsigned int	i;

	i = 0;
	it_s = i;
	while (s[it_s] != '\0')
	{
		while (ft_isspace(s[it_s]))
			it_s++;
		if ((s[it_s] != '\0') && !ft_isspace(s[it_s]))
		{
			i++;
			while (!ft_isspace(s[it_s]) && s[it_s] != '\0')
				it_s++;
		}
	}
	return (i);
}

static	char	**ft_populate(char const *s, int num, char **res)
{
	int i;
	int k;
	int j;

	i = 0;
	j = 0;
	while (i < (num - 1))
	{
		if (!ft_isspace(s[j]) && s[j] != '\0')
		{
			k = 0;
			while (s[j + k] != '\0' && !ft_isspace(s[j + k]))
				k++;
			res[i] = ft_strsub(s, j, k);
			j += k;
			i++;
		}
		else
			j++;
	}
	return (res);
}

char			**tokenize(char const *s)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	i = ft_countwords(s);
	if (!(res = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	res = ft_populate(s, i + 1, res);
	res[i] = NULL;
	return (res);
}
