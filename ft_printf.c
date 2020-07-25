/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:02:39 by jheat             #+#    #+#             */
/*   Updated: 2020/07/25 20:32:23 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void            ft_struct_zero()
{
	t.minus = 0;
	t.zero = 0;
	t.width = 0;
	t.prec = 0;
	t.point = 0;
	t.j_print = 0;
	t.X = 0;
	t.int_minus = 0;
	t. prec_less_lenght = 0;
	t.type = '\0';
}

static void		struct_print()
{
	printf("t.minus = %i\n", t.minus);
	printf("t.zero = %i\n", t.zero);
	printf("t.width = %i\n", t.width);
	printf("t.prec = %i\n", t.prec);
	printf("t.type = %c\n", t.type);
}

void			ft_type_parser(const char *format, va_list ap, int *i)
{
	if (!t.type && (ft_strchr("cspdiuxX%", format[*i])))
		t.type = (format[*i]);
	t.X = (format[*i] == 'X') ? 1 : 0;
}

void         ft_prec_parser(const char *format, va_list ap, int *i)
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

void         ft_width_parser(const char *format, va_list ap, int *i)
{
	if (!t.width && !t.prec && format[*i] == '*')
		t.width = va_arg(ap, int);
	if (!t.width && !t.prec && ('1' <= format[*i] && format[*i] <= '9'))
		t.width = ft_atoi(&format[*i]);
}

void         ft_flags_parser(const char *format, int *i)
{
	if(format[*i] == '-' && !t.zero && !t.width)
		t.minus = 1;
	if(format[*i] == '0' && !t.zero && !t.width)
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
		ft_type_parser(format, ap, i);
		(*i)++;
	}
	(*i)--;
}

static void			ft_print_char(va_list ap)
{
	int 	j;
	int 	c;

	c = va_arg(ap, int);
	j = 1;
	if (!t.width)
		t.count += write(1, &c, 1);
	if (!t.minus && t.width)
	{
		while( j++ < t.width)
			t.count += write(1, " ", 1);
		t.count += write(1, &c, 1);
	}
	if (t.minus && t.width)
	{
		t.count += write(1, &c, 1);
		while( j++ < t.width)
			t.count += write(1, " ", 1);
	}
}

static void			ft_print_string(va_list ap)
{
	char 	*str;
	int 	lenght;
	int 	j;

	j = 0;
	str = va_arg(ap, char *);
	lenght = ft_strlen(str);
	if (t.prec == 0 && t.point == 1)
		lenght = 0;
	else if (t.point == 1 && t.prec < lenght)
		lenght = t.prec;
	// 1,8,10
	if ((!t.width && !t.minus) && (t.prec == 0 || t.prec >= lenght))
		while(j++ < lenght)
			t.count += write(1, &(*str++), 1);
	//2,4,6
	if (t.width && !t.minus && (!t.prec || t.prec >=lenght))
	{
		while (j++ < (t.width - lenght))
			t.count += write(1, " ", 1);
		while(*str && (j++ <= t.width))
			t.count += write(1, &(*str++), 1);
	}
	//3,5, 7
	if (t.width && t.minus && (!t.prec || t.prec >=lenght))
	{
		while(*str && (j++ < lenght))
			t.count += write(1, &(*str++), 1);
		if (t.prec == lenght)
			j--;
		while (j++ < t.width)
			t.count += write(1, " ", 1);
	}
}

static void        ft_xtoi(unsigned long x)
{
	char   tmp;

	if (x >= 16)
		ft_xtoi(x/16);
	tmp = x % 16 + '0';
	if(tmp == (10 + '0'))
		tmp = (t.X == 1) ? 'A' : 'a';
	else if(tmp == (11 + '0'))
		tmp = (t.X == 1) ? 'B' : 'b';
	else if(tmp == (12 + '0'))
		tmp = (t.X == 1) ? 'C' : 'c';
	else if(tmp == (13 + '0'))
		tmp = (t.X == 1) ? 'D' : 'd';
	else if(tmp == (14 + '0'))
		tmp = (t.X == 1) ? 'E' : 'e';
	else if(tmp == (15 + '0'))
		tmp = (t.X == 1) ? 'F' : 'f';
	t.count += write(1, &tmp , 1);
}

static int			ft_num_len(int num, int div) // убрал unsigned. возможно где-то ошибка выйдет
{
	int		len;

	len = (num < 0) ? 2 : 1;
	while ((num /= div))
		len++;
	return (len);
}

static void 		ft_print_pointer(va_list ap)
{
	unsigned long		p;
	int 	j;
	int		lenght;

	j = 0;
	p = va_arg(ap, unsigned long);
	lenght = ft_num_len(p, 16);
	if (!t.width)
	{
		t.count += write(1, "0x", 2);
		ft_xtoi(p);
	}
	else if (!t.minus)
	{
		while (j++ < (t.width - (lenght + 2)))
			t.count += write(1, " ", 1);
		t.count += write(1, "0x", 2);
		ft_xtoi(p);
	}
	else if (t.minus)
	{
		t.count += write(1, "0x", 2);
		ft_xtoi(p);
		while (j++ < (t.width - (lenght + 2)))
			t.count += write(1, " ", 1);
	}
}

void		ft_putnbr(int n)
{
	char 	c;

	c = 0;
	if (n == INT_MIN)
		t.count += write(1, "-2147483648", 11);
	else if (n < 0)
	{
//		t.count += write(1, "-", 1);
		ft_putnbr(n * (-1));
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		c = n % 10 + '0';
		t.count += write(1, &c, 1);
	}
}

void ft_print_space_and_zero(int num, int len, char print_sym, int putnbr_flag)
{
	if (putnbr_flag == 1)
	{
		if (t.int_minus == 1 && t.prec_less_lenght == 1)
			t.count += write(1, "-", 1);
		ft_putnbr(num);
	}

	if (print_sym == '0')
	{
		t.count += write(1, "-", 1);
		t.j_print--;
	}
//	len = (!t.minus && t.width && t.prec_less_lenght == 0) ? (len + 1) : len;
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (putnbr_flag == 2)
	{
		if (t.int_minus == 1 && t.prec_less_lenght == 1)
			t.count += write(1, "-", 1);
		ft_putnbr(num);
	}
}

void 	ft_print_integer(va_list ap)
{
	int 	num;
	int 	lenght;

	num = va_arg(ap, int);
	lenght = ft_num_len(num, 10);
	t.prec_less_lenght = (t.prec < lenght) ? 1 : 0;
	if (num < 0)
		t.int_minus = 1;
	if (t.prec_less_lenght == 0 && t.width)
		t.width--;
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.minus && (!t.prec || t.prec <= lenght))
		ft_print_space_and_zero(num, lenght, ' ', 2);
	else if (t.minus && (!t.prec || t.prec <= lenght))
		ft_print_space_and_zero(num, lenght, ' ', 1);
	//15, 19
	else if(t.prec > lenght && !t.minus)
	{
		ft_print_space_and_zero(num, t.prec, ' ', 0);
		ft_print_space_and_zero(num, lenght - 1, '0', 2);
	}
	//16
	else if (t.prec > lenght && t.minus)
	{
		ft_print_space_and_zero(num, ((t.width - t.prec) + lenght), '0', 2);
		ft_print_space_and_zero(num, lenght - 1, ' ', 0);
	}
}

void ft_print_space_and_zero_xx(unsigned int num, int len, char print_sym, int putnbr_flag)
{
	if (putnbr_flag == 1)
		ft_xtoi(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (putnbr_flag == 2)
		ft_xtoi(num);
}

void 	ft_print_xx(va_list ap)
{
	unsigned int 		u;
	int 	j;
	int		lenght;

	j = 0;
	u = va_arg(ap, unsigned int);
	lenght = ft_num_len(u, 16);
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.width && (!t.prec || t.prec <= lenght))
		ft_xtoi(u);
	else if (!t.minus && (!t.prec || t.prec <= lenght))
	{
		while (j++ < (t.width - (lenght)))
			t.count += write(1, " ", 1);
		ft_xtoi(u);
	}
	else if (t.minus && (!t.prec || t.prec <= lenght))
	{
		ft_xtoi(u);
		while (j++ < (t.width - (lenght)))
			t.count += write(1, " ", 1);
	}
	else if(t.prec > lenght && !t.minus)
	{
		ft_print_space_and_zero_xx(u, t.prec, ' ', 0);
		ft_print_space_and_zero_xx(u, lenght - 1, '0', 2);
	}
	else if (t.prec > lenght && t.minus)
	{
		ft_print_space_and_zero_xx(u, ((t.width - t.prec) + lenght), '0', 2);
		ft_print_space_and_zero_xx(u, lenght - 1, ' ', 0);
	}
}

void		ft_putnbr_un(unsigned int n)
{
	char 	c;

	c = 0;
	if (n > 9)
		ft_putnbr_un(n / 10);
	c = n % 10 + '0';
	t.count += write(1, &c, 1);
}

void ft_print_space_and_zero_un(unsigned int num, int len, char print_sym, int putnbr_flag)
{
	if (putnbr_flag == 1)
		ft_putnbr(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (putnbr_flag == 2)
		ft_putnbr(num);
}

void 	ft_print_unsigned(va_list ap)
{
	int 	num;
	int 	lenght;

	lenght = ft_num_len((num = va_arg(ap, int)), 10);
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.minus && (!t.prec || t.prec <= lenght))
		ft_print_space_and_zero_un(num, lenght, ' ', 2);
	else if (t.minus && (!t.prec || t.prec <= lenght))
		ft_print_space_and_zero_un(num, lenght, ' ', 1);
	else if(t.prec > lenght && !t.minus)
	{
		ft_print_space_and_zero_un(num, t.prec, ' ', 0);
		ft_print_space_and_zero_un(num, lenght - 1, '0', 2);
	}
	else if (t.prec > lenght && t.minus)
	{
		ft_print_space_and_zero_un(num, ((t.width - t.prec) + lenght), '0', 2);
		ft_print_space_and_zero_un(num, lenght - 1, ' ', 0);
	}
}

static void 		ft_check_type(va_list ap)
{
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

int        ft_printf(const char *format, ...)
{
	int         i;
	int         count;
	va_list     ap;

	t.count = 0;
	i = 0;
	count = 0;
	va_start(ap, format);
	while(format[i])
	{
		if (format[i] != '%' )
			t.count += write (1, &format[i], 1);
		else if (format[i] == '%')
		{
			ft_struct_zero();
			ft_parser(format, ap, &i);
			ft_check_type(ap);
		}
		if(format[i])
			i++;
	}
	va_end(ap);
	return (t.count);
}