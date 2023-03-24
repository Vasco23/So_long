/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:13:43 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:42:31 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_window	*data(void)
{
	static t_window	mlx;

	return (&mlx);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_obj	*floors(void)
{
	static t_obj	floor;

	return (&floor);
}

t_obj	*wall(void)
{
	static t_obj	wall;

	return (&wall);
}

t_player	*player(void)
{
	static t_player	player;

	return (&player);
}
