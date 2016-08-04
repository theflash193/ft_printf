/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:25:12 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 11:45:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static wint_t	lenght_modifier(va_list ap, t_env *e)
{
	if (e->l)
		return ((wint_t)va_arg(ap, int));
	else
		return (va_arg(ap, int));
}

char	*conversion_c(va_list ap, t_env *e)
{
	wint_t			c;
	char			*s;

	c = (wint_t)lenght_modifier(ap, e);
	if (e->l)
		s = ft_wtoa(c);
	else
	{
		if (c == 0)
			return (ft_strdup(""));
		s = ft_strnew(1);
		s[0] = (unsigned char)c;
	}
	return (s);
}
