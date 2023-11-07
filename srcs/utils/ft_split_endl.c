/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_endl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:06:11 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/07 19:31:46 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_strlen_endl(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

static int	count_nb_endl(char *str)
{
	int	i;
	int	nb_endl;

	i = 0;
	nb_endl = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb_endl++;
		i++;
	}
	return (nb_endl + 1);
}

char	**ft_split_at_endl(char *str)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)ft_calloc(count_nb_endl(str) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
	{
		tab[i] = ft_substr(str, j, ft_strlen_endl(&str[j]));
		if (!tab[i])
			return (ft_free_tabn(tab, i), NULL);
		i++;
		j += ft_strlen_endl(&str[j]);
		if (!str[j])
			break ;
		j++;
	}
	tab[i] = NULL;
	return (tab);
}
