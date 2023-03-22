#include <structs.h>

void bad_guys_1(void)
{
	int i;
	int j;
	int bad_guys;

	i = 0;
	bad_guys = 0;
	while (map()->map[i])
	{
		j = 0;
		while (map()->map[i][j])
		{
			if (map()->map[i][j] == 'T')
				bad_guys++;
			j++;
		}
		i++;
	}
	map()->enemies = bad_guys;
}

t_bad_guys *array_of_structs(void)
{
	static t_bad_guys *e;

	bad_guys_1();
	e = malloc(sizeof(t_bad_guys) * map()->enemies);
	return(e);
}

void make_bad_guys(t_bad_guys *e, int times, double y, double x)
{
	e[times].img = mlx_xpm_file_to_image
		(mlx()->mlx_ptr, "imgs/bad_guy.xpm", &e[times].w, &e[times].h);
	e[times].addr = mlx_get_data_addr(e[times].img, &e[times].bits_per_pixel, \
		&e[times].line_length, &e[times].endian);
	e[times].x = x;
	e[times].y = y;
}

void bad_guys_2(t_bad_guys *e)
{
	int i;
	int j;
	int times;

	times = 0;
	i = 0;
	while (map()->map[i])
	{
		j = 0;
		while (map()->map[i][j])
		{
			if (map()->map[i][j] == 'T')
			{
				make_bad_guys(e, times, i, j);
				times++;
			}
			j++;
		}
		i++;
	}
}

void bad_guys_sprites(t_bad_guys *e, int i, int sprite)
{
	if (sprite == 1)
	{
		mlx_destroy_image(mlx()->mlx_ptr, e[i].img);
		e[i].img = mlx_xpm_file_to_image
			(mlx()->mlx_ptr, "imgs/bad_guy.xpm", &e[i].w, &e[i].h);
		e[i].addr = mlx_get_data_addr(e[i].img, &e[i].bits_per_pixel, \
			&e[i].line_length, &e[i].endian);
	}
	if (sprite == 2)
	{
		mlx_destroy_image(mlx()->mlx_ptr, e[i].img);
		e[i].img = mlx_xpm_file_to_image
			(mlx()->mlx_ptr, "imgs/bad_guy_2.xpm", &e[i].w, &e[i].h);
		e[i].addr = mlx_get_data_addr(e[i].img, &e[i].bits_per_pixel, \
			&e[i].line_length, &e[i].endian);
	}
}
