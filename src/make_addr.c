/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_addr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:12:46 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:23:48 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

void	make_addr(void)
{
	char	*tmp;

	tmp = mlx_get_data_addr(canva()->img, &canva()->bpp,
			&canva()->line_length, &canva()->endian);
	canva()->addr = tmp;
	tmp = mlx_get_data_addr(egg()->img, &egg()->bpp,
			&egg()->line_length, &egg()->endian);
	egg()->addr = tmp;
	tmp = mlx_get_data_addr(floors()->img, &floors()->bpp,
			&floors()->line_length, &floors()->endian);
	floors()->addr = tmp;
	tmp = mlx_get_data_addr(wall()->img, &wall()->bpp,
			&wall()->line_length, &wall()->endian);
	wall()->addr = tmp;
	tmp = mlx_get_data_addr(player()->img, &player()->bpp,
			&player()->line_length, &player()->endian);
	player()->addr = tmp;
	tmp = mlx_get_data_addr(chest()->img, &chest()->bpp,
			&chest()->line_length, &chest()->endian);
	chest()->addr = tmp;
}

void	sprites_guy(int n, t_player *tmp)
{
	mlx_destroy_image(data()->mlx_ptr, player()->img);
	if (n == 1)
	{
		tmp->img = mlx_xpm_file_to_image(data()->mlx_ptr, "imgs/guy.xpm",
				&player()->w, &player()->h);
		tmp->addr = mlx_get_data_addr(player()->img, &player()->bpp,
				&player()->line_length, &player()->endian);
	}
	if (n == 2)
	{
		tmp->img = mlx_xpm_file_to_image(data()->mlx_ptr, "imgs/guy_walk2.xpm",
				&player()->w, &player()->h);
		tmp->addr = mlx_get_data_addr(player()->img, &player()->bpp,
				&player()->line_length, &player()->endian);
	}
}

void	sprites_guy_inv(int n, t_player *tmp)
{
	mlx_destroy_image(data()->mlx_ptr, player()->img);
	if (n == 1)
	{
		tmp->img = mlx_xpm_file_to_image(data()->mlx_ptr, "imgs/guy_inv.xpm",
				&player()->w, &player()->h);
		tmp->addr = mlx_get_data_addr(player()->img, &player()->bpp,
				&player()->line_length, &player()->endian);
	}
	if (n == 2)
	{
		tmp->img = mlx_xpm_file_to_image(data()->mlx_ptr,
				"imgs/guy_walk2_inv.xpm", &player()->w, &player()->h);
		tmp->addr = mlx_get_data_addr(player()->img, &player()->bpp,
				&player()->line_length, &player()->endian);
	}
}

void	sprites_guy_dead(t_player *tmp)
{
	mlx_destroy_image(data()->mlx_ptr, player()->img);
	tmp->img = mlx_xpm_file_to_image(data()->mlx_ptr, "imgs/ghost.xpm",
			&player()->w, &player()->h);
	tmp->addr = mlx_get_data_addr(player()->img, &player()->bpp,
			&player()->line_length, &player()->endian);
	player()->died += 1;
}
