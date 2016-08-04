/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positive_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:01:20 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:13:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	positive_number(t_env *e)
{
	char	*str;
	char	positive[2];

	if (e->d)
	{
		if (e->fmt && e->fmt[0] != '-' && e->d)
		{
			positive[0] = (e->sign) ? '+' : ' ';
			str = ft_strjoin(positive, e->fmt);
			ft_strclean2(&(e->fmt));
			e->fmt = str;
		}
	}
}
