/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:58:03 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/21 17:58:03 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	error_gnl(char	*file, int nbr_line)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	i = -1;
	while (++i < nbr_line)
	{	
		line = get_next_line(fd);
		free (line);
	}
	line = get_next_line(fd);
	if (line != NULL)
		return (1);
	free(line);
	return (0);
}

static int	size_line(char *line)
{
	int	nbr_octet;

	nbr_octet = ft_strlen(line);
	if (line[nbr_octet - 1] == '\n')
			nbr_octet--;
	return (nbr_octet);
}

static int	fil_map(char **map, int nbr_line, char *file)
{
	int		fd;
	int		i;
	int		j;
	int		nbr_octet;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = -1;
	while (++i < nbr_line)
	{
		line = get_next_line(fd);
		nbr_octet = size_line(line);
		map[i] = malloc(sizeof(char) * (nbr_octet + 1));
		if (!map[i])
			return (free_map_2d(map));
		j = -1;
		while (++j <= nbr_octet)
			map[i][j] = line[j];
		map[i][nbr_octet] = '\0';
		free(line);
	}
	close(fd);
	return (1);
}

char	**create_map(char	*file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map->nbr_line = 0;
	line = get_next_line(fd);
	while (line)
	{	
		free(line);
		line = get_next_line(fd);
		map->nbr_line += 1;
	}
	close(fd);
	if (error_gnl(file, map->nbr_line))
		return (0);
	map->map = malloc(sizeof(char *) * (map->nbr_line + 1));
	if (!map->map)
		return (0);
	map->map[map->nbr_line] = NULL;
	if (!fil_map(map->map, map->nbr_line, file))
		return (0);
	return (map->map);
}
