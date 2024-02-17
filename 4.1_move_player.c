/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:56:48 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/05 12:16:39 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_right(char **map, t_position *position, void **array)
{
	if (map[position->y][position->x + 1] == 'E' && is_full_collected(map))
		on_destroy(array);
	if (map[position->y][position->x + 1] != '1' && \
		map[position->y][position->x + 1] != 'E')
	{
		map[position->y][position->x] = '0';
		map[position->y][position->x + 1] = 'P';
	}
}

static void	move_left(char **map, t_position *position, void **array)
{
	if (map[position->y][position->x - 1] == 'E' && is_full_collected(map))
		on_destroy(array);
	if (map[position->y][position->x - 1] != '1' && \
		map[position->y][position->x - 1] != 'E')
	{
		map[position->y][position->x] = '0';
		map[position->y][position->x - 1] = 'P';
	}
}

static void	move_up(char **map, t_position *position, void **array)
{
	if (map[position->y - 1][position->x] == 'E' && is_full_collected(map))
		on_destroy(array);
	if (map[position->y - 1][position->x] != '1' && \
		map[position->y - 1][position->x] != 'E')
	{
		map[position->y][position->x] = '0';
		map[position->y - 1][position->x] = 'P';
	}
}

static void	move_down(char **map, t_position *position, void **array)
{
	if (map[position->y + 1][position->x] == 'E' && is_full_collected(map))
		on_destroy(array);
	if (map[position->y + 1][position->x] != '1' && \
		map[position->y + 1][position->x] != 'E')
	{
		map[position->y][position->x] = '0';
		map[position->y + 1][position->x] = 'P';
	}
}

void	move_player(char **map, char key, t_position *position, void **array)
{
	if (key == 'S')
		move_right(map, position, array);
	else if (key == 'Q')
		move_left(map, position, array);
	else if (key == 'R')
		move_up(map, position, array);
	else if (key == 'T')
		move_down(map, position, array);
}
