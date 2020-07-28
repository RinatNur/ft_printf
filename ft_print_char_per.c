/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_per.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:09:08 by jheat             #+#    #+#             */
/*   Updated: 2020/07/28 16:51:26 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_char(va_list ap)
{
	int		j;
	int		c;

	c = va_arg(ap, int);
	j = 1;
	if (!t.width)
		t.count += write(1, &c, 1);
	if (!t.minus && t.width)
	{
		while (j++ < t.width)
			t.count += write(1, " ", 1);
		t.count += write(1, &c, 1);
	}
	if (t.minus && t.width)
	{
		t.count += write(1, &c, 1);
		while (j++ < t.width)
			t.count += write(1, " ", 1);
	}
}

void		ft_print_percent(void)
{
	char		sym;
	int			j;
	int			c;

	c = '%';
	j = 1;
	sym = (t.zero == 1 && !t.minus) ? '0' : ' ';
	if (!t.width)
		t.count += write(1, &c, 1);
	if (!t.minus && t.width)
	{
		while (j++ < t.width)
			t.count += write(1, &sym, 1);
		t.count += write(1, &c, 1);
	}
	if (t.minus && t.width)
	{
		t.count += write(1, &c, 1);
		while (j++ < t.width)
			t.count += write(1, &sym, 1);
	}
}
