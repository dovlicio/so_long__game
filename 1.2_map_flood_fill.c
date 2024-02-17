/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:47:56 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/05 18:49:07 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map)
{
	char	**map2;
	int		y;
	int		map_height;

	map_height = get_map_height(map);
	map2 = ft_calloc(sizeof(char *), map_height + 1);
	if (!map2)
		free_map_exit(map);
	y = 0;
	while (map[y])
	{
		map2[y] = ft_strdup(map[y]);
		if (!map2[y])
			free_map_exit(map);
		y++;
	}
	return (map2);
}

static void	dfs(char **map, int y, int x, int *exit)
{
	if (map[y][x] == 'E')
		(*exit)++;
	if (map[y][x] == 'F' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	else
	{
		map[y][x] = 'F';
		dfs(map, y + 1, x, exit);
		dfs(map, y - 1, x, exit);
		dfs(map, y, x + 1, exit);
		dfs(map, y, x - 1, exit);
	}
}

static void	run_flood_fill(char **map, t_position *pos, int *exit)
{
	if (map[pos->y][pos->x] == 'F')
		return ;
	dfs(map, pos->y, pos->x, exit);
}

static int	check_if_valid_path(int exit, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (exit == 0)
	{
		free_map(map);
		return (-1);
	}
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				free_map(map);
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_flood_fill(char **map)
{
	char		**map2;
	t_position	pos;
	int			exit;

	exit = 0;
	map2 = copy_map(map);
	get_player_position(map, &pos);
	run_flood_fill(map2, &pos, &exit);
	if (check_if_valid_path(exit, map2) == -1)
		return (-1);
	free_map(map2);
	return (0);
}
