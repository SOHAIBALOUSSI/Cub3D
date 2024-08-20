#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"

# define SIZE 64

# define ALLOC 'A'
# define FREE 'F'

# define WIDTH  920
# define HEIGHT 1280

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
	struct s_gc	*prev;
}				t_gc;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int			x;
	int			y;
	float 		angle;
}	t_player;

typedef struct s_map
{
	int         rows;
	char        **content;
	char        **map;
	char        *so_texture;
	char        *no_texture;
	char        *ea_texture;
	char        *we_texture;
	char        *f_color;
	char        *c_color;
	t_color     *ciel_color;
	t_color     *floor_color;
	t_player    player;
	size_t      max_len;
	int         len;
	int         we;
	int         so; 
	int         no; 
	int         ea; 
	int         c; 
	int         f;
} t_map;

typedef struct s_game
{
	t_map		*map;
	void		*mlx_ptr;
	void		*mlx_win;

	t_gc	*gc_lst;
	//  
}   t_game;

/*		Singleton pattern	(Global like)	*/
t_game		*instance(void);

void    ft_error(t_game *cub3d,char *message);
void    free_map(t_map *map);
void    free_cub3d(t_game *cub3d);
void	ft_free(char	**arr);
int		ft_search(char c, char *set);
int		has_cub_extension(const char *f_name);
int 	check_empty(char *f_name);
void 	check_map(t_game **cub3d,char *file);
char	*get_next_line(int fd);
void 	fill_content_map(char *map_file, t_game *cub3d);
void	check_content(t_game *cub3d);
void    initialize_identifiers(t_map *map);
void    check_texture_identifiers(t_map *map, char *line, t_game *cub3d);
void    check_color_identifiers(t_map *map, char *line, t_game *cub3d);
void    validate_identifiers(t_map *map, t_game *cub3d);
void    check_identifier(t_game *content);
void 	check_textures_path(char **content,t_game *cub3d);
void 	get_textures(t_game *cub3d);
char	*get_from_file(char **content, char *target);
void 	get_colors(t_game *cub3d);
void 	get_map(t_game *cub3d);
void    check_map_last(t_game *cub3d,char **check_last);
void	check_player(t_game *cub3d);

#endif