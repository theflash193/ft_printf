/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:18:06 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/10 14:13:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	bit_display(unsigned long number, int start, int end)
{
	int position;
	char bit;

	position = end - 1;
	while (position >= start)
	{
		bit = recovered_bit(position--, number) + 48;
		write(1, &bit, 1);
	}
}
