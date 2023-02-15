/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:00:03 by vcacador          #+#    #+#             */
/*   Updated: 2023/02/13 19:35:09 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void	path_ver_recurive(int x, int y);

int		path_ver(void)
{
	int x;
	int y;

	x = 0;
	printf("pos x = %d\n", player()->x);
	path_ver_recurive(player()->x, player()->y);
	while (map()->temp[x])
	{
		y = 0;
		while (map()->temp[x][y])
		{
			if (map()->temp[x][y] == 'E')
				return (0);
			if (map()->temp[x][y] == 'C')
				return (2);
			y++;
		}
		x++;
	}
	return (1);
}

void	path_ver_recurive(int x, int y)
{
	if (map()->temp[x + 1][y] != '1' && map()->temp[x + 1][y] != 'z')
	{
		map()->temp[x + 1][y] = 'z';
		path_ver_recurive(x + 1, y);
	}
	if (map()->temp[x - 1][y] != '1' && map()->temp[x - 1][y] != 'z')
	{
		map()->temp[x - 1][y] = 'z';
		path_ver_recurive(x - 1, y);
	}
	if (map()->temp[x][y + 1] != '1' && map()->temp[x][y + 1] != 'z')
	{
		map()->temp[x][y + 1] = 'z';
		path_ver_recurive(x, y + 1);
	}
	if (map()->temp[x][y - 1] != '1' && map()->temp[x][y - 1] != 'z')
	{
		map()->temp[x][y - 1] = 'z';
		path_ver_recurive(x, y - 1);
	}
}

int	errors_and_map_check(char **map)
{
	if (wall_checker(map) != 1)
		return (ft_printf("\n Wall Fail!\n"));
	if (player_checker(map) > 1)
		return (ft_printf("\n Only One Player Allowed!\n"));
	if (player_checker(map) < 1)
		return (ft_printf("\n No Player!\n"));
	if (exit_ok(map) < 1)
		return (ft_printf("\n No Exit!\n"));
	if (exit_ok(map) > 1)
		return (ft_printf("\n Too Many Exits!\n"));
	if (colletibles(map) < 1)
		return (ft_printf("\n No collectibles!\n"));
	if (map_rectangular(map) == 0)
		return (ft_printf("\n The Map Its Not Rectangular!\n"));
	if (path_ver() == 0)
		return (ft_printf("\n Theres no way out!\n"));
	if (path_ver() == 2)
		return (ft_printf("\n Can't get all the collectibles!\n"));
	return (0);
}