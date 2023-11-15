/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:08:46 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 13:46:33 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* Free a pointer and set it to NULL */
void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/* Free a pointer of tabulation and set it to NULL */
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_free((void **)&tab[i]);
		i++;
	}
	free(tab);
}

/* Free a pointer of n tabulation and set it to NULL */
void	ft_free_tabn(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_free((void **)&tab[i]);
		i++;
	}
	free(tab);
}

/* Free a pointer of n tabulation type int and set it to NULL */
void	ft_free_tabin(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_free((void **)&tab[i]);
		i++;
	}
	free(tab);
}
