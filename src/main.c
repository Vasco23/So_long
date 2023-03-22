/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:28:20 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/22 12:29:36 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

void get_stuff(t_bad_guys *e);

int main (int ac, char **av)
{
	t_bad_guys *e;

	if (map_name(av[1], ".ber", ac) != 0)
		exit(0);
	if (get_maps(av[1]) > 0)
		exit(ft_printf("Error\n"));
	if (errors_and_map_check(map()->map) > 0)
		return(0);
	e = array_of_structs();
	get_stuff(e);
	mlx_loop_hook(mlx()->mlx_ptr, loop, e);
	mlx_hook(mlx()->win_ptr, 17, 1L<<2, closes, mlx()->mlx_ptr);
	mlx_hook(mlx()->win_ptr, 2, 1L<<0, ft_run, mlx()->mlx_ptr);
	mlx_key_hook(mlx()->win_ptr, close_window, mlx()->mlx_ptr);
	mlx_loop(mlx()->mlx_ptr);
	return (0);
}


void get_stuff(t_bad_guys *e)
{
	mlx()->mlx_ptr = mlx_init();
	mlx()->win_ptr = mlx_new_window(mlx()->mlx_ptr, map()->w * 64, (map()->h + 1) * 64 , "so_long");
	canva()->img = mlx_new_image(mlx()->mlx_ptr, map()->w * 64, (map()->h + 1) * 64);
	canva()->w = map()->w * 64;
	canva()->h = (map()->h + 1) * 64;
	bad_guys_2(e);
	egg()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/egg.xpm", &egg()->w, &egg()->h);
	floors()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/floor.xpm", &floors()->w, &floors()->h);
	wall()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/parede.xpm", &wall()->w, &wall()->h);
	player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/guy.xpm", &player()->w, &player()->h);
	chest()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/Chest.xpm", &chest()->w, &chest()->h);
	make_addr();
}

int map_letters(void)
{
	int i;
	int j;

	i = 0;
	while(map()->map[i])
	{
		j = 0;
		while(map()->map[i][j])
		{
			if (map()->map[i][j] != '1' && map()->map[i][j] != '0' && map()->map[i][j] != 'E' && map()->map[i][j] != 'T' && map()->map[i][j] != 'P' && map()->map[i][j] != 'C' && map()->map[i][j] != '\n')
				return (ft_printf("Error map not allowed!\n"));
			j++;
		}
		i++;
	}
	return (0);
}
