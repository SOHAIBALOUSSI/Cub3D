/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:20:41 by sait-alo          #+#    #+#             */
/*   Updated: 2024/10/06 09:39:17 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../include/libft/libft.h"
# include "../include/gc.h"

// Game settings 
# define WIDTH  1000
# define HEIGHT 1000
# define SIZE 64
# define MOVE_SPEED 1.5
# define ROTATION_SPEED 0.01

# define PI 	3.14159265358979323846
# define PI_2	1.57079632679489661923
# define PI2	6.28318530718

// Game Controle
# define ESC	0xff1b
# define W		0x0077
# define S		0x0073
# define A		0x0061
# define D		0x0064
# define LEFT	65363
# define RIGHT	65361
# define FOV_RD 1.04719755119

# define WALL_BUFFER 0.1
# define DISTANCE_PROJ_PLANE 866.025403791 // ((WIDTH / 2) / tan(FOV_RD / 2))
# define USAGE "Error\nUsage: ./cub3d maps/*.cub\n"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
}	t_keys;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	double		dir_x;
	double		dir_y;
	t_keys		keys;
}	t_player;

typedef struct s_data
{
	int			height;
	int			width;
	char		**content;
	char		**map;
	char		**last_map;
	char		**square_map;
	char		*so_texture;
	char		*no_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*image_start;
	char		*f_color;
	char		*c_color;
	t_color		ciel_color;
	t_color		floor_color;
	t_player	player;
	int			we;
	int			so;
	int			no;
	int			ea;
	int			c;
	int			f;
}		t_data;

typedef struct s_ray
{
	int			id;
	double		angle;
	char		dir;
	t_point		wall_hit;
	double		distance;
	int			was_hit_vertical;
	int			facing_up;
	int			facing_right;
	size_t		wall_strip_height;
	int			wall_top;
	int			wall_bottom;
}			t_ray;

typedef struct s_wall
{
	int		start_y;
	int		end_y;
	int		tx;
	double	height;
	t_image	*texture;
}	t_wall;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_data		*data;
	t_image		frame_buffer;
	t_image		*textures[4];
	t_player	player;
	double		screen_middle;
	t_ray		ray[WIDTH];
}			t_game;

enum
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
};

/*	init	*/
void	initialize_window(t_game *game);
void	initialize_textures(t_game *game);
void	initialize_frame_buffer(t_game *game);
t_image	*load_texture(t_game *game, char *path);

/* 		Raycasting	*/
int		raycasting(t_game *game, t_ray *rays);
double	normalize_angle(double angle);
void	set_ray_direction(t_ray *ray, t_point *stp);
int		wall_hit(double x, double y, t_game *g);

/*		Rendring		*/
void	render_wall_strip(t_game *g, t_ray ray);
int		get_color(t_color color);
void	put_pixels(t_image *data, int x, int y, int color);

/*		hooks	*/
void	capture_hooks(t_game *game);
void	move_player(t_game *game);

void	get_square_map(t_game *cub3d);
void	map_borders(t_game *cub3d);
int		check_row(char *row);
void	check_map_height(t_game *cub3d);
void	ft_error(t_game *game, char *message);
void	free_map(t_data *map);
int		turnoff(t_game *game);
int		ft_search(char c, char *set);
int		has_cub_extension(const char *f_name);
int		check_empty(char *f_name);
void	check_map(t_game *cub3d, char *file);
char	*get_next_line(int fd);
void	fill_content_data(char *map_file, t_game *cub3d);
void	check_content(t_game *cub3d);
void	initialize_identifiers(t_data *map);
void	check_texture_identifiers(t_data *map, char *line, t_game *cub3d);
void	check_color_identifiers(t_data *map, char *line, t_game *cub3d);
void	validate_identifiers(t_data *map, t_game *cub3d);
void	check_identifier(t_game *content);
void	check_textures_path(char **content, t_game *cub3d);
void	get_textures(t_game *cub3d);
char	*get_from_file(char **content, char *target);
void	get_colors(t_game *cub3d);
void	get_map(t_game *cub3d);
void	get_square_map(t_game *cub3d);
void	check_player(t_game *cub3d);
int		check_walls(t_game *cub3d);
int		map_len(char **content);
int		check_row(char *row);
int		check_map_last(t_game *cub3d);

#endif