/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:02:47 by jheat             #+#    #+#             */
/*   Updated: 2020/07/22 20:11:55 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void            ft_struct_zero()
{
	t.minus = 0;
	t.zero = 0;
	t.width = 0;
	t.prec = 0;
	t.type = '\0';
}

static void		struct_print()
{
	printf("t.minus = %i\n", t.minus);
	printf("t.zero = %i\n", t.zero);
	printf("t.width = %i\n", t.width);
	printf("t.prec = %i\n", t.prec);
	printf("t.type = %c", t.type);
}

//static void 	ft_type_parser(const char *format, va_list ap, int *i)
//{
//	if (format[*i] == 'c')
//		t.type = 'c';
//		ft_char_type(format, va_arg(ap, int));
//    if (format[*i] == 's')
//        ft_string_type();
//    if (format[*i] == 'p')
//        ft_pointer_type();
//    if (format[*i] == 'i' || format[*i] == 'd')
//        ft_int_type();
//    if (format[*i] == 'u')
//        ft_un_int_type();
//    if (format[*i] == 'x' || format[*i] == 'X')
//        ft_un_xx_type();
//    if (format[*i] == '%')
//        ft_percent_type();
//}

static void			ft_type_parser(const char *format, va_list ap, int *i)
{
	char 	*ptr;
//	ptr = ft_strchr("cspdiuxX%", format[*i]);
	if (!t.type && (ft_strchr("cspdiuxX%", format[*i])))
		t.type = (format[*i]);
}

static void         ft_prec_parser(const char *format, va_list ap, int *i)
{
	if (!t.prec && format[*i] == '.')
	{
		if ('0' <= format[(*i) + 1] && format[(*i) + 1] <= '9')
			t.prec = ft_atoi(&format[++(*i)]);
		else if (format[(*i) + 1] == '*')
			t.prec = va_arg(ap, int);
	}
}

static void         ft_width_parser(const char *format, va_list ap, int *i)
{
	if (!t.width && !t.prec && format[*i] == '*')
		t.width = va_arg(ap, int);
	if(!t.width && !t.prec && ('1' <= format[*i] && format[*i] <= '9'))
		t.width = ft_atoi(&format[*i]);
}

static void         ft_flags_parser(const char *format, int *i)
{
	if(format[*i] == '-' && !t.zero && !t.width)
			t.minus = 1;
	if(format[*i] == '0' && !t.zero && !t.width)
			t.zero = 1;
}

static void		ft_parser(const char *format, va_list ap, int *i)
{
	(*i)++;
	while (format[*i] != '\0' && !t.type)
	{
		ft_flags_parser(format, i);
		ft_width_parser(format, ap, i);
		ft_prec_parser(format, ap, i);
		ft_type_parser(format, ap, i);
		(*i)++;
	}
	struct_print();
//

}

int        ft_printf(const char *format, ...)
{
	int         i;
	int         count;
	va_list     ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] != '%' )
		{
			write (1, &format[i], 1);
			count ++;
		}
		else if (format[i] == '%')
		{
			ft_struct_zero();
			ft_parser(format, ap, &i);
		}
		if(format[i])
			i++;
	}
	va_end(ap);
	return (count);
}