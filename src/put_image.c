/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:05:15 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/24 18:05:15 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	*image(char *path, t_win *win)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(win->mlx, path, &width, &height));
}

static void	init_image(t_win *win)
{
	win->one = image("./sprites/water.xpm", win);
	win->zero = image("./sprites/sol.xpm", win);
	win->collec = image("./sprites/milk.xpm", win);
	win->exit = image("./sprites/trou.xpm", win);
	win->right = image("./sprites/perso_right1.xpm", win);
	win->left = image("./sprites/perso_left1.xpm", win);
	win->up = image("./sprites/perso_dos1.xpm", win);
	win->collec_end = image("./sprites/milk_empty.xpm", win);
	win->down = image("./sprites/perso_face1.xpm", win);
	if (!win->one || !win->zero || !win->collec || !win->exit || !win->right
		|| !win->left || !win->up || !win->collec_end || !win->down)
		end_program(win, 1);
}

static int	put_image_element(t_win *win, char map, int w, int h)
{	
	if (map == 'P')
	{	
		if (win->nbr_perso == 1)
		{
			mlx_put_image_to_window(win->mlx, win->win, win->down, w, h);
			win->nbr_perso = win->nbr_perso + 1;
		}
		else
			mlx_put_image_to_window(win->mlx, win->win, win->zero, w, h);
	}
	else if (map == 'C')
		mlx_put_image_to_window(win->mlx, win->win, win->collec, w, h);
	else if (map == 'E')
		mlx_put_image_to_window(win->mlx, win->win, win->exit, w, h);
	return (win->nbr_perso);
}

void	put_image(t_win *win, t_map *map)
{
	int	y;
	int	x;
	int	w;
	int	h;

	y = -1;
	h = 0;
	init_image(win);
	while (map->map[++y])
	{
		x = -1;
		w = 0;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx, win->win, win->one, w, h);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(win->mlx, win->win, win->zero, w, h);
			else if (map->map[y][x] == 'P' || map->map[y][x] == 'C'
					|| map->map[y][x] == 'E')
				win->nbr_perso = put_image_element(win, map->map[y][x], w, h);
			w = w + IMG_SIZE;
		}
		h = h + IMG_SIZE;
	}
}
