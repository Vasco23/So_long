#include "../includes/structs.h"


t_mlx *mlx(void)
{
	static t_mlx	mlx;

	return (&mlx);
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

t_floors *floors(void)
{
	static t_floors	floor;

	return (&floor);
}

t_wall *wall(void)
{
	static t_wall	wall;

	return (&wall);
}

t_player *player(void)
{
	static t_player	player;

	return (&player);
}

t_bomb *bomb(void)
{
	static t_bomb	bomb;
	
	return (&bomb);
}