/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:06:26 by jheat             #+#    #+#             */
/*   Updated: 2020/07/27 23:18:16 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pr_sp_and_zero_xx(unsigned int num, int len, char sym, int flag)
{
	t.zero = (t.point == 1) ? 0 : t.zero;
	if (t.zero == 1)
		sym = '0';
	if (flag == 1)
		ft_xtoi(num, 0);
	while (t.j_print++ < (t.width - len))
		t.count += write(1, &sym, 1);
	if (flag == 2)
		ft_xtoi(num, 0);
}

int			ft_num_len_un(int num, int div)
{
	int		len;

	len = (num < 0) ? 2 : 1;
	while ((num /= div))
		len++;
	return (len);
}

void		ft_print_xx(va_list ap)
{
	unsigned int		u;
	int					j;
	int					lenght;

	j = 0;
	u = va_arg(ap, unsigned int);
	lenght = ft_num_len_un(u, 16);
	t.width = (t.prec > t.width) ? t.prec : t.width;
	if (!t.width && (!t.prec || t.prec <= lenght))
		ft_xtoi(u, 0);
	else if (!t.minus && (!t.prec || (t.prec <= lenght)))
		ft_pr_sp_and_zero_xx(u, lenght, ' ', 2);
	else if (t.minus && (!t.prec || t.prec <= lenght))
		ft_pr_sp_and_zero_xx(u, lenght, ' ', 1);
	else if (t.prec > lenght && !t.minus)
	{
		ft_pr_sp_and_zero_xx(u, t.prec, ' ', 0);
		ft_pr_sp_and_zero_xx(u, lenght - 1, '0', 2);
	}
	else if (t.prec > lenght && t.minus)
	{
		ft_pr_sp_and_zero_xx(u, ((t.width - t.prec) + lenght), '0', 2);
		ft_pr_sp_and_zero_xx(u, lenght - 1, ' ', 0);
	}
}
