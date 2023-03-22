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

t_player *player(void)
{
	static t_player	player;

	return (&player);
}
