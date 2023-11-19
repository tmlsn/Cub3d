/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:56 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/30 10:17:58 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*run_in_circle(char *buff, char *line);
char	*clean_stat(char *s);
char	*new_stat(char *new_l, char *s, size_t i, size_t j);
char	*ret_v(char *s);
int		is_new_line(char *s);
char	*gnl_join(char *line, char	*buff, int need_to_be_free);
size_t	len(char *s);
char	*salut_mon_pote(char *s);

#endif
