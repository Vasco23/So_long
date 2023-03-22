#include <structs.h>

t_obj *egg(void)
{
	static t_obj	bomb;
	
	return (&bomb);
}

t_obj *canva(void)
{
	static t_obj	canva;
	
	return (&canva);
}

t_obj *chest(void)
{
	static t_obj	exit;
	
	return (&exit);
}