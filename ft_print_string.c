/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:13:46 by jheat             #+#    #+#             */
/*   Updated: 2020/07/28 16:13:49 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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