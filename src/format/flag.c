/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:11:13 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/31 03:37:29 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag(t_env *e)
{
	zero_padding(e);
	if (e->f_alternate_form)
		alternate_form(e);
	if (e->sign || e->blank_positiv_number)
		positive_number(e);
}
