/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:17:06 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:06 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static void	put_element(t_win *win, char map, int width, int height)
{	
	if (map == 'P')
	{	
		if (win->nbr_perso == 1)
		{
			images(win, win->down, width, height);
			win->nbr_perso = win->nbr_perso + 1;
		}
		else
			images(win, win->zero, width, height);
	}
	else if (map == 'C')
		images(win, win->collec, width, height);
	else if (map == 'O')
		images(win, win->collec_end, width, height);
	else if (map == 'E' || map == 'S')
		images(win, win->exit, width, height);
}

static void	put_image_zero(t_win *win, int x, int y)
{
	if (win->perso.y == y && win->perso.x == x)
		images(win, win->anim.frame_image, win->image.w, win->image.h);
	else
		images(win, win->zero, win->image.w, win->image.h);
}

static void	put_ennemy(t_win *win, int y, int x, t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (tmp->next)
	{
		if (tmp->x == x && tmp->y == y)
			break ;
		tmp = tmp->next;
	}
	images(win, tmp->current_image, win->image.w, win->image.h);
}

static void	put_inside(t_win *win, t_map *map)
{
	int	y;
	int	x;

	win->image.h = IMG_SIZE;
	y = 0;
	while (map->map[++y] && (y < map->nbr_line - 1))
	{
		x = 0;
		win->image.w = IMG_SIZE;
		while (map->map[y][++x] && (x < map->nbr_octet - 1))
		{
			if (map->map[y][x] == '1')
				put_image_one(win, map, x, y);
			else if (map->map[y][x] == '0')
				put_image_zero(win, x, y);
			else if (map->map[y][x] == 'P' || map->map[y][x] == 'C'
					|| map->map[y][x] == 'O' || map->map[y][x] == 'S'
					|| map->map[y][x] == 'E')
				put_element(win, map->map[y][x], win->image.w, win->image.h);
			else if (map->map[y][x] == 'V')
				put_ennemy(win, y, x, win->mob.lst_mob);
			win->image.w = win->image.w + IMG_SIZE;
		}
		win->image.h = win->image.h + IMG_SIZE;
	}
}

void	put_image(t_win *win, t_map *map)
{
	replace_border(map);
	put_border(win, map);
	replace_carac(map, '2', '1');
	put_inside(win, map);
}
