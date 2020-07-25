#include "ft_printf.h"

void ft_print_space_and_zero_xx(unsigned int num, int len, char print_sym, int putnbr_flag)
{
	if (putnbr_flag == 1)
		ft_xtoi(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &print_sym, 1);
	if (putnbr_flag == 2)
		ft_xtoi(num);
}

int			ft_num_len_un(int num, int div)
{
	int		len;

	len = (num < 0) ? 2 : 1;
	while ((num /= div))
		len++;
	return (len);
}

void 	ft_print_xx(va_list ap)
{
	unsigned int 		u;
	int 	j;
	int		lenght;

	j = 0;
	u = va_arg(ap, unsigned int);
	lenght = ft_num_len_un(u, 16);
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
