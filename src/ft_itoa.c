/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcacador <vcacador@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:12:48 by vcacador          #+#    #+#             */
/*   Updated: 2023/03/24 13:13:44 by vcacador         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && n > i)
	{
		dest[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_itoa3(int n, char *num)
{
	if (n == -2147483648)
	{
		num = malloc(sizeof(char) * 12);
		return (ft_strncpy(num, "-2147483648", 12));
	}
	return ((void *)0);
}

char	*ft_itoa2(int n, char *num, int count, int sinal)
{
	int	v;

	v = count;
	if (n == 0)
	{
		num = malloc(sizeof(char) + 1);
		if (!num)
			return ((void *)0);
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	num = malloc(sizeof(char) * (count + 1));
	if (!num)
		return ((void *)0);
	if (sinal == 1)
		num[0] = '-';
	while (n > 0)
	{
		count--;
		num[count] = 48 + (n % 10);
		n = n / 10;
	}
	num[v] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	int		sinal;
	int		tmp;
	int		count;
	char	*num;

	sinal = 0;
	num = 0;
	tmp = n;
	count = 0;
	if (n == -2147483648)
		return (ft_itoa3(n, num));
	if (n < 0)
	{
		tmp = -tmp;
		sinal = 1;
		n = -n;
		count++;
		num++;
	}
	while (tmp > 9)
	{
		count++;
		tmp = tmp / 10;
	}
	return (ft_itoa2(n, num, count + 1, sinal));
}
