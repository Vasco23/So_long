/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:07:56 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 15:29:15 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

int	collision(double player_y, double player_x, int pos)
{
	if (pos == 1)
		if (map()->map[(int)player_y][(int)(player_x - 0.1)] == '1' \
			|| map()->map[(int)(player_y + 0.9)][(int)(player_x - 0.1)] == '1')
			return (1);
	if (pos == 2)
		if (map()->map[(int)(player_y + 1)][(int)(player_x)] == '1' \
			|| map()->map[(int)(player_y + 1)][(int)(player_x + 0.7)] == '1')
			return (1);
	if (pos == 3)
		if (map()->map[(int)player_y][(int)(player_x + 0.9)] == '1' \
			|| map()->map[(int)(player_y + 0.9)][(int)(player_x + 0.9)] == '1')
			return (1);
	if (pos == 4)
		if (map()->map[(int)(player_y - 0.1)][(int)player_x] == '1' \
			|| map()->map[(int)(player_y - 0.1)][(int)(player_x + 0.7)] == '1')
			return (1);
	return (0);
}

int	collision_collect(double player_y, double player_x)
{
	if (map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.4)] == 'C')
	{
		map()->collect -= 1;
		map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.4)] = '0';
	}
	else if (map()->map[(int)(player_y + 0.7)][(int)(player_x + 0.5)] == 'C')
	{
		map()->collect -= 1;
		map()->map[(int)(player_y + 0.7)][(int)(player_x + 0.5)] = '0';
	}
	else if (map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.5)] == 'C')
	{
		map()->collect -= 1;
		map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.5)] = '0';
	}
	else if (map()->map[(int)(player_y + 0.1)][(int)(player_x + 0.5)] == 'C')
	{
		map()->collect -= 1;
		map()->map[(int)(player_y + 0.1)][(int)(player_x + 0.5)] = '0';
	}
	return (0);
}

int	collision_exit(double player_y, double player_x)
{
	if (map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.4)] == 'E'
		&& map()->collect == 0)
		free_stuff();
	if (map()->map[(int)(player_y + 0.7)][(int)(player_x + 0.5)] == 'E'
		&& map()->collect == 0)
		free_stuff();
	if (map()->map[(int)(player_y + 0.5)][(int)(player_x + 0.5)] == 'E'
		&& map()->collect == 0)
		free_stuff();
	if (map()->map[(int)(player_y + 0.1)][(int)(player_x + 0.5)] == 'E'
		&& map()->collect == 0)
		free_stuff();
	return (0);
}

int	collision_enemies(double player_y, double player_x, t_bad_guys *e)
{
	int	i;

	i = 0;
	if (player()->died >= 1)
		player()->died += 1;
	if (player()->died > 100)
		free_stuff();
	while (i < map()->enemies)
	{
		if (player_y + 0.1 >= e[i].y && player_y + 0.1 <= e[i].y + 0.7
			&& player_x + 0.1 >= e[i].x && player_x + 0.1 <= e[i].x + 0.7)
			sprites_guy_dead(player());
		if (player_y + 0.7 >= e[i].y && player_y + 0.7 <= e[i].y + 0.7
			&& player_x + 0.1 >= e[i].x && player_x + 0.1 <= e[i].x + 0.7)
			sprites_guy_dead(player());
		if (player_y + 0.1 >= e[i].y && player_y + 0.1 <= e[i].y + 0.7
			&& player_x + 0.7 >= e[i].x && player_x + 0.7 <= e[i].x + 0.7)
			sprites_guy_dead(player());
		if (player_y + 0.7 >= e[i].y && player_y + 0.7 <= e[i].y + 0.7
			&& player_x + 0.7 >= e[i].x && player_x + 0.7 <= e[i].x + 0.7)
			sprites_guy_dead(player());
		i++;
	}
	return (0);
}
