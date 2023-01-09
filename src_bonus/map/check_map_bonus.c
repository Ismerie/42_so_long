/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:43:24 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/22 14:43:24 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	check_rectangle(t_map *map)
{
	int	nbr_charac_first;
	int	nbr_charac;
	int	i;

	i = 0;
	if (!map->map[i])
	{
		ft_printf("Error\nThe map is empty\n");
		free_map_2d(map->map);
		return (0);
	}
	nbr_charac_first = ft_strlen(map->map[i]);
	while (map->map[++i])
	{
		nbr_charac = ft_strlen(map->map[i]);
		if (nbr_charac != nbr_charac_first)
		{
			ft_printf("Error\nThe map is not a rectangle\n");
			free_map_2d(map->map);
			return (0);
		}
	}
	map->nbr_octet = nbr_charac;
	return (1);
}

static int	check_wall(char **map, int line, int rank)
{
	int	i;

	i = -1;
	while (map[line][++i])
	{
		if (map[line][i] != '1')
		{
			ft_printf("Error\nThe map is not surrouded by walls '1'\n");
			free_map_2d(map);
			return (0);
		}
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][rank] != '1')
		{
			ft_printf("Error\nThe map is not surrouded by walls '1'\n");
			free_map_2d(map);
			return (0);
		}
	}
	return (1);
}

static int	check_valid_charac(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
			&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'V')
			{
				ft_printf("Error\nA character is not valid in the map\n");
				free_map_2d(map);
				return (0);
			}
		}
	}
	return (1);
}

static int	check_element(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'C')
				map->nbr_c = map->nbr_c + 1;
			else if (map->map[i][j] == 'E')
				map->nbr_e = map->nbr_e + 1;
			else if (map->map[i][j] == 'P')
				map->nbr_p = map->nbr_p + 1;
		}
	}
	if ((map->nbr_c < 1) || (map->nbr_e < 1) || (map->nbr_p < 1))
	{
		ft_printf("Error\nMap must have at least one exit 'E',");
		ft_printf(" one collectible 'C' and one starting position 'P'\n");
		free_map_2d(map->map);
		return (0);
	}
	return (1);
}

char	**check_map(char *file, t_map *map)
{
	map->map = create_map(file, map);
	if (!map->map)
		return (0);
	if (!check_rectangle(map))
		return (0);
	map->nbr_e = 0;
	map->nbr_c = 0;
	map->nbr_p = 0;
	map->nbr_v = 0;
	if (!check_element(map))
		return (0);
	if (!(check_wall(map->map, 0, 0)))
		return (0);
	if (!check_wall(map->map, (map->nbr_line - 1), (map->nbr_octet - 1)))
		return (0);
	if (!check_valid_charac(map->map))
		return (0);
	check_mob_map(map);
	return (map->map);
}
