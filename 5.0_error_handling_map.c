/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:57:18 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 15:30:34 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map_too_big(void)
{
	write(2, "Error\nInvalid map. (maximum size: 40x21)\n", 41);
	exit(EXIT_FAILURE);
}

void	invalid_map(char **map)
{
	free_map(map);
	write(2, "Error\nInvalid map.\n", 19);
	exit(EXIT_FAILURE);
}

void	error_invalid_map_format(void)
{
	write(2, "Error\nInvallid map format. Only '.ber' format supported.\n", 57);
	exit(EXIT_FAILURE);
}

void	free_map_exit(char **map)
{
	free_map(map);
	write(2, "Error\nMalloc failed.\n", 21);
	exit(EXIT_FAILURE);
}

void	error_empty_line(void)
{
	write(2, "Error\nMap must me rectangle and cannot have empty lines.\n", 57);
	exit(EXIT_FAILURE);
}
