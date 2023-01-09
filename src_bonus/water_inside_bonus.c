/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   water_inside_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:17:36 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:36 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

void	images(t_win *win, void *image, int x, int y)
{
	mlx_put_image_to_window(win->mlx, win->win, image, x, y);
}

static void	put_border1(t_win *win, t_image *image, int x, int y)
{
	if (win->map.map[y - 1][x] == '1')
		images(win, image->water_3u, image->w, image->h);
	if (win->map.map[y + 1][x] == '1')
		images(win, image->water_3d, image->w, image->h);
	if (win->map.map[y][x - 1] == '1')
		images(win, image->water_3l, image->w, image->h);
	if (win->map.map[y][x + 1] == '1')
		images(win, image->water_3r, image->w, image->h);
}

static void	put_border2(t_win *win, t_image *image, int x, int y)
{
	if (win->map.map[y - 1][x] == '1' && win->map.map[y][x - 1] == '1')
		images(win, image->water_2lu, image->w, image->h);
	if (win->map.map[y + 1][x] == '1' && win->map.map[y][x - 1] == '1')
		images(win, image->water_2ld, image->w, image->h);
	if (win->map.map[y + 1][x] == '1' && win->map.map[y][x + 1] == '1')
		images(win, image->water_2rd, image->w, image->h);
	if (win->map.map[y - 1][x] == '1' && win->map.map[y][x + 1] == '1')
		images(win, image->water_2ru, image->w, image->h);
	if (win->map.map[y][x - 1] == '1' && win->map.map[y][x + 1] == '1')
		images(win, image->water_2ud, image->w, image->h);
	if (win->map.map[y - 1][x] == '1' && win->map.map[y + 1][x] == '1')
		images(win, image->water_2rl, image->w, image->h);
}

static void	put_border3(t_win *win, t_image *image, int x, int y)
{
	if (win->map.map[y - 1][x] != '1')
		images(win, image->water_d, image->w, image->h);
	if (win->map.map[y + 1][x] != '1')
		images(win, image->water_u, image->w, image->h);
	if (win->map.map[y][x - 1] != '1')
		images(win, image->water_r, image->w, image->h);
	if (win->map.map[y][x + 1] != '1')
		images(win, image->water_l, image->w, image->h);
}

void	put_image_one(t_win *win, t_map *map, int x, int y)
{
	int	count_1;

	count_1 = 0;
	win->map = win->map;
	map->map = map->map;
	if (map->map[y - 1][x] == '1')
		count_1++;
	if (map->map[y][x - 1] == '1')
		count_1++;
	if (map->map[y + 1][x] == '1')
		count_1++;
	if (map->map[y][x + 1] == '1')
		count_1++;
	if (count_1 == 0)
		images(win, win->image.water_close, win->image.w, win->image.h);
	if (count_1 == 4)
		images(win, win->image.water, win->image.w, win->image.h);
	if (count_1 == 1)
		put_border1(win, &win->image, x, y);
	if (count_1 == 2)
		put_border2(win, &win->image, x, y);
	if (count_1 == 3)
		put_border3(win, &win->image, x, y);
}
