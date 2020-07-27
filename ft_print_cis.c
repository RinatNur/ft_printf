/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:36:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 22:28:33 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_percent()
{
	char 	sym;
	int 	j;
	int 	c;

	c = '%';
	j = 1;
	sym = (t.zero == 1 && !t.minus) ? '0' : ' ';
	if (!t.width)
		t.count += write(1, &c, 1);
	if (!t.minus && t.width)
	{
		while(j++ < t.width)
			t.count += write(1, &sym, 1);
		t.count += write(1, &c, 1);
	}
	if (t.minus && t.width)
	{
		t.count += write(1, &c, 1);
		while( j++ < t.width)
			t.count += write(1, &sym, 1);
	}
}

void ft_print_space_and_zero(int num, int len, int putnbr_flag)
{
	char 	print_sym;

	t.zero = (t.point == 1) ? 0 : t.zero;
	print_sym = (t.zero == 1 || t.prec >= len) ? '0' : ' ';// >= len (добавил =)
	if (putnbr_flag == 1)
		ft_putnbr(num);
	if (print_sym == '0' && t.int_minus == 1 && t.zero == 1)
		t.j_print--;
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (putnbr_flag == 2)
		ft_putnbr(num);
}

void 	ft_print_int_1(int num, int len, char print_sym)
{
	if (t.int_minus == 1 && t.zero == 1)
		t.count += write(1, "-", 1);
	while (t.j_print++ < (t.width - len)) {
		t.count += write(1, &print_sym, 1);
	}
	if (t.int_minus == 1 && t.zero != 1)
		t.count += write(1, "-", 1);
	ft_putnbr(num);
}

void 	ft_print_int_2(int num, int len, char print_sym)
{
	if (t.int_minus == 1)
		t.count += write(1, "-", 1);
	ft_putnbr(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
}

void 	ft_print_int_3(int num, int len)
{
	if (t.int_minus == 1)
	{
		t.width--;
		len--;
	}
	while (t.j_print < (t.width - t.prec))
	{
		t.count += write(1, " ", 1);
		t.j_print++;
	}
	if (t.int_minus == 1)
	{
		t.count += write(1, "-", 1);
		if(t.width < t.prec)
			t.j_print--;
	}
	while (t.j_print++ < (t.width - len))
	{
		t.count += write(1, "0", 1);
//		t.j_print++;
	}

	ft_putnbr(num);
}

void 	ft_print_int_4(int num, int len)
{
	if (t.int_minus == 1)
	{
		t.width--;
		len--;
	}
	if (t.int_minus == 1)
		t.count += write(1, "-", 1);
	while (t.j_print < (t.prec -len))
	{
		t.count += write(1, "0", 1);
		t.j_print++;
	}
	ft_putnbr(num);
	while (t.j_print++ < (t.width - len))
	{
		t.count += write(1, " ", 1);
	}

}

void 	ft_print_integer(va_list ap)
{
	int 	num;
	int 	lenght;
	char 	print_sym;

	num = va_arg(ap, int);
	lenght = ft_num_len(num, 10);
	t.zero = (t.point == 1) ? 0 : t.zero;
	print_sym = (t.zero == 1 && t.minus == 0 && (!t.point || (t.point && t.prec > lenght))) ? '0' : ' ';
	t.prec_less_lenght = (t.prec < lenght) ? 1 : 0;
	if (num < 0)
	{
		t.int_minus = 1;
//		lenght--;
	}
//	if (t.prec_less_lenght == 0 && t.width)
//		t.width--;
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.minus && (!t.prec || t.prec < lenght))
		ft_print_int_1(num, lenght, print_sym);
//		ft_print_space_and_zero(num, lenght, 2);
	else if (t.minus && (!t.prec || t.prec < lenght))
		ft_print_int_2(num, lenght, print_sym);
//		ft_print_space_and_zero(num, lenght, 1);
	else if(t.prec >= lenght && !t.minus)
	{
//		t.count += write(1, "-", 1);
		ft_print_int_3(num, lenght);
//		ft_print_space_and_zero(num, t.prec, 0);
//		ft_print_space_and_zero(num, lenght - 1, 2);
	}
	else if (t.prec >= lenght && t.minus)
	{
		ft_print_int_4(num, lenght);
//		ft_print_space_and_zero(num, ((t.width - t.prec) + lenght), 2);
//		ft_print_space_and_zero(num, lenght - 1,  0);
	}
}

void			ft_print_char(va_list ap)
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

void			ft_print_string(va_list ap)
{
	char 	*str;
	int 	lenght;
	const char		*nl = "(null)";
	int 	j;
	int 	flag;

	j = 0;
	str = va_arg(ap, char *);
	if (NULL == str || str == 0)
	{
		str = (char *)nl;
		if (t.prec < 0)
			t.prec = 6;
		flag = 1;
	}
	lenght = ft_strlen(str);
	if (t.prec == 0 && !t.prec_minus && t.point == 1 && nl != str)
		lenght = 0;
	else if (t.point == 1 && t.prec < lenght && !t.prec_minus)
		lenght = t.prec;
	if (t.width < lenght)
		t.width = lenght;
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
		while(*str && (j < lenght))
		{
			t.count += write(1, &(*str++), 1);
			j++;
		}
		while (j++ < t.width)
			t.count += write(1, " ", 1);
	}
}

