/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:22:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/24 16:51:35 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include "./libft/libft.h"
#include <stdarg.h>

struct		s_format
{
	int minus;
	int zero;
	int width;
	int prec;
	int point;
	char type;
	int count;
}					t;

int			ft_printf(const char *format, ...);
void		ft_type_parser(const char *format, va_list ap, int *i);
void		ft_prec_parser(const char *format, va_list ap, int *i);
void		ft_width_parser(const char *format, va_list ap, int *i);
void		ft_flags_parser(const char *format, int *i);
void		ft_parser(const char *format, va_list ap, int *i);

#endif
