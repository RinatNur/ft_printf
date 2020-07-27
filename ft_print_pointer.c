/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:05:47 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 19:07:03 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_xtoi(unsigned long x, int flag)
{
	char		tmp;
	if ((t.point == 1 && t.prec == 0) && x == 0)
	{
		if (t.width > 0)
			t.count += write(1, " " , 1);
		return (0);
	}
	if (x >= 16)
		ft_xtoi(x/16, flag);
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
	if (flag == 0)
		t.count += write(1, &tmp , 1);
	else
		t.hex_len_count++;
	return (t.hex_len_count);
}

int			ft_num_len(int num, int div)
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
	lenght = ft_xtoi(p, 1);;
	if (!t.width)
	{
		t.count += write(1, "0x", 2);
		ft_xtoi(p, 0);
	}
	else if (!t.minus)
	{
		while (j++ < (t.width - (lenght + 2)))
			t.count += write(1, " ", 1);
		t.count += write(1, "0x", 2);
		ft_xtoi(p, 0);
	}
	else if (t.minus)
	{
		t.count += write(1, "0x", 2);
		ft_xtoi(p, 0);
		while (j++ < (t.width - (lenght + 2)))
			t.count += write(1, " ", 1);
	}
}

