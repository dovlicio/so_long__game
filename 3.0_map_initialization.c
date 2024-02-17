/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:23:32 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/05 12:13:02 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*check_for_input(int y, int x, char **map, void **array)
{
	if (map[y][x] == '1')
		return (array[3]);
	else if (map[y][x] == 'P')
		return (array[4]);
	else if (map[y][x] == 'C')
		return (array[5]);
	else if (map[y][x] == 'E')
		return (array[7]);
	else
		return (array[2]);
}

void	initialize_map(char **map, t_data *data, void **array)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	t_img	*img;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	while (map[y1])
	{
		x = 0;
		x1 = 0;
		while (map[y1][x1])
		{
			img = check_for_input(y1, x1, map, array);
			mlx_put_image_to_window(data->mlx_ptr, \
				data->win_ptr, img->img, x, y);
			x += img->width;
			x1++;
		}
		y += img->height;
		y1++;
	}
}

static t_img	*check_for_input2(int y, int x, char **map, void **array)
{
	if (map[y][x] == '1')
		return (array[3]);
	else if (map[y][x] == 'P')
		return (array[6]);
	else if (map[y][x] == 'C')
		return (array[5]);
	else if (map[y][x] == 'E')
		return (array[7]);
	else
		return (array[2]);
}

void	initialize_map_2(char **map, t_data *data, void **array)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	t_img	*img;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	while (map[y1])
	{
		x = 0;
		x1 = 0;
		while (map[y1][x1])
		{
			img = check_for_input2(y1, x1, map, array);
			mlx_put_image_to_window(data->mlx_ptr, \
				data->win_ptr, img->img, x, y);
			x += img->width;
			x1++;
		}
		y += img->height;
		y1++;
	}
}
