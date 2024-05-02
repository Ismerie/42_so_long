/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:34:55 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/24 16:34:55 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static int	close_win(int keycode, t_win *win)
{
	if (keycode == ESC)
		end_program(win, 0);
	else if (keycode == UP)
		move_to(win, win->up, win->perso.x, (win->perso.y - 1));
	else if (keycode == DOWN)
		move_to(win, win->down, win->perso.x, (win->perso.y + 1));
	else if (keycode == LEFT)
		move_to(win, win->left, (win->perso.x - 1), win->perso.y);
	else if (keycode == RIGHT)
		move_to(win, win->right, (win->perso.x + 1), win->perso.y);
	return (0);
}

static int	close_win_cross(t_win *win)
{	
	end_program(win, 0);
	return (0);
}

static void	init_game(t_win *win, t_map *map)
{	
	int	max_y;
	int	max_x;

	max_x = map->nbr_octet * IMG_SIZE;
	max_y = map->nbr_line * IMG_SIZE;
	if (max_x >= 2560 || max_y >= 1440)
	{
		ft_printf("The map is too big\n");
		free_map_2d(win->map.map);
		exit (1);
	}
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, max_x, max_y, "so_long");
	mlx_hook(win->win, 2, 1L << 0, close_win, win);
	mlx_hook(win->win, 17, 0L, close_win_cross, win);
}

void	start(t_win *win, t_map *map)
{
	map->nbr_c = 0;
	win->nbr_collec = 0;
	win->perso.nbr_movement = 0;
	init_game(win, map);
	win->nbr_perso = 1;
	put_image(win, map);
	replace_carac(win, map, 'E', 'S');
	data_perso(&win->perso, map);
}
