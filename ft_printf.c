/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:02:39 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 22:43:33 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_struct_zero(void)
{
	t.minus = 0;
	t.zero = 0;
	t.width = 0;
	t.prec = 0;
	t.prec_minus = 0;
	t.point = 0;
	t.j_print = 0;
	t.X = 0;
	t.int_minus = 0;
	t.prec_less_lenght = 0;
	t.hex_len_count = 0;
	t.type = '\0';
}

void		ft_check_type(va_list ap)
{
	if (t.type == '%')
		ft_print_percent();
	if (t.type == 'c')
		ft_print_char(ap);
	if (t.type == 's')
		ft_print_string(ap);
	if (t.type == 'p')
		ft_print_pointer(ap);
	if (t.type == 'd' || t.type == 'i')
		ft_print_integer(ap);
	if (t.type == 'u')
		ft_print_unsigned(ap);
	if (t.type == 'x' || t.type == 'X')
		ft_print_xx(ap);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;

	t.count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			t.count += write(1, &format[i], 1);
		else if (format[i] == '%')
		{
			ft_struct_zero();
			ft_parser(format, ap, &i);
			ft_check_type(ap);
		}
		if (format[i])
			i++;
	}
	va_end(ap);
	return (t.count);
}
