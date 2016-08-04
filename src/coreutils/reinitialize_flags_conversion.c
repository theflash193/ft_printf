/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinitialize_flags_conversion.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:07:57 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 04:48:50 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ini_conversion(t_env *e)
{
	e->s = 0;
	e->p = 0;
	e->d = 0;
	e->o = 0;
	e->u = 0;
	e->x = 0;
	e->x_upper = 0;
	e->c = 0;
	e->modulo = 0;
}

void	ini_lenght_modifier(t_env *e)
{
	e->hh = 0;
	e->h = 0;
	e->l = 0;
	e->ll = 0;
	e->j = 0;
	e->z = 0;
}

static void	ini_flag(t_env *e)
{
	e->f_alternate_form = 0;
	e->zero_padded = 0;
	e->left_adjusted = 0;
	e->blank_positiv_number = 0;
	e->sign = 0;
}

void	reinitialize_flags_conversion(t_env *e)
{
	ini_conversion(e);
	ini_flag(e);
	ft_bzero(&(e->f_precision), sizeof(int));
	ft_bzero(&(e->get_minimum_field), sizeof(int));
	ft_bzero(&(e->get_precision), sizeof(int));
	ft_bzero(&(e->minimum_field), sizeof(int));
	ft_bzero(&(e->precision), sizeof(int));
	ini_lenght_modifier(e);
}
