#include <structs.h>

void make_bad_guys_walk(t_bad_guys *e, int j)
{
	int i;
	static int u;

	i = 0;
	while (i < map()->enemies)
	{
		if (u < 15)
			bad_guys_sprites(e, i, 1);
		else if (u >= 15)
			bad_guys_sprites(e, i, 2);
		if (u > 30)
			u = 0;
		if (i == 0)
			u++;
		if (map()->map[(int)(e[i].y + 1)][(int)e[i].x] != '1' && j < 500 && i % 2 != 0)
			e[i].y = e[i].y + 0.005;
		else if (map()->map[(int)e[i].y][(int)(e[i].x + 1)] != '1' && j < 500 && i % 2 == 0)
			e[i].x += 0.005;
		else if (map()->map[(int)(e[i].y - 1)][(int)e[i].x] != '1' && j < 1000 && i % 2 != 0)
			e[i].y -= 0.005;
		else if (map()->map[(int)e[i].y][(int)(e[i].x - 1)] != '1' && j < 1000 && i % 2 == 0)
			e[i].x -= 0.005;
		i++;
	}
}
