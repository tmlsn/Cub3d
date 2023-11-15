/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:49:19 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/15 15:07:31 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

int		ft_error(char *str);
void	ft_close(int *fd);

void	ft_free(void **ptr);
void	ft_free_tab(char **tab);
void	ft_free_tabn(char **tab, int n);
void	ft_free_tabin(int **tab, int n);

char	**ft_split_at_endl(char *str);

int		ft_count_nb_line(char **file_content);

int		ft_line_lowercase(char *line);

int		ft_atoi_base(char *str, char *base);

void	destroy_data(t_data *data);

#endif