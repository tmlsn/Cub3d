/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:47:52 by fduzant           #+#    #+#             */
/*   Updated: 2023/11/07 17:50:51 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define ERROR_EMPTY "Error\nEmpty file\n"
# define ERROR_XPM_COLOR "Error\nXPM color is invalid\n"

enum		e_extention
{
	CUB,
	XPM
};

enum		e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum		e_item
{
	NO,
	SO,
	EA,
	WE,
	F,
	C
};

enum		e_map
{
	EMPTY,
	WALL,
	SPACE,
	SPAWN
};

#endif