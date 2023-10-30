/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:45:19 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/18 17:08:42 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	w_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && str[i + 1] == c)
			count++;
		else if (str[i] != c && str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	*fill_str_tab(char const *s, char sep, int i)
{
	int		j;
	char	*p;

	j = i;
	while (s[j] && s[j] != sep)
		j++;
	p = ft_substr(s, i, j - i);
	if (!p)
		return (0);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	strs = ft_calloc(w_count(s, c) + 1, sizeof(char *));
	while (s[i] && pos < w_count(s, c))
	{
		if (s[i] != c)
		{
			strs[pos] = fill_str_tab(s, c, i);
			if (!strs[pos])
			{
				clean_split(strs);
				return (0);
			}
			pos++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i])
			i++;
	}
	return (strs);
}
