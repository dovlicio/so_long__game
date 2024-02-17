/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:57:06 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/02 18:13:18 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_opening_fd(void)
{
	write(2, "Error\nOpening file descriptor failed.\n", 38);
	exit(EXIT_FAILURE);
}

void	error_closing_fd(void)
{
	write(2, "Error\nClosing file descriptor failed.\n", 38);
	exit(EXIT_FAILURE);
}

void	error_reading_fd(int *fd)
{
	write(2, "Error\nFailed to read a file.\n", 29);
	if (close(*fd) == -1)
		write(2, "Error\nFailed to close a file.\n", 30);
	exit(EXIT_FAILURE);
}
