/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 17:06:18 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 00:22:38 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static wchar_t	*lenght_modifier(va_list ap, t_env *e)
{
	if (e->l)
		return (va_arg(ap, wchar_t *));
	else
		return ((wchar_t *)va_arg(ap, const char *));
}

char			*conversion_s(va_list ap, t_env *e)
{
	wchar_t	*tmp;
	char	*s;

	tmp = lenght_modifier(ap, e);
	if (tmp == NULL)
		s = ft_strdup("(null)");
	else if (e->l)
		s = (e->precision > 0) ? ft_wtons(tmp, e->precision) : ft_wtos(tmp);
	else
		s = (char *)ft_strdup((char *)tmp);
	return (s);
}
