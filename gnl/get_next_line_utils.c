/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:16:06 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/30 10:21:44 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ret_v(char *s)
{
	size_t	i;
	size_t	j;
	char	*ret_s;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	ret_s = malloc(sizeof(char) * (i + 2));
	if (!ret_s)
		return (0);
	while (j <= i)
	{
		ret_s[j] = s[j];
		j++;
	}
	ret_s[j] = '\0';
	return (ret_s);
}

char	*new_stat(char *new_l, char *s, size_t i, size_t j)
{
	size_t	k;

	k = 0;
	while (i <= j)
	{
		new_l[k] = s[i];
		k++;
		i++;
	}
	free(s);
	return (new_l);
}

char	*clean_stat(char *s)
{
	size_t	i;
	char	*new_l;

	i = 0;
	if (!s)
	{
		free(s);
		return (0);
	}
	while (s[i] != '\n' && s[i])
		i++;
	if (i == len(s) || (s[i + 1] == '\0'))
	{
		free (s);
		return (0);
	}
	new_l = malloc(sizeof(char) * (len(s) - i + 2));
	if (!new_l)
	{
		free(s);
		return (0);
	}
	i++;
	return (new_stat(new_l, s, i, len(s)));
}

char	*salut_mon_pote(char *s)
{
	free(s);
	return (0);
}
