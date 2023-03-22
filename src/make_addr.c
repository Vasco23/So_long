#include <structs.h>

void make_addr(void)
{
	canva()->addr =mlx_get_data_addr(canva()->img, &canva()->bits_per_pixel, \
	&canva()->line_length, &canva()->endian);
	egg()->addr = mlx_get_data_addr(egg()->img, &egg()->bits_per_pixel, \
	&egg()->line_length, &egg()->endian);
	floors()->addr = mlx_get_data_addr(floors()->img, &floors()->bits_per_pixel, \
	&floors()->line_length, &floors()->endian);
	wall()->addr = mlx_get_data_addr(wall()->img, &wall()->bits_per_pixel, \
	&wall()->line_length, &wall()->endian);
	player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
	&player()->line_length, &player()->endian);
	chest()->addr = mlx_get_data_addr(chest()->img, &chest()->bits_per_pixel, \
	&chest()->line_length, &chest()->endian);
}

void sprites_guy(int n)
{
	mlx_destroy_image(mlx()->mlx_ptr, player()->img);
	if (n == 1)
	{
		player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/guy.xpm", &player()->w, &player()->h);
		player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
		&player()->line_length, &player()->endian);
	}
	if (n == 2)
	{
		player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/guy_walk2.xpm", &player()->w, &player()->h);
		player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
		&player()->line_length, &player()->endian);
	}
}

void sprites_guy_inv(int n)
{
	mlx_destroy_image(mlx()->mlx_ptr, player()->img);
	if (n == 1)
	{
		player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/guy_inv.xpm", &player()->w, &player()->h);
		player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
		&player()->line_length, &player()->endian);
	}
	if (n == 2)
	{
		player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/guy_walk2_inv.xpm", &player()->w, &player()->h);
		player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
		&player()->line_length, &player()->endian);
	}
}

void sprites_guy_dead(void)
{
		mlx_destroy_image(mlx()->mlx_ptr, player()->img);
		player()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/ghost.xpm", &player()->w, &player()->h);
		player()->addr = mlx_get_data_addr(player()->img, &player()->bits_per_pixel, \
		&player()->line_length, &player()->endian);
		player()->died += 1;
}