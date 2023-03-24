/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:41:15 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 17:53:52 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

int	close_window(int keycode)
{
	if (keycode == 65307)
		free_stuff();
	if (keycode == 32 && player()->walk == 9)
		sprites_guy(4, player());
	return (0);
}

int	closes(void)
{
	free_stuff();
	return (0);
}

void	chest_open(t_obj *tmp)
{
	if (map()->collect == 0)
	{
		mlx_destroy_image(data()->mlx_ptr, chest()->img);
		tmp->img = mlx_xpm_file_to_image
			(data()->mlx_ptr, "imgs/Chest_2.xpm", &chest()->w, &chest()->h);
		tmp->addr = mlx_get_data_addr(chest()->img, &chest()->bpp, \
			&chest()->line_length, &chest()->endian);
	}
}

int	loop(void *param)
{
	static int	i;
	char		*count;

	count = ft_itoa(map()->steps);
	makeground(param);
	make_bad_guys_walk(param, i++);
	if (i == 1000)
		i = 0;
	mlx_string_put(data()->mlx_ptr, data()->win_ptr, 10,
		10, (unsigned int)*"#000000", count);
	free(count);
	chest_open(chest());
	collision_enemies(player()->y, player()->x, param);
	return (0);
}

int	free_stuff(void)
{
	free_stuff_2(*array_of_structs());
	if (egg()->img)
		mlx_destroy_image(data()->mlx_ptr, egg()->img);
	if (floors()->img)
		mlx_destroy_image(data()->mlx_ptr, floors()->img);
	if (wall()->img)
		mlx_destroy_image(data()->mlx_ptr, wall()->img);
	if (player()->img)
		mlx_destroy_image(data()->mlx_ptr, player()->img);
	if (chest()->img)
		mlx_destroy_image(data()->mlx_ptr, chest()->img);
	if (canva()->img)
		mlx_destroy_image(data()->mlx_ptr, canva()->img);
	if (data()->win_ptr)
		mlx_destroy_window(data()->mlx_ptr, data()->win_ptr);
	if (data()->mlx_ptr)
	{
		mlx_destroy_display(data()->mlx_ptr);
		free(data()->mlx_ptr);
	}
	exit(0);
}
