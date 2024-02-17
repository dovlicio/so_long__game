/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:37:25 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 14:33:01 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_inputs(char **map, int *e, int *p, int *c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				(*p)++;
			else if (map[y][x] == 'E')
				(*e)++;
			else if (map[y][x] == 'C')
				(*c)++;
			else if (map[y][x] != '0' && map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	if (*p != 1 || *e != 1 || *c < 1)
		return (-1);
	return (0);
}

static int	check_map_edges(char **map, int map_width, int map_height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < map_width)
		if (map[0][x++] != '1')
			return (-1);
	x = 0;
	while (x < map_width)
		if (map[map_height - 1][x++] != '1')
			return (-1);
	while (y < map_height)
		if (map[y++][0] != '1')
			return (-1);
	y = 0;
	while (y < map_height)
		if (map[y++][map_width - 1] != '1')
			return (-1);
	return (0);
}

static int	check_if_rectangle(char **map, int map_width)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != map_width)
			return (-1);
		y++;
	}
	return (0);
}

int	is_valid_map(char **map, int map_width, int map_height)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	if (map_width > 40 || map_height > 21)
		return (-1);
	if ((map_width < 4 && map_height < 4) || (map_width < 5 && map_height < 3)
		|| (map_width < 3 && map_height < 5))
		return (-1);
	if (check_if_rectangle(map, map_width) == -1)
		return (-1);
	if (check_map_edges(map, map_width, map_height) == -1)
		return (-1);
	if (check_map_inputs(map, &e, &p, &c) == -1)
		return (-1);
	if (check_flood_fill(map) == -1)
		return (-1);
	return (0);
}
