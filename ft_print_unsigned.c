#include "ft_printf.h"

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
