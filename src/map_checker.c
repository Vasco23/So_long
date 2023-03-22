/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:35:08 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/22 12:29:28 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

int	wall_checker(char **map)
{
	int	i;
	int	len;

	i = 0;
	if (map)
		len = line_len(map[i]);
	while (i < len - 1)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map && map[i + 1])
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

int	player_checker(char **map)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (map[i++])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p++;
				if (p == 1)
				{
					player()->x = j;
					player()->y = i;
				}
			}
			j++;
		}
	}
	if (p == 1)
		return (1);
	return (p);
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

int	colletibles(char **maps)
{
	int	i;
	int	j;
	int	collet;

	i = -1;
	j = 0;
	collet = 0;
	while (maps[++i])
	{
		j = 0;
		while (maps[i][j])
		{
			if (maps[i][j] == 'C')
				collet++;
			j++;
		}
	}
	map()->collect = collet;
	return (collet);
}

int	map_rectangular(char **maps)
{
	int	i;

	i = 0;
	map()->w = line_len(maps[i]);
	while (maps[i])
		i++;
	if (i < 3)
		return (0);
	i = 0;
	while (maps[i + 1])
	{
		if (line_len(maps[i]) - line_len(maps[i + 1]) != 0)
			return (0);
		i++;
	}
	map()->h = i;
	return (1);
}
