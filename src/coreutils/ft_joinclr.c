/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinclr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 23:47:14 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:48:23 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_joinclr(char *s1, char *s2, int mode)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	if (mode == 1)
		ft_strclean2(&s1);
	if (mode == 2)
	{
		ft_strclean2(&s1);
		ft_strclean2(&s2);
	}
	return (s);
}
