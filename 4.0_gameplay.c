/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.0_gameplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:56:15 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/11/14 19:05:08 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int key, void **array)
{
	char		ch;
	static int	moves;

	ch = (char)key;
	if (key == XK_Escape)
		on_destroy(array);
	else
	{
		ft_printf("Movements count: %d\n", moves);
		if (ch == 'R' || ch == 'Q' || ch == 'S' || ch == 'T')
		{
			start_gameplay(array[1], array[0], array, key);
			moves++;
		}
	}
	return (0);
}

void	get_player_position(char **map, t_position *position)
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
			{
				position->y = y;
				position->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_full_collected(char **map)
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
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	start_gameplay(t_data *data, char **map, void **array, char key)
{
	t_position	position;

	get_player_position(map, &position);
	move_player(map, key, &position, array);
	if (key == 'Q')
		initialize_map_2(map, data, array);
	else
		initialize_map(map, data, array);
}
