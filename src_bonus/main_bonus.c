/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:42 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:42 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (!valid_file(argc, argv[1]))
		return (0);
	win.map.map = check_map(argv[1], &win.map);
	if (!win.map.map)
		return (0);
	start(&win, &win.map);
	mlx_loop_hook(win.mlx, animation, &win);
	mlx_loop(win.mlx);
	free_map_2d(win.map.map);
	return (0);
}
