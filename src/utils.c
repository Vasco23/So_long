#include <structs.h>

int	close_window(int keycode)
{
/* 	if (keycode)
		printf("%u\n", keycode); */
	if (keycode == 65307)
		free_stuff();
	if (keycode == 32 && player()->walk == 9)
		sprites_guy(4);
	return (0);
}

int closes(void)
{
	free_stuff();
	return (0);
}

void chest_open(void)
{
	if (map()->collect == 0)
	{
		mlx_destroy_image(mlx()->mlx_ptr, chest()->img);
		chest()->img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/Chest_2.xpm", &chest()->w, &chest()->h);
		chest()->addr = mlx_get_data_addr(chest()->img, &chest()->bits_per_pixel, \
		&chest()->line_length, &chest()->endian);
	}
}

int loop(void *param)
{
	static int i;
	char * count;

	count = ft_itoa(map()->steps);
	/* (void) param; */
	makeground(param);
	make_bad_guys_walk(param, i++);
	if (i == 1000)
		i = 0;
	chest_open();
	collision_enemies(player()->y, player()->x, param);
	mlx_string_put(mlx()->mlx_ptr, mlx()->win_ptr, 10, 10, (unsigned int)*"#000000", count);
	free(count);
	return (0);
}

int free_stuff(void)
{
	int i;

	i = 0;
	while(map()->temp[i])
	{
		free(map()->temp[i]);
		free(map()->map[i]);
		i++;
	}
	free(map()->temp);
	free(map()->map);
	mlx_destroy_image(mlx()->mlx_ptr, egg()->img);
	mlx_destroy_image(mlx()->mlx_ptr, floors()->img);
	mlx_destroy_image(mlx()->mlx_ptr, wall()->img);
	mlx_destroy_image(mlx()->mlx_ptr, player()->img);
	mlx_destroy_image(mlx()->mlx_ptr, chest()->img);
	mlx_destroy_display(mlx()->mlx_ptr);
	mlx_clear_window(mlx()->mlx_ptr, mlx()->mlx_ptr);
	free(mlx()->mlx_ptr);
	exit(0);
}