/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:35:08 by vcacador          #+#    #+#             */
/*   Updated: 2022/11/25 15:45:04 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	wall_checker(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = line_len(map[i]);
	while (i < len - 1)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i + 1])
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][len - 1] != '1')
			return (0);
		i++;
	}
	if (ft_strncmp(map[0], map[i], len - 1))
		return (0);
	return (1);
}

int	*player_checker(char **map, int *pos)
{
	int	i;
	int	j;
	int	player;

	i = 1;
	player = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			if (map[i][j] == 'P')
			{
				player++;
				if (player == 1)
					pos = malloc(sizeof(int) * 2);
				pos[0] = i;
				pos[1] = j;
			}
			j++;
		}
	}
	if (player == 1)
		return (pos);
	return (0);
}

int	exit_ok(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	j = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

int	colletibles(char **map)
{
	int	i;
	int	j;
	int	collet;

	i = -1;
	j = 0;
	collet = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'B' || map[i][j] == 'C')
				collet++;
			j++;
		}
	}
	return (collet);
}

int	map_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (line_len(map[i]) - line_len(map[i + 1]) != 0)
			return (0);
		i++;
	}
	return (1);
}
