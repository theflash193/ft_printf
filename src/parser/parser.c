/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:13:34 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 11:36:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	flags(char *format, int *i, t_env *e)
{
	while (format[*i] != '\0' && is_flag(format[*i]))
	{
		set_flags(format[*i], e);
		*i = *i + 1;
	}
}

static void	minimum_field_width(char *format, int *i, t_env *e)
{
	if (ft_isdigit(format[*i]))
	{
		e->minimum_field = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]) || format[*i] == '+' || format[*i] == '-')
			*i = *i + 1;
	}
	if (format[*i] == '*')
	{
		e->get_minimum_field = 1;
		*i = *i + 1;
	}
}

static void	parser_precision(char *format, int *i, t_env *e)
{
	if (format[*i] == '.')
	{
		*i = *i + 1;
		e->f_precision = 1;
		if (ft_isdigit(format[*i]))
		{
			e->precision = ft_atoi(format + *i);
			while (ft_isdigit(format[*i]) || format[*i] == '+' ||
				format[*i] == '-')
				*i = *i + 1;
		}
		if (format[*i] == '*')
		{
			e->get_precision = 1;
			*i = *i + 1;
		}
	}
}

static void	lenght_modifier(char *format, int *i, t_env *e)
{
	if (is_length_modifier(format + *i))
	{
		set_lenght_modifier(format + *i, e);
		while (is_length_modifier(format + *i))
			*i = *i + 1;
	}
	while (is_length_modifier(format + *i))
	{
		ini_lenght_modifier(e);
		set_lenght_modifier(format + *i, e);
		*i = (ft_strnequ("ll", format + *i, 2) ||
			ft_strnequ("hh", format + *i, 2)) ? 2 : 1;
	}
}

int			parser(char *format, t_env *e)
{
	int i;

	i = 1;
	flags(format, &i, e);
	minimum_field_width(format, &i, e);
	parser_precision(format, &i, e);
	lenght_modifier(format, &i, e);
	if (format[i] != '\0' && is_conversion(format[i]))
		set_conversion(format[i++], e);
	return (i);
}
