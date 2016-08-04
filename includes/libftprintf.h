/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:07:56 by grass-kw          #+#    #+#             */
/*   Updated: 2016/04/01 15:02:13 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdio.h>
# include <locale.h>
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct		s_env
{
	va_list			ap;
	char			*fmt;
	unsigned int	s : 1;
	unsigned int	p : 1;
	unsigned int	d : 1;
	unsigned int	o : 1;
	unsigned int	u : 1;
	unsigned int	x : 1;
	unsigned int	x_upper : 1;
	unsigned int	c : 1;
	unsigned int	modulo : 1;
	unsigned int	hh : 1;
	unsigned int	h : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
	unsigned int	f_alternate_form : 1;
	unsigned int	zero_padded : 1;
	unsigned int	left_adjusted : 1;
	unsigned int	blank_positiv_number : 1;
	unsigned int	sign : 1;
	int				minimum_field;
	int				get_minimum_field;
	int				f_precision;
	int				precision;
	int				get_precision;
	char			*formated_string;
	char			*s1;
}					t_env;

/*
*** coreutils
*/
unsigned int		recovered_bit(unsigned int position, unsigned long nombre);
void				bit_display(unsigned long number, int start, int end);
void				free_singleton(void);
t_env				*singleton(void);
int					is_conversion(char c);
int					is_length_modifier(char *c);
int					is_flag(char c);
void				set_conversion(char option, t_env *e);
void				reinitialize_flags_conversion(t_env *e);
void				set_flags(char option, t_env *e);
void				set_lenght_modifier(char *option, t_env *e);
void				add_to_format(t_env *e);
char				*ft_itoa_long(long long n);
void				ft_capitalize(char *s);
char				*ft_wtos(const wchar_t *src);
void				ini_lenght_modifier(t_env *e);
char				*padding_left(size_t lenght_max, char *s, int justify);
char				*padding_right(size_t lenght_max, char *s, int justify);
char				*ft_wtons(const wchar_t *src, int precision);
char				*ft_wtoa(wchar_t n);
char				*ft_itoa_base(unsigned long long n, int base);
char				*ft_joinclr(char *s1, char *s2, int mode);
void				ft_strclean2(char **s);

/*
*** main
*/
int					ft_printf(const char *format, ...);

/*
*** parser
*/
int					parser(char *format, t_env *e);

/*
** conversion
*/

char				*conversion_s(va_list ap, t_env *e);
char				*conversion_c(va_list ap, t_env *e);
char				*modulo(void);

char				*conversion_o(va_list ap, t_env *e);
char				*conversion_u(va_list ap,t_env *e);
char				*conversion_x(va_list ap, t_env *e);
char				*conversion_di(va_list ap, t_env *e);

/*
*** format
*/
void				conversion_formatting(t_env *e);
void				flag(t_env *e);
void				alternate_form(t_env *e);
void				case_o(t_env *e);
void				positive_number(t_env *e);
void				zero_padding(t_env *e);
void				minimum_field(t_env *e);
void				precision(t_env *e);

#endif
