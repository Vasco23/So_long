/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:28:20 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/30 17:42:28 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	close_window(int keycode, t_mlx *mlx)
{
	if (keycode)
		printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
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
 	if (get_maps("mapaD2.ber") == 1);
		return (0);
	for (int i = 0; game()->t_map.map[i]; i++)
		printf("%s", game()->t_map.map[i]);
	int	*pos = NULL;
	printf("\n Wall Checker: %d\n", wall_checker(game()->t_map.map));
	pos = player_checker(game()->t_map.map, 0);
	printf("\n Player Checker: %d - %d\n", pos[0], pos[1]);
	printf("\n Map Rectangular?: %d\n", map_rectangular(game()->t_map.map));
	printf("\n Collectible?: %d\n", colletibles(game()->t_map.map));
	printf("\n exit valid?: %d\n", exit_ok(game()->t_map.map));
	printf("\n//// COPY MAP /////\n");
	for (int i = 0; game()->t_map.temp[i]; i++)
		printf("%s", game()->t_map.temp[i]);
	/* mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 640, 832, "so_long");
	floor.img = mlx_xpm_file_to_image
		(mlx.mlx_ptr, "imgs/floor.xpm", &floor.x, &floor.y);
	wall.img = mlx_xpm_file_to_image
		(mlx.mlx_ptr, "imgs/parede.xpm", &wall.x, &wall.y);
	makegound(&mlx, floor.img, wall.img);
	mlx_key_hook(mlx.win_ptr, close_window, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mouse_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0); */
}