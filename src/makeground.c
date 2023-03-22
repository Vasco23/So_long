/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:29:21 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/22 00:00:44 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void makeground_save_lines(void);

int	makeground(t_bad_guys *e)
{
	int i;
	
	i = 0;
	makeground_save_lines();
	while (i < map()->enemies)
	{
		print_img((t_obj *) &(e[i]), e[i].x * 64, e[i].y * 64);
		i++;
	}
	print_img((t_obj*) player(), player()->x * 64, player()->y * 64);
	mlx_put_image_to_window(mlx()->mlx_ptr, mlx()->win_ptr, canva()->img, 0, 0);
	return (0);
}

void makeground_save_lines(void)
{
	int i;
	int j;
	
	i = 0;
	while (map()->map[i])
	{
		j = 0;
		while (map()->map[i][j] != '\0' && map()->map[i][j] != '\n')
		{
			if (map()->map[i][j] == '1')
				print_img(wall(), j * 64, i * 64);
			else 
				print_img(floors(), j * 64, i * 64);
			if (map()->map[i][j] == 'C')
			 	print_img(egg(), j * 64, i * 64);
			if (map()->map[i][j] == 'E')
				print_img(chest(), j * 64, i * 64);
			j++;
		}
		i++;
	}
}
