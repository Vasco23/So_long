/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_structs_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:13:31 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:12:28 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

t_obj	*egg(void)
{
	static t_obj	bomb;

	return (&bomb);
}

t_obj	*canva(void)
{
	static t_obj	canva;

	return (&canva);
}

t_obj	*chest(void)
{
	static t_obj	exit;

	return (&exit);
}
