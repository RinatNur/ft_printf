/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:06:20 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 23:29:02 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_un(unsigned int n)
{
	char		c;

	c = 0;
	if (n > 9)
		ft_putnbr_un(n / 10);
	c = n % 10 + '0';
	t.count += write(1, &c, 1);
}

void		ft_pr_sp_and_zero_un(unsigned int num, int len, char sym, int flag)
{
	t.zero = (t.point == 1) ? 0 : t.zero;
	if (t.zero == 1)
		sym = '0';
	if (flag == 1 && (!t.point || (t.point && t.prec != 0)))
		ft_putnbr_un(num);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &sym, 1);
	if (flag == 2 && (!t.point || (t.point && t.prec != 0)))
		ft_putnbr_un(num);
}

void		ft_print_unsigned(va_list ap)
{
	int		num;
	int		lenght;

	num = va_arg(ap, int);
	lenght = ft_num_len(num, 10);
	if (t.point && t.prec == 0)
		lenght = 0;
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.minus && (!t.prec || t.prec <= lenght))
		ft_pr_sp_and_zero_un(num, lenght, ' ', 2);
	else if (t.minus && (!t.prec || t.prec <= lenght))
		ft_pr_sp_and_zero_un(num, lenght, ' ', 1);
	else if (t.prec > lenght && !t.minus)
	{
		ft_pr_sp_and_zero_un(num, t.prec, ' ', 0);
		ft_pr_sp_and_zero_un(num, lenght - 1, '0', 2);
	}
	else if (t.prec > lenght && t.minus)
	{
		ft_pr_sp_and_zero_un(num, ((t.width - t.prec) + lenght), '0', 2);
		ft_pr_sp_and_zero_un(num, lenght - 1, ' ', 0);
	}
}
