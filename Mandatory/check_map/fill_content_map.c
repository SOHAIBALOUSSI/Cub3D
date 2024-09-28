#include "../cub3D.h"

int	rows_nbr(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		len++;
	}
	return (len);
}

char *skip_spaces(char *line)
{
    while (*line && (*line == ' ' || *line == '\t'))
        line++;
    return line;
}

int is_texture_identifier(char *line) {
    return (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "WE", 2) == 0 ||
            ft_strncmp(line, "SO", 2) == 0 || ft_strncmp(line, "EA", 2) == 0 ||
            ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0);
}

void fill_content_data(char *map_file, t_game *cub3d)
{
    int fd, i, rows;
    i = 0;
    fd = open(map_file, O_RDONLY);
    if (fd == -1)
        (perror("Error opening file"), exit(EXIT_FAILURE));
    rows = rows_nbr(fd);
    close(fd);
    fd = open(map_file, O_RDONLY);
    if (fd == -1)
        (perror("Error opening file"), exit(EXIT_FAILURE));
    cub3d->data->content = m_alloc(sizeof(char *) * (rows + 1), ALLOC);
    char *line = get_next_line(fd);
    while (i < rows && line)
	{
        char *trimmed_line = skip_spaces(line);
        if (is_texture_identifier(trimmed_line))
            cub3d->data->content[i] = ft_strdup(trimmed_line);
        else
            cub3d->data->content[i] = ft_strdup(line);
        line = get_next_line(fd);
        i++;
    }
    cub3d->data->content[i] = NULL;
    close(fd);
}
