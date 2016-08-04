/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:48:39 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:37:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libftprintf.h"
#include <inttypes.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

int main(void)
{
	int return1;
	int return2;
	int e = 2600;

	// setlocale(LC_ALL, "en_US.UTF-8");
	return1 = printf("%4.15d", 42);
	printf("\n%d\n", return1);
	return2 = ft_printf("%4.15d", 42);
	printf("\n%d\n", return2);
	return (0);
}
