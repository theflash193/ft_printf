/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovered_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:38 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/10 13:09:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	recovered_bit(unsigned int position, unsigned long nombre)
{
	return (((1 << position) & nombre) >> position);
}
