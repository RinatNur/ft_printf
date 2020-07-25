#include "ft_printf.h"

void        ft_xtoi(unsigned long x)
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

int			ft_num_len(int num, int div) // убрал unsigned. возможно где-то ошибка выйдет
{
	int		len;

	len = (num < 0) ? 2 : 1;
	while ((num /= div))
		len++;
	return (len);
}

void 		ft_print_pointer(va_list ap)
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
