/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:49:19 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/07 19:37:31 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "librairies.h"

int		ft_error(const char *str);
void	ft_close(int *fd);

void	ft_free(void **ptr);
void	ft_free_tab(char **tab);
void	ft_free_tabn(char **tab, int n);

char	**ft_split_at_endl(char *str);

#endif