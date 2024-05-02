/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:44:46 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/16 19:44:46 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_win	win;

	if (!valid_file(argc, argv[1]))
		return (0);
	win.map.map = check_map(argv[1], &win.map);
	if (!win.map.map)
		return (0);
	start(&win, &win.map);
	mlx_loop(win.mlx);
	free_map_2d(win.map.map);
	return (0);
}
