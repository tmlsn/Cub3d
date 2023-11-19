/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:25:50 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/07 18:53:49 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_extension(char *file_name, int mode)
{
	size_t		len;
	const char	*ext[] = {".cub", ".xpm"};

	len = ft_strlen(file_name);
	if (len == 0 | len < 5)
		return (ft_error("Error, file name too short\n"));
	len -= 4;
	if (ft_strncmp(file_name + len, ext[mode], 4) != 0)
	{
		if (mode == CUB)
			return (ft_error("Error, file extension must be .cub\n"));
		else if (mode == XPM)
			return (ft_error("Error, file extension must be .xpm\n"));
	}
	return (EXIT_SUCCESS);
}

int	check_file(char *file_name, int *fd, int mode)
{
	if (check_file_extension(file_name, mode) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		return (ft_error("Error, file not readeable or file doesn't exist\n"));
	return (EXIT_SUCCESS);
}
