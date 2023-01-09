/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mob_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:17:13 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:17:13 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

static int	check_mob(t_lst_mob *mob, int y, int x, t_win *win)
{
	if (win->map.map[y][x] == 'V')
	{
		mob->current_image = win->mob.right1;
		mob->current_image2 = win->mob.right2;
		mob->current_image3 = win->mob.right3;
		mob->x = x;
		mob->y = y;
		return (1);
	}
	return (0);
}

void	put_mobs(t_win *win, t_lst_mob *mob)
{
	int			y;
	int			x;
	t_lst_mob	*tmp;
	t_lst_mob	*new;

	y = -1;
	tmp = mob;
	while (win->map.map[++y])
	{
		x = -1;
		while (win->map.map[y][++x])
		{
			if (check_mob(tmp, y, x, win))
			{
				new = malloc(sizeof(t_lst_mob));
				if (!new)
					end_program(win);
				tmp->next = new;
				tmp = tmp->next;
				tmp->next = 0;
			}
		}
	}
}
