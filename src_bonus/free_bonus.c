/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:26 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:26 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	free_map_2d(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}

void	free_lst(t_lst_mob *mob)
{
	t_lst_mob	*tmp;

	tmp = mob;
	while (mob)
	{
		tmp = mob->next;
		free(mob);
		mob = tmp;
	}
}

static void	destroy_image_map(t_win *win)
{
	mlx_destroy_image(win->mlx, win->image.water);
	mlx_destroy_image(win->mlx, win->image.water_close);
	mlx_destroy_image(win->mlx, win->image.water_d);
	mlx_destroy_image(win->mlx, win->image.water_u);
	mlx_destroy_image(win->mlx, win->image.water_l);
	mlx_destroy_image(win->mlx, win->image.water_r);
	mlx_destroy_image(win->mlx, win->image.water_2ru);
	mlx_destroy_image(win->mlx, win->image.water_2rd);
	mlx_destroy_image(win->mlx, win->image.water_2lu);
	mlx_destroy_image(win->mlx, win->image.water_2ld);
	mlx_destroy_image(win->mlx, win->image.water_2rl);
	mlx_destroy_image(win->mlx, win->image.water_2ud);
	mlx_destroy_image(win->mlx, win->image.water_3d);
	mlx_destroy_image(win->mlx, win->image.water_3u);
	mlx_destroy_image(win->mlx, win->image.water_3r);
	mlx_destroy_image(win->mlx, win->image.water_3l);
	mlx_destroy_image(win->mlx, win->one);
	mlx_destroy_image(win->mlx, win->zero);
	mlx_destroy_image(win->mlx, win->collec);
	mlx_destroy_image(win->mlx, win->collec_end);
	mlx_destroy_image(win->mlx, win->exit);
}

static void	destroy_image_perso(t_win *win, t_mob *mob, t_anim *anim)
{
	mlx_destroy_image(win->mlx, win->right);
	mlx_destroy_image(win->mlx, win->left);
	mlx_destroy_image(win->mlx, win->up);
	mlx_destroy_image(win->mlx, win->down);
	mlx_destroy_image(win->mlx, win->anim.right2);
	mlx_destroy_image(win->mlx, anim->left2);
	mlx_destroy_image(win->mlx, anim->up2);
	mlx_destroy_image(win->mlx, anim->down2);
	mlx_destroy_image(win->mlx, mob->right1);
	mlx_destroy_image(win->mlx, mob->right2);
	mlx_destroy_image(win->mlx, mob->right3);
	mlx_destroy_image(win->mlx, mob->left1);
	mlx_destroy_image(win->mlx, mob->left2);
	mlx_destroy_image(win->mlx, mob->left3);
}

void	end_program(t_win *win)
{
	free_lst(win->mob.lst_mob);
	free_map_2d(win->map.map);
	destroy_image_map(win);
	destroy_image_perso(win, &win->mob, &win->anim);
	mlx_destroy_window(win->mlx, win->win);
	exit (0);
}
