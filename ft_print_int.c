/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:36:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/30 00:20:16 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_int_1(int num, int len, char print_sym)
{
	if (t.int_minus == 1 && t.zero == 1)
		t.count += write(1, "-", 1);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (t.int_minus == 1 && t.zero != 1)
		t.count += write(1, "-", 1);
//	if (!(num == 0 && t.prec == 0))
		ft_putnbr(num);
}

static void		ft_print_int_2(int num, int len, char print_sym)
{
	if (t.int_minus == 1)
		t.count += write(1, "-", 1);
	ft_putnbr(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
}

static void		ft_print_int_3(int num, int len)
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
		if (t.width < t.prec)
			t.j_print--;
	}
	while (t.j_print++ < (t.width - len))
		t.count += write(1, "0", 1);
	ft_putnbr(num);
}

static void		ft_print_int_4(int num, int len)
{
	if (t.int_minus == 1)
	{
		t.width--;
		len--;
	}
	if (t.int_minus == 1)
		t.count += write(1, "-", 1);
	while (t.j_print < (t.prec - len))
	{
		t.count += write(1, "0", 1);
		t.j_print++;
	}
	ft_putnbr(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, " ", 1);
}

void			ft_print_integer(va_list ap)
{
	int			num;
	int			lenght;
	char		print_sym;

	num = va_arg(ap, int);
	lenght = ft_num_len(num, 10);
	t.prec = (t.prec < 0) ? (t.point = 0) : t.prec;
	t.zero = (t.point == 1) ? 0 : t.zero;
	print_sym = (t.zero == 1 && t.minus == 0) ? '0' : ' ';
//	if (num == 0)
//		t.width = 0;
	if (num < 0)
		t.int_minus = 1;
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.minus && (t.prec == -1 || t.prec < lenght))
		ft_print_int_1(num, lenght, print_sym);
	else if (t.minus && (t.prec == -1 || t.prec < lenght))
		ft_print_int_2(num, lenght, print_sym);
	else if (t.prec >= lenght && !t.minus)
		ft_print_int_3(num, lenght);
	else if (t.prec >= lenght && t.minus)
		ft_print_int_4(num, lenght);
}
