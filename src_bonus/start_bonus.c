/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:17:22 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:22 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static int	input(int keycode, t_win *win)
{
	if (keycode == ESC)
		end_program(win);
	else if (keycode == UP)
		move(win, win->up, win->perso.x, (win->perso.y - 1));
	else if (keycode == DOWN)
		move(win, win->down, win->perso.x, (win->perso.y + 1));
	else if (keycode == LEFT)
		move(win, win->left, (win->perso.x - 1), win->perso.y);
	else if (keycode == RIGHT)
		move(win, win->right, (win->perso.x + 1), win->perso.y);
	change_animation(keycode, win);
	return (0);
}

static int	close_win_cross(t_win *win)
{	
	end_program(win);
	return (0);
}

void	write_move_window(t_win *win, int nbr_movement)
{
	char	*movement;

	movement = ft_itoa(nbr_movement);
	mlx_put_image_to_window(win->mlx, win->win, win->image.water, 0, 0);
	mlx_string_put(win->mlx, win->win, 2, 15, 0xFF660099, "Total");
	mlx_string_put(win->mlx, win->win, 10, 30, 0xFF660099, movement);
	free(movement);
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
	mlx_hook(win->win, 2, 1L << 0, input, win);
	mlx_hook(win->win, 17, 0L, close_win_cross, win);
}

void	start(t_win *win, t_map *map)
{	

	map->nbr_c = 0;
	init_game(win, map);
	win->nbr_collec = 0;
	win->perso.nbr_movement = 0;
	win->anim.frame = 0;
	init_image(win);
	init_border(win, &win->image);
	init_mob(win, &win->mob);
	win->anim.current_image = win->down;
	win->anim.current_image2 = win->anim.down2;
	win->anim.frame_image = win->anim.current_image;
	data_perso(&win->perso, map);
	win->nbr_perso = 1;
	count_collectable(map, win);
	replace_carac(map, 'E', 'S');
	replace_carac(map, 'P', '0');
	if (win->map.nbr_v > 0)
	{
		win->mob.lst_mob = malloc(sizeof(t_lst_mob));
		if (!win->mob.lst_mob)
			end_program(win);
		win->mob.lst_mob->next = 0;
		put_mobs(win, win->mob.lst_mob);
	}
	put_image(win, map);
}
