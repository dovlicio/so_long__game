/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:55:01 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 15:33:16 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

static int	check_empty_line(char *str)
{
	int	line_lenght;
	int	i;
	int	len;

	line_lenght = 0;
	while (str[line_lenght] != '\n')
		line_lenght++;
	i = line_lenght + 1;
	len = 0;
	while (str[i])
	{
		len = 0;
		while (str[i] != '\n' && str[i] != '\0')
		{
			len++;
			i++;
		}
		if (str[i] == '\0')
			return (0);
		if (len != line_lenght || str[i + 1] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

static char	*put_map_in_string(char *map_path)
{
	int		buffer_size;
	int		fd;
	char	temp[862];
	char	*buffer;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_opening_fd();
	buffer_size = read(fd, temp, 862);
	if (buffer_size == -1)
		error_reading_fd(&fd);
	temp[buffer_size] = '\0';
	if (close(fd) == -1)
		error_closing_fd();
	if (buffer_size > 861)
		error_map_too_big();
	if (check_empty_line(temp) == -1)
		error_empty_line();
	temp[buffer_size] = '\0';
	buffer = ft_strdup(temp);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	**read_map(char *map_path)
{
	char	**map;
	char	*buffer;
	int		map_width;
	int		map_height;

	if (!ft_strnstr(map_path, ".ber", 100))
		error_invalid_map_format();
	buffer = put_map_in_string(map_path);
	if (!buffer)
		return (NULL);
	map = ft_split(buffer, '\n');
	free(buffer);
	if (!map)
		return (NULL);
	map_width = ft_strlen(map[0]);
	map_height = get_map_height(map);
	if (is_valid_map(map, map_width, map_height) == -1)
		invalid_map(map);
	return (map);
}
