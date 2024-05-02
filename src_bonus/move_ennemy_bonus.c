/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ennemy_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:49 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:49 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_empty(t_win *win, t_map *map, t_lst_mob *lst_mob, int next_x)
{	
	int	y;

	y = lst_mob->y * IMG_SIZE;
	images(win, win->zero, (next_x * IMG_SIZE), y);
	map->map[lst_mob->y][lst_mob->x] = '0';
	images(win, lst_mob->current_image, (next_x * IMG_SIZE), y);
	map->map[lst_mob->y][next_x] = 'V';
	lst_mob->x = next_x;
}

static void	move_to_perso(t_win *win, t_lst_mob *lst_mob, int next_x, int x)
{
	int	y;

	y = lst_mob->y * IMG_SIZE;
	images(win, win->zero, (x * IMG_SIZE), y);
	images(win, lst_mob->current_image, (next_x * IMG_SIZE), y);
	printf("You've just been attacked by a cow...\n");
	end_program(win);
}

static void	move_to_wall(t_win *win, t_lst_mob *lst_mob, void *image)
{
	images(win, image, (lst_mob->x * IMG_SIZE), (lst_mob->y * IMG_SIZE));
	lst_mob->current_image = image;
}

static void	move_action(t_win *win, t_lst_mob *tmp, t_map *map, void *image)
{
	int	next_x;
	int	x;
	int	y;

	x = tmp->x;
	y = tmp->y;
	if (image == win->mob.left1)
		next_x = x + 1;
	else
		next_x = x - 1;
	if (y == win->perso.y && next_x == win->perso.x)
		move_to_perso(win, tmp, next_x, x);
	else if (map->map[y][next_x] == 'C' || map->map[y][next_x] == 'E'
		|| map->map[y][next_x] == 'S' || map->map[y][next_x] == 'V'
		|| map->map[y][next_x] == '1' || map->map[y][next_x] == 'O')
		move_to_wall(win, tmp, image);
	else if (map->map[y][next_x] == '0')
		move_empty(win, map, tmp, next_x);
}

void	move_to_ennemy(t_win *win, t_map *map, t_mob *mob, t_lst_mob *lst_mob)
{	
	t_lst_mob	*tmp;

	tmp = lst_mob;
	while (tmp->next != 0)
	{
		if (tmp->current_image == mob->right1
			|| tmp->current_image == mob->right2
			|| tmp->current_image == mob->right3)
			move_action(win, tmp, map, mob->left1);
		else if (tmp->current_image == mob->left1
			|| tmp->current_image == mob->left2
			|| tmp->current_image == mob->left3)
			move_action(win, tmp, map, mob->right1);
		tmp = tmp->next;
	}
}
