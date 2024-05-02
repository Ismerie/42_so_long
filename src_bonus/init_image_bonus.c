/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:35 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:35 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static void	*image_init(char *path, t_win *win)
{
	int	width;
	int	height;

	return (mlx_xpm_file_to_image(win->mlx, path, &width, &height));
}

void	init_image(t_win *win)
{
	win->one = image_init("./sprites/water.xpm", win);
	win->zero = image_init("./sprites/sol.xpm", win);
	win->collec = image_init("./sprites/milk.xpm", win);
	win->exit = image_init("./sprites/trou.xpm", win);
	win->right = image_init("./sprites/perso_right1.xpm", win);
	win->left = image_init("./sprites/perso_left1.xpm", win);
	win->up = image_init("./sprites/perso_dos1.xpm", win);
	win->collec_end = image_init("./sprites/milk_empty.xpm", win);
	win->down = image_init("./sprites/perso_face1.xpm", win);
	win->anim.down2 = image_init("./sprites/perso_face2.xpm", win);
	win->anim.up2 = image_init("./sprites/perso_dos2.xpm", win);
	win->anim.left2 = image_init("./sprites/perso_left2.xpm", win);
	win->anim.right2 = image_init("./sprites/perso_right2.xpm", win);
	if (!win->one || !win->zero || !win->collec || !win->exit || !win->right
		|| !win->left || !win->up || !win->collec_end || !win->down
		|| !win->anim.down2 || !win->anim.up2 || !win->anim.left2
		|| !win->anim.right2)
	{
		free_map_2d(win->map.map);
		exit (1);
	}
}

static void	init_border2(t_win *win, t_image *image)
{
	image->water_2ld = image_init("./sprites/water_2LD.xpm", win);
	image->water_2rl = image_init("./sprites/water_2RL.xpm", win);
	image->water_2ud = image_init("./sprites/water_2UD.xpm", win);
	image->water_3d = image_init("./sprites/water_3D.xpm", win);
	image->water_3l = image_init("./sprites/water_3L.xpm", win);
	image->water_3r = image_init("./sprites/water_3R.xpm", win);
	image->water_3u = image_init("./sprites/water_3U.xpm", win);
	if (!image->water_2ld || !image->water_2rl || !image->water_2ud
		|| !image->water_3d || !image->water_3l || !image->water_3r
		|| !image->water_3u)
	{
		free_map_2d(win->map.map);
		exit (1);
	}
}

void	init_border(t_win *win, t_image *image)
{
	init_border2(win, image);
	image->water = image_init("./sprites/water.xpm", win);
	image->water_close = image_init("./sprites/water_close.xpm", win);
	image->water_d = image_init("./sprites/water_down.xpm", win);
	image->water_u = image_init("./sprites/water_up.xpm", win);
	image->water_l = image_init("./sprites/water_left.xpm", win);
	image->water_r = image_init("./sprites/water_right.xpm", win);
	image->water_2ru = image_init("./sprites/water_2RU.xpm", win);
	image->water_2rd = image_init("./sprites/water_2RD.xpm", win);
	image->water_2lu = image_init("./sprites/water_2LU.xpm", win);
	if (!image->water || !image->water_close || !image->water_d
		|| !image->water_u || !image->water_l || !image->water_r
		|| !image->water_2ru ||!image->water_2rd || !image->water_2lu)
	{
		free_map_2d(win->map.map);
		exit (1);
	}
}

void	init_mob(t_win *win, t_mob *mob)
{
	win->mob.lst_mob = NULL;
	mob->right1 = image_init("./sprites/cow_right1.xpm", win);
	mob->right2 = image_init("./sprites/cow_right2.xpm", win);
	mob->right3 = image_init("./sprites/cow_right3.xpm", win);
	mob->left1 = image_init("./sprites/cow_left1.xpm", win);
	mob->left2 = image_init("./sprites/cow_left2.xpm", win);
	mob->left3 = image_init("./sprites/cow_left3.xpm", win);
	if (!mob->right1 || !mob->right2 || !mob->right3 || !mob->left1
		|| !mob->left2 || !win->left || !mob->left3)
	{
		free_map_2d(win->map.map);
		exit (1);
	}
}
