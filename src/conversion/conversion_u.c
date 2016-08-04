/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:54:58 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/30 23:09:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static long long	lenght_modifier(va_list ap, t_env *e)
{
	if (e->hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (e->h)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (e->l)
		return (va_arg(ap, unsigned long));
	else if (e->ll)
		return (va_arg(ap, unsigned long long));
	else if (e->j)
		return (va_arg(ap, intmax_t));
	else if (e->z)
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, unsigned int));
}

char				*conversion_u(va_list ap, t_env *e)
{
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)lenght_modifier(ap, e);
	str = ft_itoa_base(n, 10);
	return (str);
}
