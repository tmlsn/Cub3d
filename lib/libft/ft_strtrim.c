/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:42 by marvin            #+#    #+#             */
/*   Updated: 2022/11/17 17:28:54 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	findstart(const char *s, const char *charset)
{
	int	i;

	i = 0;
	while (ft_strchr(charset, s[i]) != 0)
		i++;
	return (i);
}

static	int	findend(const char *s, const char *charset)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (ft_strchr(charset, s[i]) != 0)
		i--;
	return (i + 1);
}

static char	*empty_s(void)
{
	char	*s;

	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (0);
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		start;
	int		end;
	char	*trim;

	j = 0;
	if (!set || !s1)
		return (empty_s());
	start = findstart(s1, set);
	end = findend(s1, set);
	if (start > end)
		return (empty_s());
	trim = (char *) ft_calloc(end - start + 1, sizeof(char));
	if (!trim)
		return (0);
	i = start;
	while (i < end)
	{
		trim[j] = s1[i];
		i++;
		j++;
	}
	return (trim);
}
