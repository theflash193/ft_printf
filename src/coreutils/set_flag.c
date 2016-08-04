/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 12:13:01 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 07:25:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	set_conversion3(char option, t_env *e)
{
	if (option == 'x')
		e->x = 1;
	if (option == 'X')
		e->x_upper = 1;
	if (option == 'c')
		e->c = 1;
	if (option == 'C')
	{
		e->c = 1;
		ini_lenght_modifier(e);
		set_lenght_modifier("l", e);
	}
	if (option == '%')
		e->modulo = 1;
}

static void	set_conversion2(char option, t_env *e)
{
	if (option == 'D')
	{
		ini_lenght_modifier(e);
		set_lenght_modifier("l", e);
		e->d = 1;
	}
	if (option == 'o')
		e->o = 1;
	if (option == 'O')
	{
		ini_lenght_modifier(e);
		set_lenght_modifier("l", e);
		e->o = 1;
	}
	if (option == 'u')
		e->u = 1;
	if (option == 'U')
	{
		ini_lenght_modifier(e);
		set_lenght_modifier("l", e);
		e->u = 1;
	}
	set_conversion3(option, e);
}

void	set_conversion(char option, t_env *e)
{
	if (option == 's')
		e->s = 1;
	if (option == 'S')
	{
		ini_lenght_modifier(e);
		e->s = 1;
		set_lenght_modifier("l", e);
	}
	if (option == 'p')
	{
		ini_lenght_modifier(e);
		e->x = 1;
		set_lenght_modifier("l", e);
		set_flags('#', e);
	}
	if (option == 'd' || option == 'i')
		e->d = 1;
	set_conversion2(option, e);
}

void	set_flags(char option, t_env *e)
{
	if (option == '#')
		e->f_alternate_form = 1;
	if (option == '0')
		e->zero_padded = 1;
	if (option == '-')
		e->left_adjusted = 1;
	if (option == ' ')
		e->blank_positiv_number = 1;
	if (option == '+')
		e->sign = 1;
}

void	set_lenght_modifier(char *option, t_env *e)
{
	if (ft_strncmp(option, "hh", 2) == 0)
		e->hh = 1;
	if (ft_strncmp(option, "h", 1) == 0 && ft_strncmp(option, "hh", 2) != 0)
		e->h = 1;
	if (ft_strncmp(option, "l", 1) == 0 && ft_strncmp(option, "ll", 2) != 0)
		e->l = 1;
	if (ft_strncmp(option, "ll", 2) == 0)
		e->ll = 1;
	if (ft_strncmp(option, "j", 1) == 0)
		e->j = 1;
	if (ft_strncmp(option, "z", 1) == 0)
		e->z = 1;
}
