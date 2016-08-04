/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:40:15 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 16:30:28 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	stock_conversion(char **format, unsigned int diff, t_env *e)
{
	char			*join;

	if (diff != 0)
	{
		join = ft_strndup(*format, diff);
		e->formated_string = ft_joinclr(e->formated_string, join, 2);
		*format += diff;
	}
	*format += parser((char *)*format, e);
	if (e->c || e->s || e->p || e->d || e->o || e->u || e->x ||
			e->x_upper || e->modulo)
	{
		conversion_formatting(e);
		e->s1 = ft_strdup(e->formated_string);
		ft_strclean2(&(e->formated_string));
		e->formated_string = ft_joinclr(e->s1, e->fmt, 2);
	}
	reinitialize_flags_conversion(e);
}

static void	stock_last_charactere(char **format, t_env *e)
{
	char	*s;

	s = ft_strdup(e->formated_string);
	ft_strclean2(&(e->formated_string));
	e->formated_string = ft_joinclr(s, *format, 1);
}

static int	print(t_env *e)
{
	int		len;

	ft_putstr(e->formated_string);
	len = ft_strlen(e->formated_string);
	ft_strclean2(&(e->formated_string));
	return (len);
}

int			ft_printf(const char *format, ...)
{
	t_env			e;
	char			*conversion_found;
	unsigned int	diff;

	ft_bzero(&e, sizeof(t_env));
	e.formated_string = ft_strdup("");
	if (format == NULL)
		return (-1);
	va_start(e.ap, format);
	while (*format != '\0')
	{
		if ((conversion_found = ft_strchr(format, '%')) != NULL)
		{
			diff = (unsigned int)(conversion_found - format);
			stock_conversion((char **)&format, diff, &e);
		}
		else
		{
			stock_last_charactere((char **)&format, &e);
			break ;
		}
	}
	va_end(e.ap);
	return (print(&e));
}
