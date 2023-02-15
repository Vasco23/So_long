/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:28:20 by vcacador          #+#    #+#             */
/*   Updated: 2023/02/15 00:34:16 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	close_window(int keycode)
{
	if (keycode)
		printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx()->mlx_ptr, mlx()->win_ptr);
		exit(0);
	}
	return (0);
}

int closes(void)
{
	mlx_destroy_window(mlx()->mlx_ptr, mlx()->win_ptr);
	exit(0);
	return (0);
}

int	mouse_hook(int keycode)
{
	if (keycode)
		printf("%d\n", keycode);
	return (0);
}

t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int main ()
{
 	if (get_maps("maptest.ber") == 1)
		return (0);
	for (int i = 0; map()->map[i]; i++)
		printf("%s", map()->map[i]);
	if (errors_and_map_check(map()->map) > 0)
		return(0);
	/* printf("\n Wall Checker: %d\n", wall_checker(map()->map));
	printf("\n Player Checker: %d - %d\n", player()->x, player()->y);
	printf("\n Map Rectangular?: %d\n", map_rectangular(map()->map));
	printf("\n Collectible?: %d\n", colletibles(map()->map));
	printf("\n exit valid?: %d\n", exit_ok(map()->map));
	printf("\n//// COPY MAP /////\n"); */
	for (int i = 0; map()->temp[i]; i++)
		printf("%s", map()->temp[i]);
	printf("->>>%d\n", map()->w);
	mlx()->mlx_ptr = mlx_init();
	mlx()->win_ptr = mlx_new_window(mlx()->mlx_ptr, (map()->w) * 64, (map()->h + 1) * 64, "so_long");
	bomb()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/bomb.xpm", &bomb()->x, &bomb()->y);
	floors()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/floor.xpm", &floors()->x, &floors()->y);
	wall()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/parede.xpm", &wall()->x, &wall()->y);
	makegound();
	mlx_hook(mlx()->win_ptr, 17, 1L<<2, closes, mlx()->mlx_ptr);
	mlx_key_hook(mlx()->win_ptr, close_window, mlx()->mlx_ptr);
	mlx_mouse_hook(mlx()->win_ptr, mouse_hook, mlx()->mlx_ptr);
	mlx_loop(mlx()->mlx_ptr);
	return (0);
}