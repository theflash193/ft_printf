/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:31:02 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:09:10 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_to_format(t_env *e)
{
	char	*tmp;

	tmp = ft_strjoin(e->s1, e->fmt);
	ft_strclean(e->s1);
	ft_strclean(e->fmt);
	ft_strclean(e->formated_string);
	e->formated_string = tmp;
}
