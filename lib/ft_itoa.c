/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburet <jburet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 10:11:34 by jburet            #+#    #+#             */
/*   Updated: 2014/01/04 14:45:28 by jburet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*int_to_char(int n, int mult, int sign, int limit_case)
{
	int		tmp;
	int		size;
	char	*dst;

	size = 1;
	while (n / mult >= 10 && size++)
		mult *= 10;
	dst = malloc(sizeof(char) * size + sign);
	if (!dst)
		return (NULL);
	size = sign - 1;
	if (sign == 2)
		dst[0] = '-';
	while (mult >= 1)
	{
		tmp = n;
		dst[size] = (tmp / mult) + '0';
		size++;
		n %= mult;
		mult /= 10;
	}
	if (limit_case == 1)
		dst[size - 1] = '8';
	dst[size] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	int			mult;
	int			size;
	int			sign;
	int			limit_case;

	mult = 1;
	size = 1;
	sign = 1;
	limit_case = 0;
	if (n == -2147483648)
	{
		n = n + 1;
		limit_case = 1;
	}
	if (n < 0)
	{
		n *= -1;
		sign = 2;
	}
	return (int_to_char(n, mult, sign, limit_case));
}
