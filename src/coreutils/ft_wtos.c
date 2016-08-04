/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:23:40 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:10:42 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_wtons(const wchar_t *src, int precision)
{
	char	*dest;
	char	*s;
	int		i;
	char	*tmp;

	i = 0;
	dest = ft_strnew(1);
	while (src[i] != '\0')
	{
		s = ft_wtoa((wchar_t)src[i++]);
		if (precision >= (int)ft_strlen(s))
		{
			precision -= ft_strlen(s);
			tmp = dest;
			dest = ft_strjoin(tmp, s);
			ft_strclean2(&tmp);
			ft_strclean2(&s);
		}
		else
		{
			ft_strclean2(&s);
			continue ;
		}
	}
	return (dest);
}

char	*ft_wtos(const wchar_t *src)
{
	char	*dest;
	char	*s;
	int		i;
	char	*tmp;

	i = 0;
	dest = ft_strnew(1);
	while (src[i] != '\0')
	{
		s = ft_wtoa((wchar_t)src[i++]);
		tmp = dest;
		dest = ft_strjoin(tmp, s);
		ft_strclean2(&(tmp));
		ft_strclean2(&s);
	}
	return (dest);
}
