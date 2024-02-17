/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0.0_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:03:24 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 15:51:27 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	t_data	*data;
	void	*array[9];

	ft_bzero(array, (sizeof(void *) * 9));
	if (argc != 2)
		return (write(2, "Error\nIvaild number of arguments.\n", 34));
	map = read_map(argv[1]);
	if (!map)
		return (write(2, "Error\nMemory allocation failed.\n", 32));
	array[0] = map;
	data = initialize_data(map);
	array[1] = data;
	initialize_images(data, array);
	initialize_map(map, data, array);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &on_keypress, array);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, \
		&on_destroy, array);
	mlx_loop(data->mlx_ptr);
	return (0);
}
