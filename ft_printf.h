/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:22:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/25 18:06:02 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include "./libft/libft.h"
#include <stdarg.h>

# define INT_MIN -2147483648

struct		s_format
{
	int minus;
	int zero;
	int width;
	int prec;
	int point;
	char type;
	int count;
	int X;
	int int_minus;
	int prec_less_lenght;
	int j_print;
}					t;

int			ft_printf(const char *format, ...);
void		ft_type_parser(const char *format, va_list ap, int *i);
void		ft_prec_parser(const char *format, va_list ap, int *i);
void		ft_width_parser(const char *format, va_list ap, int *i);
void		ft_flags_parser(const char *format, int *i);
void		ft_parser(const char *format, va_list ap, int *i);

#endif
