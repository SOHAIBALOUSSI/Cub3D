/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <sait-alo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:01:58 by sait-alo          #+#    #+#             */
/*   Updated: 2024/10/06 09:39:52 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <SDL2/SDL.h>
# include <X11/X.h>
# include "../mlx/mlx.h"
# include "../include/libft/libft.h"
# include "../include/cute_sound/cute_sound.h"
# include "../include/gc.h"

# define SIZE 	64
# define WIDTH  1280
# define HEIGHT 720
# define MOVE_SPEED 2
# define MOUSE_SENSITIVITY 0.0004

# define PI 	3.14159265358
# define PI_2	1.57079632679489661923
# define PI2	6.28318530718

# define ESC	0xff1b
# define W		0x0077
# define S		0x0073
# define A		0x0061
# define D		0x0064
# define E		0x0065
# define LEFT	65363
# define RIGHT	65361
# define UP 	0xff52
# define DOWN 	0xff54
# define LCTRL 	0xffe3

# define DISTANCE_PROJ_PLANE 1108.51251686
# define MINIMAP_X_OFFSET 20
# define PLAYER_SIZE 0.4
# define PLAYER_COLOR 0xFF0000
# define FOV_RD 1.04719755119
# define ROTATION_SPEED 0.01
# define WALL_BUFFER 0.1
# define MAP_SCALE 10
# define MINIMAP_SIZE 15
# define SHOOT_BOARD_PATH	"./resources/shot-board.xpm"

/* Errors */
# define USAGE "Error\nUsage: ./cub3d_bonus maps/*.cub\n"

typedef struct s_minimap
{
	int		map_x;
	int		map_y;
	int		x;
	int		y;
}				t_minimap;

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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
	int	open_door;
}	t_keys;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_ray
{
	int			id;
	double		angle;
	bool		skip_closed_door;
	char		wall_dir;
	t_point		wall_hit;
	double		distance;
	int			was_hit_vertical;
	int			facing_up;
	int			facing_right;
	int			wall_strip_height;
	int			wall_top;
	int			wall_bottom;
	char		hit_content;
	char		vhit_content;
	char		hhit_content;
	int			is_door;
}				t_ray;

typedef struct s_player
{
	double		x;
	double		y;
	double		angle;
	double		dir_x;
	double		dir_y;
	t_keys		keys;
	t_ray		ray;
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
	char		*f_color;
	char		*c_color;
	t_color		ciel_color;
	t_color		floor_color;
	t_player	player;
	size_t		max_len;
	int			len;
	int			we;
	int			so;
	int			no;
	int			ea;
	int			c;
	int			f;
}			t_data;

typedef struct s_animation
{
	int		curr_frame;
	int		frame_counter;
	int		sound_played;
	bool	is_shooting;
}			t_animation;

typedef struct s_mouse
{
	int		x;
	int		y;
	bool	show_mouse;
}		t_mouse;

typedef struct s_wall
{
	int		start_y;
	int		end_y;
	int		tx;
	double	height;
	t_image	*texture;
}			t_wall;

typedef struct s_audio
{
	cs_audio_source_t	*sound_track;
	cs_audio_source_t	*gun_sound;
	cs_audio_source_t	*door_sound[2];
	cs_sound_params_t	gun_params;
	cs_sound_params_t	theme_params;
	cs_sound_params_t	door_params;
}	t_audio;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_data		*data;
	t_image		frame_buffer;
	t_image		*textures[6];
	t_image		*gun[4];
	t_animation	gun_anim;
	t_mouse		mouse;
	t_audio		audio;
	bool		door_sound_played;
	int			door_open;
	int			screen_center;
	bool		key_pressed;
	t_ray		ray[WIDTH];
}				t_game;

enum
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	SHOOT_BOARD,
	DOOR,
};

/* 		Raycasting	*/
int		raycasting(t_game *game, t_ray *rays);
void	cast_ray(t_game *g, t_ray *ray);
int		wall_hit(double x, double y, t_game *g, t_ray *ray);
double	normalize_angle(double angle);
double	get_distance(double x1, double y1, double x2, double y2);

/*		Rendring		*/
void	render_wall_strip(t_game *g, t_ray ray);
void	render_map(t_game *game);
void	render_player(t_game *game, t_player *player);
void	put_pixels(t_image *data, int x, int y, int color);
void	minimap(t_game *game);
void	put_gun_to_buffer(t_image *gun, int x, int y, t_game *g);
void	gun_animation(t_game *game);
int		gun_fire(int button, int x, int y, void *param);

/*		Hooks	*/
void	capture_hooks(t_game *game);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	move_player(t_game *game);
int		mouse_hook(int x, int y, void *game);
void	mouse_movement(t_game *game, int new_x, int new_y);
void	control_mouse_status(t_game *game);

/*		initalization 	*/
void	initialize_window(t_game *game);
void	initialize_frame(t_game *g);
void	initialize_textures(t_game *game);
void	initialize_sound(t_game *game);

/*		Sounds	*/
void	play_sounds(t_game *game);

int		get_color(t_color color);
void	ft_error(t_game *game, char *message);
int		shutdown2(t_game *game);
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
void	map_borders(t_game *cub3d);
void	check_map_height(t_game *cub3d);
int		check_row(char *row);
int		check_map_last(t_game *cub3d);

#endif