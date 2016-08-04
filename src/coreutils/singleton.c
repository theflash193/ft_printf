/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 17:06:51 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/19 16:48:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_env 	*singleton(void)
{
	static t_env *e = NULL;

	if (e == NULL)
	{
		e = (t_env *)malloc(sizeof(t_env));
		ft_bzero(e, sizeof(t_env));
		e->formated_string = ft_strnew(1);
	}
	return (e);
}

void	free_singleton(void)
{
	t_env *e;

	
	ft_bzero(e, sizeof(t_env));
	ft_memdel((void *)&e);
}
