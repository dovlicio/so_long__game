/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.1_image_import.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hp <hp@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:51:06 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/12/03 02:02:37 by hp               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	*fill_img_data(t_data *data, void **array, int index)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		on_destroy(array);
	if (index == 0)
		img->relative_path = ft_strdup("./textures/tile8.xpm");
	else if (index == 1)
		img->relative_path = ft_strdup("./textures/wall2.xpm");
	else if (index == 2)
		img->relative_path = ft_strdup("./textures/player_right.xpm");
	else if (index == 3)
		img->relative_path = ft_strdup("./textures/collect.xpm");
	else if (index == 4)
		img->relative_path = ft_strdup("./textures/player_left.xpm");
	else if (index == 5)
		img->relative_path = ft_strdup("./textures/exit.xpm");
	if (!img->relative_path)
		img_malloc_fail(img, array);
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, \
		img->relative_path, &img->width, &img->height);
	if (!img->img)
		img_malloc_fail(img, array);
	return (img);
}

void	initialize_images(t_data *data, void **array)
{
	array[2] = fill_img_data(data, array, 0);
	array[3] = fill_img_data(data, array, 1);
	array[4] = fill_img_data(data, array, 2);
	array[5] = fill_img_data(data, array, 3);
	array[6] = fill_img_data(data, array, 4);
	array[7] = fill_img_data(data, array, 5);
}
