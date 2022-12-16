/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:29:21 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/25 15:44:58 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	makegound(t_mlx *mlx, void *floor, void *wall)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 640)
	{
		while (y < 832)
		{
			if (x == 0 || y == 0 || x >= 576 || y >= 768)
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, wall, x, y);
			else
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, floor, x, y);
			y += 64;
		}
		y = 0;
		x += 64;
	}
	return (0);
}


