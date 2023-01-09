/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:27:49 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/24 20:27:49 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	move_to_empty(t_win *win, t_perso *perso, void *image)
{
	int	width;
	int	height;
	int	width_next;
	int	height_next;

	width = perso->x * IMG_SIZE;
	height = perso->y * IMG_SIZE;
	width_next = perso->next_x * IMG_SIZE;
	height_next = perso->next_y * IMG_SIZE;
	mlx_put_image_to_window(win->mlx, win->win, win->zero, width, height);
	mlx_put_image_to_window(win->mlx, win->win, image, width_next, height_next);
	perso->x = perso->next_x;
	perso->y = perso->next_y;
}

static void	move_to_collectable(t_win *win, t_perso *perso, void *image)
{
	int	width;
	int	height;
	int	w_nxt;
	int	h_nxt;

	width = perso->x * IMG_SIZE;
	height = perso->y * IMG_SIZE;
	w_nxt = perso->next_x * IMG_SIZE;
	h_nxt = perso->next_y * IMG_SIZE;
	mlx_put_image_to_window(win->mlx, win->win, image, width, height);
	mlx_put_image_to_window(win->mlx, win->win, win->collec_end, w_nxt, h_nxt);
	win->map.map[perso->next_y][perso->next_x] = 'O';
}

static void	move_to_exit(t_win *win, t_perso *perso, void *image)
{
	int	width;
	int	height;

	width = perso->x * IMG_SIZE;
	height = perso->y * IMG_SIZE;
	mlx_put_image_to_window(win->mlx, win->win, image, width, height);
	ft_printf("You drank all milk bottles !\n");
	end_program(win, 0);
}

int	move_to(t_win *win, void *image, int next_X, int next_Y)
{
	win->perso.next_x = next_X;
	win->perso.next_y = next_Y;
	if (win->nbr_collec >= win->map.nbr_c)
		replace_carac(win, &win->map, 'S', 'E');
	if (win->map.map[next_Y][next_X] == '1'
		|| win->map.map[next_Y][next_X] == 'S'
		|| win->map.map[next_Y][next_X] == 'O')
		return (win->perso.nbr_movement);
	else if (win->map.map[next_Y][next_X] == '0'
			|| win->map.map[next_Y][next_X] == 'P')
		move_to_empty(win, &win->perso, image);
	else if (win->map.map[next_Y][next_X] == 'C')
	{
		move_to_collectable(win, &win->perso, image);
		win->nbr_collec++;
	}
	else if (win->map.map[next_Y][next_X] == 'E')
	{
		move_to_exit(win, &win->perso, win->zero);
	}
	win->perso.nbr_movement++;
	ft_printf("Total movement : %d\n", win->perso.nbr_movement);
	return (win->perso.nbr_movement);
}
