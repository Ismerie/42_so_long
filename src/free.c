/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:33:57 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/22 14:33:57 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map_2d(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	return (0);
}

static void	destroy_image_map(t_win *win)
{
	mlx_destroy_image(win->mlx, win->one);
	mlx_destroy_image(win->mlx, win->zero);
	mlx_destroy_image(win->mlx, win->collec);
	mlx_destroy_image(win->mlx, win->collec_end);
	mlx_destroy_image(win->mlx, win->exit);
}

static void	destroy_image_perso(t_win *win)
{
	mlx_destroy_image(win->mlx, win->right);
	mlx_destroy_image(win->mlx, win->left);
	mlx_destroy_image(win->mlx, win->up);
	mlx_destroy_image(win->mlx, win->down);
}

void	end_program(t_win *win, int error)
{
	free_map_2d(win->map.map);
	destroy_image_perso(win);
	destroy_image_map(win);
	mlx_destroy_window(win->mlx, win->win);
	exit (error);
}
