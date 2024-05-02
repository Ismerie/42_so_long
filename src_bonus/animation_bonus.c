/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:12 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:12 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static void	change_image(t_win *win, void *image1, void *image2)
{
	int	frame_max_half;

	frame_max_half = win->anim.frame_max / 2;
	win->anim.current_image = image1;
	win->anim.current_image2 = image2;
	if (win->anim.frame >= frame_max_half
		&& win->anim.frame < win->anim.frame_max)
		win->anim.frame_image = image2;
	if (win->anim.frame == win->anim.frame_max
		|| win->anim.frame < (frame_max_half - 1))
		win->anim.frame_image = image1;
}

void	change_animation(int keycode, t_win *win)
{
	if (keycode == UP)
		change_image(win, win->up, win->anim.up2);
	else if (keycode == DOWN)
		change_image(win, win->down, win->anim.down2);
	else if (keycode == LEFT)
		change_image(win, win->left, win->anim.left2);
	else if (keycode == RIGHT)
		change_image(win, win->right, win->anim.right2);
}

static void	change_animation_ennemy(t_win *win, t_lst_mob *lst_mob)
{
	t_lst_mob	*tmp;

	tmp = lst_mob;
	while (tmp->next != 0)
	{
		if (tmp->current_image == win->mob.right1)
			tmp->current_image = win->mob.right2;
		else if (tmp->current_image == win->mob.left1)
			tmp->current_image = win->mob.left2;
		else if (tmp->current_image == win->mob.right2)
			tmp->current_image = win->mob.right3;
		else if (tmp->current_image == win->mob.left2)
			tmp->current_image = win->mob.left3;
		else if (tmp->current_image == win->mob.right3)
			tmp->current_image = win->mob.right1;
		else if (tmp->current_image == win->mob.left3)
			tmp->current_image = win->mob.left1;
		tmp = tmp->next;
	}
}

int	animation(t_win *win)
{
	int	frame_max_one_third;

	frame_max_one_third = win->anim.frame_max / 3;
	if (win->anim.frame == frame_max_one_third
		|| win->anim.frame == (frame_max_one_third * 2))
	{
		win->anim.frame_image = win->anim.current_image2;
		if (win->mob.lst_mob)
			change_animation_ennemy(win, win->mob.lst_mob);
	}
	else if (win->anim.frame == win->anim.frame_max)
	{
		win->anim.frame_image = win->anim.current_image;
		if (win->mob.lst_mob)
			change_animation_ennemy(win, win->mob.lst_mob);
		win->anim.frame = 0;
	}
	if (win->anim.frame == 10)
		write_move_window(win, win->perso.nbr_movement);
	else
		put_image(win, &win->map);
	win->anim.frame++;
	return (1);
}
