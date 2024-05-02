/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:19 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:19 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

/*secure exits, open collectable*/
void	replace_carac(t_map *map, char remove, char put)
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
		}
	}
}

void	count_collectable(t_map *map, t_win *win)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 'C')
				map->nbr_c++;
		}
		if (map->nbr_line <= 10 || map->nbr_octet <= 10)
			win->anim.frame_max = SPEED_ANIM;
		else if ((map->nbr_line > 10 && map->nbr_line < 30)
			|| (map->nbr_octet > 20 && map->nbr_line < 30))
			win->anim.frame_max = SPEED_ANIM / 5;
		if (map->nbr_line >= 30 || map->nbr_octet >= 30)
			win->anim.frame_max = SPEED_ANIM / 10;
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

void	replace_border(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (y == 0 || x == 0 || y == (map->nbr_line - 1)
				|| x == (map->nbr_octet - 1))
				map->map[y][x] = '2';
		}
	}
}
