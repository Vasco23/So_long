/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:31:56 by vcacador          #+#    #+#             */
/*   Updated: 2023/02/13 19:29:18 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

static int	read_map(char *file);
static int	line_counter(char *file);
static char	*ft_strcpy(char *str1);


int		get_maps(char *file)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (read_map(file) == 0)
	{
		while (fd > 0)
		{
			map()->map[i] = get_next_line(fd);
			map()->temp[i] = ft_strcpy(map()->map[i]);
			if (!map()->map[i])
				break ;
			i++;
		}
	}
	else
		return (1);
	close(fd);
	return (0);
}

static char	*ft_strcpy(char *str1)
{
	int		i;
	char	*tmp;


	i = 0;
	if (!str1)
		return (NULL);
	tmp = malloc(ft_strlen(str1) + 1);
	if (!tmp)
		return (NULL);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

static int	line_counter(char *file)
{
	int		fd;
	int		counter;
	char	*temp;

	counter = 0;
	fd = open(file, O_RDONLY);
	while (fd != -1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;	
		free(temp);
		counter++;
	}
	close(fd);
	return (counter);
}

static int	read_map(char *file)
{
	int		nbr_lines;

	nbr_lines = line_counter(file);
	if (nbr_lines > 0)
	{	
		map()->map = malloc(sizeof(char *) * (nbr_lines + 1));
		map()->temp = malloc(sizeof(char *) * (nbr_lines + 1));
		if (!map()->map || !map()->temp)
			return (1);
	}
	map()->h = nbr_lines;
	return (0);
}
