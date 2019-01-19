/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duparray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sankosi <sankosi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:57:57 by sankosi           #+#    #+#             */
/*   Updated: 2018/09/17 14:19:34 by sankosi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shell.h"

int			arrlen(char **arr)
{
	register int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char		**dup_array(char **src)
{
	register char		**dest;
	register int		i;
	int					n;

	if (!src)
		return (NULL);
	i = arrlen(src);
	n = 0;
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	while (n < i)
	{
		dest[n] = ft_strdup(src[n]);
		n++;
	}
	dest[i] = NULL;
	return (dest);
}
