/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:28:20 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 18:09:51 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

void		get_stuff(t_bad_guys *e);

int	main(int ac, char **av)
{
	int	i;

	if (map_name(av[1], ".ber", ac) != 0)
		exit(0);
	i = get_maps(av[1]);
	if (i == 1)
	{
		ft_printf("Error\n");
		free_stuff();
	}
	if (i == 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	if (errors_and_map_check(map()->map) > 0)
		free_stuff();
	alloc_bad_guys(array_of_structs());
	get_stuff(*array_of_structs());
	mlx_loop_hook(data()->mlx_ptr, loop, *array_of_structs());
	mlx_hook(data()->win_ptr, 17, 1L << 2, closes, data()->mlx_ptr);
	mlx_hook(data()->win_ptr, 2, 1L << 0, ft_run, data()->mlx_ptr);
	mlx_key_hook(data()->win_ptr, close_window, data()->mlx_ptr);
	mlx_loop(data()->mlx_ptr);
	return (0);
}

void	alloc_bad_guys(t_bad_guys **e)
{
	bad_guys_1();
	*e = malloc(sizeof(t_bad_guys) * (map()->enemies + 1));
	if (!*e)
		free_stuff();
}

void	get_stuff(t_bad_guys *e)
{
	(data())->mlx_ptr = mlx_init();
	(data())->win_ptr = mlx_new_window((data())->mlx_ptr, map()->w * 64 \
		, (map()->h + 1) * 64, "so_long");
	(canva())->img = mlx_new_image((data())->mlx_ptr, map()->w * 64 \
		, (map()->h + 1) * 64);
	(canva())->w = map()->w * 64;
	(canva())->h = (map()->h + 1) * 64;
	bad_guys_2(e);
	(egg())->img = mlx_xpm_file_to_image
		((data())->mlx_ptr, "imgs/egg.xpm", &egg()->w, &egg()->h);
	(floors())->img = mlx_xpm_file_to_image
		((data())->mlx_ptr, "imgs/floor.xpm", &floors()->w, &floors()->h);
	(wall())->img = mlx_xpm_file_to_image
		((data())->mlx_ptr, "imgs/parede.xpm", &wall()->w, &wall()->h);
	(player())->img = mlx_xpm_file_to_image
		((data())->mlx_ptr, "imgs/guy.xpm", &player()->w, &player()->h);
	(chest())->img = mlx_xpm_file_to_image
		((data())->mlx_ptr, "imgs/Chest.xpm", &chest()->w, &chest()->h);
	make_addr();
}

int	map_letters(void)
{
	int	i;
	int	j;

	i = 0;
	while (map()->map[i])
	{
		j = 0;
		while (map()->map[i][j])
		{
			if (map()->map[i][j] != '1' && map()->map[i][j] != '0' && \
				map()->map[i][j] != 'E' && map()->map[i][j] != 'T' && \
					map()->map[i][j] != 'P' && map()->map[i][j] != 'C' && \
						map()->map[i][j] != '\n')
				return (ft_printf("Error map not allowed!\n"));
			j++;
		}
		i++;
	}
	return (0);
}

void	free_stuff_2(t_bad_guys *e)
{
	int	i;

	i = 0;	
	while (map()->temp[i])
	{
		free(map()->temp[i]);
		free(map()->map[i]);
		i++;
	}
	free(map()->temp);
	free(map()->map);
	i = 0;
	while (map()->enemies > 0)
	{
		mlx_destroy_image(data()->mlx_ptr, e[i].img);
		i++;
		map()->enemies -= 1;
	}
	free(e);
}
