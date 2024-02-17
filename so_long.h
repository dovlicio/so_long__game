/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdamnjan <vdamnjan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:54:09 by vdamnjan          #+#    #+#             */
/*   Updated: 2023/10/06 15:51:33 by vdamnjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		width;
	int		height;
}			t_img;

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

/*-----------------------------MAP-----------------------------*/
char	**read_map(char *map_path);
int		is_valid_map(char **map, int map_width, int map_height);
int		get_map_height(char **map);
void	initialize_map(char **map, t_data *data, void **array);
void	initialize_map_2(char **map, t_data *data, void **array);

/*--------------------------GAMEPLAY---------------------------*/
int		on_keypress(int key, void **array);
void	start_gameplay(t_data *data, char **map, void **array, char key);
int		is_full_collected(char **map);
void	move_player(char **map, char key, t_position *position, void **array);
void	get_player_position(char **map, t_position *position);
int		is_full_collected(char **map);
void	start_gameplay(t_data *data, char **map, void **array, char key);

/*---------------------------IMAGES----------------------------*/
void	initialize_sprites(char **map, t_data *data, void **array);
t_img	*fill_img_data(t_data *data, void **array, int index);
void	initialize_images(t_data *data, void **array);

/*-----------------------ERROR_HANDLING_FD---------------------*/
void	error_opening_fd(void);
void	error_closing_fd(void);
void	error_reading_fd(int *fd);

/*-----------------------ERROR_HANDLING_MAP--------------------*/
void	error_map_too_big(void);
void	error_empty_line(void);
void	invalid_map(char **map);
void	error_invalid_map_format(void);
int		check_flood_fill(char **map);

/*-----------------------ERROR_HANDLING_MLX--------------------*/
void	mlx_malloc_fail(t_data *data, char **map);
void	win_malloc_fail(t_data *data, char **map);
void	data_malloc_fail(char **map);
void	img_malloc_fail(t_img *img, void **array);

/*------------------------WINDOW_SETTINGS-----------------------*/
t_data	*initialize_data(char **map);
int		calculate_window_height(char **map);
t_data	*initialize_data(char **map);

/*----------------------------FREE-----------------------------*/
int		on_destroy(void **array);
void	free_map(char **map);
void	free_data(t_data *data);
void	free_img(void **array, t_data *data);
void	free_map_exit(char **map);

#endif