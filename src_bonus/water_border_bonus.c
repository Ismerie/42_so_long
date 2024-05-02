/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_border_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:17:29 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:29 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static void	put_border_vertical(t_win *win, t_map *map, int y, void *border)
{	
	int	x;

	images(win, win->image.water, 0, win->image.h);
	win->image.border1 = win->image.water;
	win->image.w = IMG_SIZE;
	x = 0;
	while (map->map[y][++x] && (x != map->nbr_octet - 1))
	{		
		if (map->map[y][x] == '1')
		{
			images(win, win->image.water, win->image.w, win->image.h);
			write_move_window(win, win->perso.nbr_movement);
			if (y == 1 && x == 1)
				win->image.border2 = win->image.water;
		}
		else
		{
			images(win, border, win->image.w, win->image.h);
			write_move_window(win, win->perso.nbr_movement);
			if (y == 1 && x == 1)
				win->image.border2 = border;
		}
		win->image.w = win->image.w + IMG_SIZE;
	}
	images(win, win->image.water, win->image.w, win->image.h);
}

static void	put_border_horizontal(t_win *win, t_map *map, int x, void *border)
{
	int	y;

	win->image.h = IMG_SIZE;
	y = 0;
	while (map->map[++y][x] && (y != map->nbr_line - 1))
	{
		if (map->map[y][x] == '1')
			images(win, win->image.water, win->image.w, win->image.h);
		else
			images(win, border, win->image.w, win->image.h);
		win->image.h = win->image.h + IMG_SIZE;
	}
}

void	put_border(t_win *win, t_map *map)
{
	write_move_window(win, win->perso.nbr_movement);
	win->image.h = 0;
	put_border_vertical(win, map, 1, win->image.water_u);
	win->image.h = (map->nbr_line - 1) * IMG_SIZE;
	put_border_vertical(win, map, (map->nbr_line - 2), win->image.water_d);
	win->image.w = 0;
	put_border_horizontal(win, map, 1, win->image.water_l);
	win->image.w = (map->nbr_octet - 1) * IMG_SIZE;
	put_border_horizontal(win, map, (map->nbr_octet - 2), win->image.water_r);
	write_move_window(win, win->perso.nbr_movement);
}
