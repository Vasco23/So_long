/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:00:03 by vcacador          #+#    #+#             */
/*   Updated: 2022/12/02 13:05:08 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int		path_ver(void)
{
	while (path_ver_recurive(game()->t_player.x, game()->t_player.y, game()->t_map.temp))
	{
		if(game()->t_player.x && game()->t_player.y)
		{
			
		}
	}
}

void	path_ver_recurive(int x, int y, char **map)
{
	if (map[x + 1][y] != '1' && map[x + 1][y] != 'z')
		path_ver_recurive(x += 1, y, map);
	if (map[x - 1][y] != '1' && map[x - 1][y] != 'z')
		path_ver_recurive(x -= 1, y, map);
	if (map[x][y + 1] != '1' && map[x][y + 1] != 'z')
		path_ver_recurive(x, y += 1, map);
	if (map[x][y - 1] != '1' && map[x][y - 1] != 'z')
		path_ver_recurive(x, y -= 1, map);
}

/* int	errors_and_map_check(char **map)
{
	if (wall_checker(map) != 1)
		return (ft_printf("\n Wall Fail!\n"));
	if (player_checker(map, 0))
		return (ft_printf("\n Only One Player Allowed!\n"));
	if (player_checker(map, 0))
		return (ft_printf("\n No Player!\n"));
	if (exit_ok(map) < 1)
		return (ft_printf("\n No Exit!\n"));
	if (exit_ok(map) > 1)
		return (ft_printf("\n Too Many Exits!\n"));
	if (colletibles(map) < 1)
		return (ft_printf("\n No collectibles!\n"));
	if (map_rectangular(map) == 0)
		return (ft_printf("\n The Map Its Not Rectangular!\n"));
	return (0);
}
 */