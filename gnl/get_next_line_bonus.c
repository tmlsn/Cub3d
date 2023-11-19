/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalless <tmalless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:45:57 by tmalless          #+#    #+#             */
/*   Updated: 2022/11/30 10:21:09 by tmalless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_join(char *line, char	*buff, int need_to_be_free)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	join = (char *) malloc(sizeof(char) * (len(line) + len(buff) + 1));
	if (!join)
		return (0);
	while (line[i])
	{
		join[i] = line[i];
		i++;
	}
	while (buff[j])
	{
		join[i] = buff[j];
		i++;
		j++;
	}
	join[i] = '\0';
	if (need_to_be_free == 1)
		free(line);
	return (join);
}

int	is_new_line(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*run_in_circle(char *buff, char *line)
{
	if (!line)
		line = gnl_join("", buff, 0);
	else
		line = gnl_join(line, buff, 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[2048];
	char		*buff;
	char		*ret_l;
	int			r;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	buff[0] = '\0';
	while (is_new_line(buff) == -1)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (salut_mon_pote(buff));
		buff[r] = '\0';
		if (r == 0)
			break ;
		line[fd] = run_in_circle(buff, line[fd]);
	}
	free(buff);
	ret_l = ret_v(line[fd]);
	line[fd] = clean_stat(line[fd]);
	return (ret_l);
}
