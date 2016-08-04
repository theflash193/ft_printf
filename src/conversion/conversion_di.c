/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 09:37:50 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 07:25:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	lenght_modifier(va_list ap, t_env *e)
{
	if (e->hh)
		return ((signed char)va_arg(ap, signed int));
	else if (e->h)
		return ((signed short)va_arg(ap, signed int));
	else if (e->l)
		return (va_arg(ap, long));
	else if (e->ll)
		return (va_arg(ap, long long));
	else if (e->j)
		return (va_arg(ap, intmax_t));
	else if (e->z)
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, int));
}

char				*conversion_di(va_list ap, t_env *e)
{
	char		*str;
	long long	n;

	n = (long long)lenght_modifier(ap, e);
	str = ft_itoa_long(n);
	return (str);
}
