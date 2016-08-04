/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:21:58 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 04:44:58 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_len(long long n)
{
	long long		res;

	res = 1;
	while (n < -9 || n > 9)
	{
		res++;
		n = n / 10;
	}
	if (n >= 0)
		return (res);
	else
		return (res + 1);
}

char		*ft_itoa_long(long long n)
{
	char			*res;
	long long		i;
	long long		nvalue;

	nvalue = n;
	if (n == 0)
	{
		res = ft_strdup("0");
		return (res);
	}
	i = ft_len(n);
	res = (char *)ft_memalloc(sizeof(char) * i + 1);
	while (i--)
	{
		if (n < 0)
			res[i] = (((n % 10) * -1) + 48);
		else
			res[i] = ((n % 10) + 48);
		n = n / 10;
	}
	if (nvalue < 0)
		res[0] = '-';
	return (res);
}
