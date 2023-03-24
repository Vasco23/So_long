/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:15:25 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:12:46 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

void	ft_run_sprites(void);
void	ft_run_sprites_inv(void);
void	ft_run_collision(int keycode);
void	ft_run_save_lines(int keycode);

int	ft_run(int keycode)
{
	ft_run_collision(keycode);
	ft_run_save_lines(keycode);
	if (keycode == 100 && !collision(player()->y, player()->x, 3)
		&& player()->died == 0)
	{
		ft_run_sprites();
		player()->x += 0.05;
		map()->steps += 1;
		printf("steps-> %d\n", map()->steps);
	}
	if (keycode == 119 && !collision(player()->y, player()->x, 4)
		&& player()->died == 0)
	{
		ft_run_sprites();
		player()->y -= 0.05;
		map()->steps += 1;
		printf("steps-> %d\n", map()->steps);
	}
	return (0);
}

void	ft_run_sprites(void)
{
	if (player()->walk < 4)
	{
		sprites_guy(1, player());
		player()->walk += 1;
	}
	else if (player()->walk >= 4 && player()->walk < 9)
	{
		sprites_guy(2, player());
		player()->walk += 1;
		if (player()->walk == 8)
			player()->walk = 0;
	}
	return ;
}

void	ft_run_sprites_inv(void)
{
	if (player()->walk < 4)
	{
		sprites_guy_inv(1, player());
		player()->walk += 1;
	}
	else if (player()->walk >= 4 && player()->walk < 9)
	{
		sprites_guy_inv(2, player());
		player()->walk += 1;
		if (player()->walk == 8)
			player()->walk = 0;
	}
	return ;
}

void	ft_run_collision(int keycode)
{
	if (keycode == 97 || keycode == 115 || keycode == 100 || keycode == 119)
	{
		collision_exit(player()->y, player()->x);
		collision_collect(player()->y, player()->x);
	}
}

void	ft_run_save_lines(int keycode)
{
	if (keycode == 97 && !collision(player()->y, player()->x, 1)
		&& player()->died == 0)
	{
		ft_run_sprites_inv();
		player()->x -= 0.05;
		map()->steps += 1;
		printf("steps-> %d\n", map()->steps);
	}
	if (keycode == 115 && !collision(player()->y, player()->x, 2)
		&& player()->died == 0)
	{
		ft_run_sprites();
		player()->y += 0.05;
		map()->steps += 1;
		printf("steps-> %d\n", map()->steps);
	}
}
