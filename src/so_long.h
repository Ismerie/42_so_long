/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:58:10 by igeorge           #+#    #+#             */
/*   Updated: 2022/04/15 15:58:10 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_mac/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// Home use Xming on Windows, 42 use Xquartz on Mac
# define IMG_SIZE 45
# define UP 122 // 42:119 or 13   Home:122
# define DOWN 115 // 42:115 or 1   Home:115
# define LEFT 113 // 42:97 or 0    Home:113
# define RIGHT 100 // 42:100 or 2   Home:100
# define ESC 65307 // 42:53 Home:65307

typedef struct s_map {
	char	**map;
	int		nbr_line;
	int		nbr_octet;
	int		nbr_e;
	int		nbr_c;
	int		nbr_p;
}	t_map;

typedef struct s_perso {
	int	x;
	int	y;
	int	next_x;
	int	next_y;
	int	nbr_movement;
}	t_perso;

typedef struct s_win {
	void	*mlx;
	void	*win;
	void	*one;
	void	*zero;
	void	*collec;
	void	*collec_end;
	void	*exit;
	void	*right;
	void	*left;
	void	*up;
	void	*down;
	int		nbr_perso;
	int		nbr_collec;
	t_map	map;
	t_perso	perso;
}	t_win;

char	*read_file(char *file);
char	**create_map(char *file, t_map *map);
int		free_map_2d(char **map);
char	**check_map(char *file, t_map *map);
int		valid_file(int argc, char *argv);
void	start(t_win *win, t_map *map);
void	put_image(t_win *win, t_map *map);
void	move_perso(t_win *win, t_map *map);
void	replace_carac(t_win *win, t_map *map, char remove, char put);
int		data_perso(t_perso *perso, t_map *map);
int		move_to(t_win *win, void *image, int next_X, int next_Y);
void	end_program(t_win *win, int error);

#endif