/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:12:55 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:12:46 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*precision_padding(size_t len, char *src, char *prefix)
{
	char	*s;
	size_t	src_len;
	int		start;
	int		prefix_len;

	src_len = ft_strlen(src);
	if (prefix != NULL)
	{
		prefix_len = ft_strlen(prefix);
		start = (len + prefix_len) - src_len;
		s = ft_strnew(len + prefix_len);
		ft_memset(s, '0', len + prefix_len);
		ft_memcpy(s, prefix, prefix_len);
		ft_memcpy(s + start, src, src_len);
	}
	else
	{
		start = len - src_len;
		s = ft_strnew(len);
		ft_memset(s, '0', len);
		ft_memcpy(s + start, src, src_len);
	}
	return (s);
}

static void	minimum_number_digit(t_env *e)
{
	char	*s;
	size_t	i;

	i = (ft_strnequ("-", e->fmt, 1)) ? ft_strlen(e->fmt + 1) :
		ft_strlen(e->fmt);
	if (e->precision > (int)i)
	{
		if (ft_strnequ("-", e->fmt, 1))
		{
			s = precision_padding(e->precision, (e->fmt + 1), "-");
			ft_strclean2(&(e->fmt));
			e->fmt = s;
		}
		else
		{
			s = precision_padding(e->precision, e->fmt, NULL);
			ft_strclean2(&(e->fmt));
			e->fmt = s;
		}
	}
	if (e->precision == 0 && e->f_precision && ft_strequ("0", e->fmt))
	{
		ft_strclean2(&(e->fmt));
		e->fmt = ft_strdup("");
	}
}

static void	maximum_characters_printed(t_env *e)
{
	char	*s;
	int		precision;

	if (e->precision < (int)ft_strlen(e->fmt) && e->precision > 0)
	{
		s = ft_strndup(e->fmt, e->precision);
		ft_strclean2(&(e->fmt));
		e->fmt = s;
	}
	if (e->precision < 0)
	{
		precision = e->precision * -1;
		s = ft_strnew(precision);
		ft_memset(s, ' ', precision);
		ft_strclean2(&(e->fmt));
		e->fmt = s;
	}
}

void		precision(t_env *e)
{
	if (e->d || e->o || e->u || e->x || e->x_upper)
		minimum_number_digit(e);
	if (e->s)
		maximum_characters_printed(e);
}
