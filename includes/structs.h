/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:04 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 16:18:11 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <math.h>
# include <unistd.h>


typedef struct s_map
{
	int					h;
	int					w;
	char				**map;
	char				**temp;
	int					bool;
	int					steps;
	int					collect;
	int					enemies;
}		t_map;

typedef struct s_obj
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	unsigned int		color;
	int					w;
	int					h;
	int					picked;
}		t_obj;

typedef struct s_bad_guys
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	unsigned int		color;
	int					w;
	int					h;
	double				x;
	double				y;
	int					is_there;
}		t_bad_guys;

typedef struct s_player
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
	unsigned int		color;
	int					w;
	int					h;
	double				x;
	double				y;
	int					gun;
	int					walk;
	int					died;
}		t_player;

typedef struct s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
}		t_window;


// global structs

t_obj			*canva(void);
t_obj			*egg(void);
t_window		*data(void);
t_map			*map(void);
t_obj			*floors(void);
t_obj			*wall(void);
t_player		*player(void);
t_obj			*chest(void);

// map and errors and utils

int				makeground(t_bad_guys *e);
int				wall_checker(char **map);
size_t			line_len(char *str);
int				ft_strncmp(char *s1, char *s2, int n);
int				player_checker(char **map);
int				map_rectangular(char **map);
int				colletibles(char **maps);
int				exit_ok(char **map);
char			**copy_map(char **newmap);
int				get_maps(char *file);
int				path_ver(void);
int				errors_and_map_check(char **map);
void			floodfill(char to_fill, char **tmp, int x, int y);
char			*ft_itoa(int n);
int				map_letters(void);
t_bad_guys		**array_of_structs(void);
int				map_name(char *str, char *str2, int ac);
void 			alloc_bad_guys(t_bad_guys **e);
/* void 				converter(void); */

// print map and sprites
void			print_img(t_obj *img, int x, int y);
unsigned int	get_img_pixel(t_obj *img, int x, int y);
void			my_mlx_pixel_put(t_obj *img, int x, int y, unsigned int color);
void			make_addr(void);
void			sprites_guy(int n, t_player *tmp);
void			sprites_guy_inv(int n, t_player *tmp);
void			sprites_guy_dead(t_player *tmp);
void			chest_open(t_obj *tmp);
void			bad_guys_sprites(t_bad_guys *e, int i, int sprite);

// collisions and bad guys
int				collision(double player_y, double player_x, int pos);
int				collision_collect(double player_y, double player_x);
int				collision_exit(double player_y, double player_x);
int				collision_enemies(double player_y, double player_x,
					t_bad_guys *e);
void			bad_guys_1(void);
void			make_bad_guys_walk(t_bad_guys *e, int j);
void			bad_guys_2(t_bad_guys *e);
void			make_bad_guys(t_bad_guys *e, int times, double y, double x);

// others
int				ft_run(int keycode);
int				free_stuff(void);
int				loop(void *param);
int				close_window(int keycode);
int				closes(void);
void			free_stuff_2(t_bad_guys *e);

#endif