#include "ft_printf.h"

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
	else if(t.prec > lenght && !t.minus)
	{
		ft_print_space_and_zero(num, t.prec, ' ', 0);
		ft_print_space_and_zero(num, lenght - 1, '0', 2);
	}
	else if (t.prec > lenght && t.minus)
	{
		ft_print_space_and_zero(num, ((t.width - t.prec) + lenght), '0', 2);
		ft_print_space_and_zero(num, lenght - 1, ' ', 0);
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

