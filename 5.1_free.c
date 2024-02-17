/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:36:00 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/03 19:14:26 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(void **array, t_data *data)
{
	t_img	*img;
	int		i;

	i = 2;
	while (array[i])
	{
		img = array[i];
		if (img->img != NULL)
			mlx_destroy_image(data->mlx_ptr, img->img);
		if (img->relative_path)
			free(img->relative_path);
		free(img);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->mlx_ptr)
			free(data->mlx_ptr);
		if (data->win_ptr)
			free(data->win_ptr);
		free(data);
	}
}

int	on_destroy(void **array)
{
	t_data	*data;

	data = array[1];
	free_img(array, data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_map(array[0]);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}
