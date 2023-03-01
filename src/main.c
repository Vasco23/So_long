/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:28:20 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/01 17:16:13 by vcacador         ###   ########.fr       */
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

void	get_img_pixel(t_bomb *data, int x, int y)
{
	char	*dst;
	unsigned int	color;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put(t_bomb *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
my_mlx_pixel_put
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
	mlx()->canva.img = mlx_new_image(mlx()->mlx_ptr, (map()->w) * 64, (map()->h + 1) * 64);
	mlx()->canva.addr = mlx_get_data_addr(mlx()->canva.img, &mlx()->canva.bits_per_pixel, \
	&mlx()->canva.line_length, &mlx()->canva.endian);
	print_img(1, 500, 0x2596be);
	/* my_mlx_pixel_put(&mlx()->canva, 100, 100, 0x2596be); */
	/* glock()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/glock.xpm", &glock()->x, &glock()->y);
	bomb()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/bomb.xpm", &bomb()->x, &bomb()->y);
	floors()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/floor.xpm", &floors()->x, &floors()->y);
	wall()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/parede.xpm", &wall()->x, &wall()->y);
	makegound();
	converter(); */
	mlx_hook(mlx()->win_ptr, 17, 1L<<2, closes, mlx()->mlx_ptr);
	mlx_key_hook(mlx()->win_ptr, close_window, mlx()->mlx_ptr);
	mlx_mouse_hook(mlx()->win_ptr, mouse_hook, mlx()->mlx_ptr);
	mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, mlx()->canva.img, 0, 0);
	mlx_loop(mlx()->mlx_ptr);
	return (0);
}

/* void	converter(int x, int y, int color)
{
	char	*dst;

	dst = mlx()->canva.addr + (y * mlx()->canva.line_length + x * (mlx()->canva.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
 */
void print_img(int i, int y, int color)
{
	my_mlx_pixel_put(&mlx()->canva, i, y, color);
}

void get_pixel(void)
{
	
}