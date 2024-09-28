#include "../cub3d_bonus.h"

void valid_content(t_game *cub3d)
{
 int i;
 int j;

 i = -1;
 j = 0;
 while (cub3d->data->content[++i])
 {
  if (ft_search(cub3d->data->content[i][0], " 10FC\n"))
   continue ;
  else if (ft_strncmp(cub3d->data->content[i], "WE", 2)
   && ft_strncmp(cub3d->data->content[i], "NO", 2)
   && ft_strncmp(cub3d->data->content[i], "EA", 2)
   && ft_strncmp(cub3d->data->content[i], "SO", 2))
   ft_error(cub3d, "Error: bad character in content of file\n");
 }
}

void check_content(t_game *cub3d)
{ 
	if (!check_map_last(cub3d))
    {
    valid_content(cub3d);
    check_identifier(cub3d);
    check_textures_path(cub3d->data->content, cub3d);
    get_textures(cub3d);
    get_colors(cub3d);
    get_map(cub3d);
    get_square_map(cub3d);
    check_player(cub3d);
    if (!check_walls(cub3d))
        ft_error(cub3d, "Error: Map borders are invalid!\n");
    }else
		ft_error(cub3d,"Error: The map must be the last!\n");
}
