/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 16:19:57 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:36:27 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*alternate_minimum(size_t lenght_max, char *s, const char *s2)
{
	char	*res;
	size_t	start;
	int		lenght;

	lenght = ft_strlen(s);
	start = lenght_max - lenght;
	res = ft_strnew(lenght_max);
	ft_memset(res, '0', lenght_max);
	ft_memcpy(res, s2, ft_strlen(s2));
	ft_memcpy(res + start, s, lenght);
	return (res);
}

static int	prefix_hexa(t_env *e)
{
	if ((!e->left_adjusted && e->f_alternate_form && e->x && e->zero_padded) ||
		(!e->left_adjusted && e->f_alternate_form && e->x_upper &&
		e->zero_padded))
		return (1);
	return (0);
}

static int	prefix_sign(t_env *e, const char *s2)
{
	if (!e->left_adjusted && e->zero_padded && (ft_strnequ("+", s2, 1) ||
		ft_strnequ("-", s2, 1)))
		return (1);
	return (0);
}

static char	*get_prefix(t_env *e, char *s2)
{
	if (!e->left_adjusted && e->f_alternate_form && e->x && e->zero_padded)
		return ("0x");
	else if (!e->left_adjusted && e->f_alternate_form && e->x_upper)
		return ("0X");
	else if (!e->left_adjusted && e->sign && ft_strnequ(s2, "+", 1))
		return ("+");
	else
		return ("-");
}

void	minimum_field(t_env *e)
{
	char	*s;
	int		justify;
	char	*s2;

	s2 = ft_strdup(e->fmt);
	e->s1 = ft_strdup(e->formated_string);
	ft_strclean2(&(e->formated_string));
	if ((size_t)e->minimum_field > ft_strlen(s2))
	{
		justify = (!e->zero_padded) ? ' ' : '0';
		if (prefix_hexa(e))
			s = alternate_minimum(e->minimum_field, s2, get_prefix(e, s2));
		else if (prefix_sign(e, s2))
			s = alternate_minimum(e->minimum_field, s2 + 1, get_prefix(e, s2));
		else if (!e->left_adjusted)
			s = padding_left(e->minimum_field, s2, justify);
		else
			s = padding_right(e->minimum_field, s2, justify);
		ft_strclean2(&(e->fmt));
		e->fmt = s;
	}
	e->formated_string = e->s1;
	ft_strclean2(&s2);
}
