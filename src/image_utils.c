/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:13:58 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:14:33 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void	print_img(t_obj *img, int x1, int y1)
{
	int		x;
	int		y;
	double	x2;
	double	y2;

	y = 0;
	y2 = 0;
	while (y < img->h)
	{
		x = 0;
		x2 = 0;
		while (x < img->w)
		{
			my_mlx_pixel_put(canva(), (x + x1), (y + y1),
				get_img_pixel(img, x2, y2));
			x++;
			x2 += ((double)img->w / (double) 64);
		}
		y++;
		y2 += ((double) img->h / (double) 64);
	}
}

unsigned int	get_img_pixel(t_obj *img, int x, int y)
{
	char	*dst;

	dst = (img->addr + (y * img->line_length + x * (img->bpp / 8)));
	return (*(unsigned int *) dst);
}

void	my_mlx_pixel_put(t_obj *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (color == 65793 || color == 16185078)
		return ;
	dst = (img->addr + (y * img->line_length + x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}
