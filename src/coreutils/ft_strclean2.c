/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:00:51 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:15:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_strclean2(char **s)
{
	if (!*s)
		return ;
	else
	{
		ft_strclr(*s);
		ft_strdel(s);
	}
}
