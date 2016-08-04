/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_formatting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:53:11 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 16:26:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*select_conversion(t_env *e)
{
	if (e->s)
		return (conversion_s(e->ap, e));
	if (e->c)
		return (conversion_c(e->ap, e));
	if (e->modulo)
		return (modulo());
	if (e->o)
		return (conversion_o(e->ap, e));
	if (e->u)
		return (conversion_u(e->ap, e));
	if (e->x || e->x_upper)
		return (conversion_x(e->ap, e));
	if (e->d)
		return (conversion_di(e->ap, e));
	return (NULL);
}

static void	get_argument(t_env *e)
{
	if (e->get_minimum_field)
		e->minimum_field = va_arg(e->ap, int);
	if (e->get_precision)
		e->precision = va_arg(e->ap, int);
}

void	conversion_formatting(t_env *e)
{
	get_argument(e);
	e->fmt = select_conversion(e);
	precision(e);
	flag(e);
	minimum_field(e);
}
