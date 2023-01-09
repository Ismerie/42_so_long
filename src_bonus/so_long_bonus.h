/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:16:04 by igeorge           #+#    #+#             */
/*   Updated: 2022/05/09 17:16:04 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// Home use Xming on Windows, 42 use Xquartz on Mac
# define IMG_SIZE 45
# define UP 122 // 42:119 or 13   Home:122
# define DOWN 115 // 42:115 or 1   Home:115
# define LEFT 113 // 42:97 or 0    Home:113
# define RIGHT 100 // 42:100 or 2   Home:100
# define ESC 65307 // 42:53 Home:65307
# define SPEED_ANIM 150 // 42:600  Home:150

typedef struct s_map {
	char	**map;
	int		nbr_line; 
	int		nbr_octet;
	int		nbr_e;
	int		nbr_c;
	int		nbr_p;
	int		nbr_v;
}	t_map;

typedef struct s_perso {
	int	x;
	int	y;
	int	next_x;
	int	next_y;
	int	nbr_movement;
}	t_perso;

typedef struct s_anim {
	void	*frame_image;
	void	*current_image;
	void	*current_image2;
	void	*down2;
	void	*up2;
	void	*left2;
	void	*right2;
	int		frame;
	int		frame_max;
}	t_anim;

typedef struct s_image {
	int		w;
	int		h;
	void	*water;
	void	*water_close;
	void	*water_d;
	void	*water_u;
	void	*water_l;
	void	*water_r;
	void	*water_2ru;
	void	*water_2rd;
	void	*water_2lu;
	void	*water_2ld;
	void	*water_2rl;
	void	*water_2ud;
	void	*water_3d;
	void	*water_3l;
	void	*water_3u;
	void	*water_3r;
	void	*border1;
	void	*border2;
}	t_image;

typedef struct s_lst_mob {
	void				*current_image;
	void				*current_image2;
	void				*current_image3;
	int					x;
	int					y;
	struct s_lst_mob	*next;
}	t_lst_mob;

typedef struct s_mob {
	void		*right1;
	void		*right2;
	void		*right3;
	void		*left1;
	void		*left2;
	void		*left3;
	t_lst_mob	*lst_mob;
}	t_mob;

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
	t_image	image;
	t_mob	mob;
	t_anim	anim;
}	t_win;

char	*read_file(char *file);
char	**create_map(char *file, t_map *map);
int		free_map_2d(char **map);
void	free_lst(t_lst_mob *mob);
void	check_mob_map(t_map *map);
char	**check_map(char *file, t_map *map);
int		valid_file(int argc, char *argv);
void	start(t_win *win, t_map *map);
void	init_image(t_win *win);
void	init_border(t_win *win, t_image *image);
void	init_mob(t_win *win, t_mob *mob);
void	put_image(t_win *win, t_map *map);
void	move_perso(t_win *win, t_map *map);
void	replace_carac(t_map *map, char remove, char put);
int		data_perso(t_perso *perso, t_map *map);
void	end_program(t_win *win);
int		animation(t_win *win);
void	change_animation(int keycode, t_win *win);
void	count_collectable(t_map *map, t_win *win);
void	write_move_window(t_win *win, int nbr_movement);
void	replace_border(t_map *map);
void	put_border(t_win *win, t_map *map);
void	put_image_one(t_win *win, t_map *map, int x, int y);
void	put_mobs(t_win *win, t_lst_mob *mob);
int		move(t_win *win, void *image, int next_X, int next_Y);
void	move_to_ennemy(t_win *win, t_map *map, t_mob *mob, t_lst_mob *lst_mob);
void	images(t_win *win, void *image, int x, int y);

#endif