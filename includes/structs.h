/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:04 by vcacador          #+#    #+#             */
/*   Updated: 2023/02/15 00:33:56 by vcacador         ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx;

typedef struct s_map
{
	int		h;
	int		w;
	char	**map;
	char	**temp;
	int		bool;
}		t_map;

typedef struct s_bomb
{
	void	*img;
	int		x;
	int		y;
}		t_bomb;

typedef struct s_floors
{
	void	*img;
	int		x;
	int		y;
}		t_floors;

typedef struct s_wall
{
	void	*img;
	int		x;
	int		y;
}		t_wall;

typedef struct s_player
{
	void	*img;
	int		x;
	int		y;
}		t_player;

typedef struct s_game
{
	t_mlx		t_mlx;
	t_map		t_map;
	t_floors		t_floor;
	t_wall		t_wall;
	t_player	t_player;
}			t_game;


t_mlx 		*mlx(void);
t_map		*map(void);
t_floors	*floors(void);
t_wall		*wall(void);
t_player 	*player(void);
t_bomb 		*bomb(void);


int		makegound(void);
size_t	line_len(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
int		wall_checker(char **map);
int		player_checker(char **map);
int		map_rectangular(char **map);
int		colletibles(char **map);
int		exit_ok(char **map);
char	**copy_map(char **newmap);
t_game	*game(void);
int		get_maps(char *file);
int		path_ver(void);
int		errors_and_map_check(char **map);

#endif