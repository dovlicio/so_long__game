/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_mlx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:26:32 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/05 12:13:08 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_malloc_fail(t_data *data, char **map)
{
	free_data(data);
	free_map(map);
	write(2, "Error\nMalloc failed.\n", 21);
	exit(EXIT_FAILURE);
}

void	win_malloc_fail(t_data *data, char **map)
{
	mlx_destroy_display(data->mlx_ptr);
	mlx_malloc_fail(data, map);
	exit(EXIT_FAILURE);
}

void	data_malloc_fail(char **map)
{
	free_map(map);
	write(2, "Error\nMalloc failed.\n", 21);
	exit(EXIT_FAILURE);
}

void	img_malloc_fail(t_img *img, void **array)
{
	if (img)
	{
		if (img->relative_path)
		{
			write(2, "Error\nImage file not found, check the input.\n", 45);
			free(img->relative_path);
		}
		free(img);
	}
	on_destroy(array);
}
