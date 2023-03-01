/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:29:21 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/01 14:04:18 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	makegound(void)
{
	int i;
	int j;
	/* int x = 0;
	int y = 0; */
	i = 0;
	while (map()->map[i])
	{
		j = 0;
		while (map()->map[i][j] != '\0')
		{
			if (map()->map[i][j] == '1')
				mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, wall()->img, j * 64, i * 64);
			else if (map()->map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, floors()->img, j * 64, i * 64);
				mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, bomb()->img, j * 64, i * 64);
			}
			else if (map()->map[i][j] == 'G')
			{
				
			}
			else
				mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, floors()->img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}
