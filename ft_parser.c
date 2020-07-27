/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:06:00 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 22:54:13 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_parser(const char *format, int *i)
{
	if (!t.type && (ft_strchr("cspdiuxX%", format[*i])))
		t.type = (format[*i]);
	t.xx = (format[*i] == 'X') ? 1 : 0;
	if (t.prec < 0 && t.type == 's')
	{
		t.prec = 0;
		t.prec_minus = 1;
	}
}

void		ft_prec_parser(const char *format, va_list ap, int *i)
{
	if (!t.prec && format[*i] == '.')
	{
		t.point = 1;
		if ('0' <= format[(*i) + 1] && format[(*i) + 1] <= '9')
			t.prec = ft_atoi(&format[++(*i)]);
		else if (format[(*i) + 1] == '*')
			t.prec = va_arg(ap, int);
	}
}

void		ft_width_parser(const char *format, va_list ap, int *i)
{
	if (format[*i] == '*' && !t.width && !t.prec && !t.point)
		t.width = va_arg(ap, int);
	if (!t.width && !t.prec && ('1' <= format[*i] && format[*i] <= '9'))
		t.width = ft_atoi(&format[*i]);
	if (t.width < 0)
	{
		t.width *= -1;
		t.minus = 1;
	}
}

void		ft_flags_parser(const char *format, int *i)
{
	if (format[*i] == '-' && !t.width)
		t.minus = 1;
	if (format[*i] == '0' && !t.zero && !t.width)
		t.zero = 1;
}

void		ft_parser(const char *format, va_list ap, int *i)
{
	(*i)++;
	while (format[*i] != '\0' && !t.type)
	{
		ft_flags_parser(format, i);
		ft_width_parser(format, ap, i);
		ft_prec_parser(format, ap, i);
		ft_type_parser(format, i);
		(*i)++;
	}
	(*i)--;
}
