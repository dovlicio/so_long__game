/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:52:15 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 12:03:37 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_window_width(char **map)
{
	int	map_width;
	int	window_width;

	map_width = ft_strlen(map[0]);
	window_width = 48 * map_width;
	return (window_width);
}

int	calculate_window_height(char **map)
{
	int	map_height;
	int	window_height;

	map_height = get_map_height(map);
	window_height = 48 * map_height;
	return (window_height);
}

t_data	*initialize_data(char **map)
{
	t_data	*data;
	int		width;
	int		height;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		data_malloc_fail(map);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		mlx_malloc_fail(data, map);
	width = calculate_window_width(map);
	height = calculate_window_height(map);
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (data->win_ptr == NULL)
		win_malloc_fail(data, map);
	return (data);
}
