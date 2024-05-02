/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_perso_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:57 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:57 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_to_empty(t_win *win, t_perso *perso, void *image)
{
	images(win, win->zero, (perso->x * IMG_SIZE), (perso->y * IMG_SIZE));
	images(win, image, (perso->next_x * IMG_SIZE), (perso->next_y * IMG_SIZE));
	perso->x = perso->next_x;
	perso->y = perso->next_y;
}

static void	move_to_collectable(t_win *win, t_perso *perso, void *image)
{
	int	next_x;
	int	next_y;

	next_x = perso->next_x * IMG_SIZE;
	next_y = perso->next_y * IMG_SIZE;
	images(win, image, (perso->x * IMG_SIZE), (perso->y * IMG_SIZE));
	images(win, win->collec_end, next_x, next_y);
	win->map.map[perso->next_y][perso->next_x] = 'O';
	win->nbr_collec++;
}

static void	end(t_win *win, t_perso *perso, void *image, char *str)
{
	images(win, image, (perso->x * IMG_SIZE), (perso->y * IMG_SIZE));
	ft_printf("%s\n", str);
	end_program(win);
}

static int	move_to_perso(t_win *win, void *image, int next_X, int next_Y)
{
	win->perso.next_x = next_X;
	win->perso.next_y = next_Y;
	if (win->nbr_collec >= win->map.nbr_c)
		replace_carac(&win->map, 'S', 'E');
	if (win->map.map[next_Y][next_X] == '1'
		|| win->map.map[next_Y][next_X] == 'S'
		|| win->map.map[next_Y][next_X] == 'O')
		return (win->perso.nbr_movement);
	else if (win->map.map[next_Y][next_X] == '0'
		|| win->map.map[next_Y][next_X] == 'P')
		move_to_empty(win, &win->perso, image);
	else if (win->map.map[next_Y][next_X] == 'C')
		move_to_collectable(win, &win->perso, image);
	else if (win->map.map[next_Y][next_X] == 'E')
		end(win, &win->perso, win->zero, "You drank all milk bottles !");
	else if (win->map.map[next_Y][next_X] == 'V')
		end(win, &win->perso, win->zero, "You've just been attacked by a cow");
	win->perso.nbr_movement++;
	images(win, win->image.border1, 0, 0);
	images(win, win->image.border2, IMG_SIZE, 0);
	write_move_window(win, win->perso.nbr_movement);
	return (win->perso.nbr_movement);
}

int	move(t_win *win, void *image, int next_X, int next_Y)
{
	move_to_perso(win, image, next_X, next_Y);
	if (win->mob.lst_mob)
		move_to_ennemy(win, &win->map, &win->mob, win->mob.lst_mob);
	return (win->perso.nbr_movement);
}
