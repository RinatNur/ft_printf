/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:22:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/29 21:59:27 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define INT_MIN -2147483648

struct		s_format
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		point;
	char	type;
	int		count;
	int		flag;
	int		xx;
	int		prec_minus;
	int		int_minus;
	int		j_print;
	int		hex_len_count;
}					t;

int			ft_printf(const char *format, ...);
void		ft_parser(const char *format, va_list ap, int *i);
int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);
int			ft_putnbr(int n);
int			ft_xtoi(unsigned long x);
int			ft_num_len(int num, int div);
void		ft_print_pointer(va_list ap);
void		ft_print_char(va_list ap);
void		ft_print_percent(void);
void		ft_print_string(va_list ap);
void		ft_print_unsigned(va_list ap);
void		ft_print_xx(va_list ap);
void		ft_print_integer(va_list ap);

#endif
