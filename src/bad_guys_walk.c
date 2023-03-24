/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_guys_walk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:02:17 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 16:48:55 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

void	make_bad_guys_walk_save_lines(t_bad_guys *e, int j, int i);

void	make_bad_guys_walk(t_bad_guys *e, int j)
{
	int			i;
	static int	u;

	i = 0;
	while (i < map()->enemies)
	{
		if (u < 30)
			bad_guys_sprites(e, i, 1);
		else if (u >= 30)
			bad_guys_sprites(e, i, 2);
		if (u > 60)
			u = 0;
		if (i == 0)
			u++;
		make_bad_guys_walk_save_lines(e, j, i);
		i++;
	}
}

void	make_bad_guys_walk_save_lines(t_bad_guys *e, int j, int i)
{
	if (map()->map[(int)(e[i].y + 1)][(int)e[i].x] != '1' \
		&& j < 500 && i % 2 != 0)
			e[i].y = e[i].y + 0.003;
	else if (map()->map[(int)e[i].y][(int)(e[i].x + 1)] != '1' \
		&& j < 500 && i % 2 == 0)
			e[i].x += 0.003;
	else if (map()->map[(int)(e[i].y - 1)][(int)e[i].x] != '1' \
		&& j < 1000 && i % 2 != 0)
			e[i].y -= 0.003;
	else if (map()->map[(int)e[i].y][(int)(e[i].x - 1)] != '1' \
		&& j < 1000 && i % 2 == 0)
			e[i].x -= 0.003;
}
