/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:01:24 by grass-kw          #+#    #+#             */
/*   Updated: 2016/03/30 13:42:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_wtoa(wchar_t n)
{
	char	*s;

	if (n <= 0x7F)
	{
		s = ft_strnew(1);
		s[0] = (unsigned char)n;
	}
	else if (n <= 0x7FF)
	{
		s = ft_strnew(2);
		s[0] = (unsigned char)((n >> 6) + 0xC0);
		s[1] = (unsigned char)((n & 0x3F) + 0x80);
	}
	else if (n <= 0xFFFF)
	{
		s = ft_strnew(3);
		s[0] = (unsigned char)((n >> 12) + 0xE0);
		s[1] = (unsigned char)(((n >> 6) & 0x3F) + 0x80);
		s[2] = (unsigned char)((n & 0x3F) + 0x80);
	}
	else
	{
		s = ft_strnew(4);
		s[0] = (unsigned char)((n >> 18) + 0xF0);
		s[1] = (unsigned char)((((n >> 12) & 0x3F) + 0x80));
		s[2] = (unsigned char)(((n >> 6) & 0x3F) + 0x80);
		s[3] = (unsigned char)((n & 0x3F) + 0x80);
	}
	return (s);
}
