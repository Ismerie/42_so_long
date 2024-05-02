  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:18:46 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/25 14:18:46 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

/*secure exits*/
void	replace_carac(t_win *win, t_map *map, char remove, char put)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == remove)
				map->map[y][x] = put;
			if (map->map[y][x] == 'C' && win->nbr_collec == 0)
				map->nbr_c++;
		}
	}
}

int	data_perso(t_perso *perso, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'P')
			{
				perso->x = x;
				perso->y = y;
				return (0);
			}
		}
	}
	return (1);
}
