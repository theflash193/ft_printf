/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 00:12:53 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/30 23:11:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	zero_padding(t_env *e)
{
	if (!(e->d || e->o || e->u || e->x || e->x_upper) && e->zero_padded)
		e->zero_padded = 0;
	if (e->zero_padded && e->left_adjusted)
		e->zero_padded = 0;
	if (e->precision > 0 && e->zero_padded)
		e->zero_padded = 0;
}
