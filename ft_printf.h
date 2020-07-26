/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:22:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/26 21:06:18 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
void		ft_check_type(va_list ap);
void		ft_struct_zero();
void		ft_type_parser(const char *format, int *i);
void		ft_prec_parser(const char *format, va_list ap, int *i);
void		ft_width_parser(const char *format, va_list ap, int *i);
void		ft_flags_parser(const char *format, int *i);
void		ft_parser(const char *format, va_list ap, int *i);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
void		ft_putnbr(int n);
int			ft_xtoi(unsigned long x, int flag);
int			ft_num_len(int num, int div);
void		ft_print_pointer(va_list ap);
void		ft_print_char(va_list ap);
void		ft_print_percent();
void		ft_print_string(va_list ap);
void		ft_print_space_and_zero_xx(unsigned int num, int len, char print_sym, int putnbr_flag);
int			ft_num_len_un(int num, int div);
void		ft_putnbr_un(unsigned int n);
void		ft_print_space_and_zero_un(unsigned int num, int len, char print_sym, int putnbr_flag);
void		ft_print_unsigned(va_list ap);
void		ft_print_xx(va_list ap);
void		ft_print_integer(va_list ap);
void		ft_print_space_and_zero(int num, int len, char print_sym, int putnbr_flag);

#endif
