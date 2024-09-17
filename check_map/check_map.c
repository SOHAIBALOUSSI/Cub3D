#include "../cub3D.h"

int	has_cub_extension(const char *f_name)
{
	const char	*ext;
	int			len;

	ext = ".cub";
	len = ft_strlen(f_name) - 4;
	return (ft_strncmp(f_name + len, ext, 4) == 0);
}

int	check_empty(char *f_name)
{
	int		fd;
	int		rslt;
	char	buf;

	fd = open(f_name, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	rslt = read(fd, &buf, 1);
	close(fd);
	return (rslt);
}

void	check_map(t_game *cub3d, char *file)
{
	if (open(file, __O_DIRECTORY) != -1)
		ft_error(NULL, "Error\nthis is a directory!");
	if (!has_cub_extension(file))
		ft_error(NULL, "Error\nbad extension!");
	if (!check_empty(file))
		ft_error(NULL, "Error\nempty file!");
	cub3d->data = malloc(sizeof(t_data));
	if (!cub3d->data)
		ft_error(NULL, "Error\nMemory allocation failed!");
	ft_memset(cub3d->data, 0, sizeof(t_data));
	fill_content_data(file, cub3d);
	check_content(cub3d);
}
