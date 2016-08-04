/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:15:59 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:11:31 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	base_number(int unit)
{
	char	number[16];

	ft_memcpy(number, "0123456789abcdef", 16);
	return (number[unit]);
}

static char	*cat_number(int r, char *src)
{
	char	*dest;
	char	*tmp;
	char	*number;

	number = ft_strnew(1);
	number[0] = base_number(r);
	tmp = ft_strjoin(number, src);
	ft_strclean2(&src);
	ft_strclean2(&number);
	dest = tmp;
	return (dest);
}

char	*ft_itoa_base(unsigned long long n, int base)
{
	char				*str;
	unsigned long long	i;
	unsigned long long	q;
	unsigned long long	r;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	str = ft_strnew(1);
	q = n;
	i = 0;
	while (q > 0)
	{
		r = q % base;
		str = cat_number(r, str);
		q = q / base;
		i++;
	}
	return (str);
}
