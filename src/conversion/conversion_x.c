/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 19:01:36 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/30 23:09:39 by grass-kw         ###   ########.fr       */
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

char				*conversion_x(va_list ap, t_env *e)
{
	char				*str;
	unsigned long long	n;

	n = (unsigned long long)lenght_modifier(ap, e);
	str = ft_itoa_base(n, 16);
	if (e->x_upper)
		ft_capitalize(str);
	return (str);
}
