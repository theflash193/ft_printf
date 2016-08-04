/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alternate_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:16:28 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:17:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	case_o(t_env *e)
{
	char	*str;

	if (ft_strequ("0", e->fmt) != 1 && ft_strnequ("0", e->fmt, 1) != 1)
	{
		str = ft_strjoin("0", e->fmt);
		ft_strclean2(&(e->fmt));
		e->fmt = str;
	}
}

void	case_xlower(t_env *e)
{
	char	*str;

	if (ft_strequ("0", e->fmt) != 1 && !e->zero_padded && !(e->precision == 0
		&& e->f_precision))
	{
		str = ft_strjoin("0x", e->fmt);
		ft_strclean2(&(e->fmt));
		e->fmt = str;
	}
}

void	case_xupper(t_env *e)
{
	char	*str;

	if (ft_strequ("0", e->fmt) != 1 && !e->zero_padded && !(e->precision == 0 && e->f_precision))
	{
		str = ft_strjoin("0X", e->fmt);
		ft_strclean2(&(e->fmt));
		e->fmt = str;
	}
}

void	alternate_form(t_env *e)
{

	if (e->o)
		case_o(e);
	if (e->x)
		case_xlower(e);
	if (e->x_upper)
		case_xupper(e);
}
