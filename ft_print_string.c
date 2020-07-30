/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 16:13:46 by jheat             #+#    #+#             */
/*   Updated: 2020/07/30 16:44:11 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (NULL == s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static int		ft_string_checker(char **str, va_list ap)
{
	char		*nl;
	int			lenght;

	nl = "(null)";
	*str = va_arg(ap, char *);
	if (NULL == *str || *str == 0)
	{
		*str = (char *)nl;
		t.prec = (t.prec < 0) ? 6 : t.prec;
	}
	lenght = ft_strlen(*str);
	if ((t.prec == -1 && !t.prec_minus && t.point == 1 && nl != *str))
		lenght = 0;
	if (t.point == 1 && t.prec < lenght && !t.prec_minus)
		lenght = t.prec;
	if (t.width < lenght)
		t.width = lenght;
	return (lenght);
}

void			ft_print_string(va_list ap)
{
	char			*str;
	int				l;
	int				j;

	l = ft_string_checker(&str, ap);
	if ((j = 0) || (((!t.width && !t.minus) && (t.prec == -1 || t.prec >= l))))
		while (j++ < l)
			t.count += write(1, &(*str++), 1);
	if (t.width && !t.minus && (t.prec == -1 || t.prec >= l))
	{
		while (j++ < (t.width - l))
			t.count += write(1, " ", 1);
		while (*str && (j++ <= t.width))
			t.count += write(1, &(*str++), 1);
	}
	if (t.width && t.minus && (t.prec == -1 || t.prec >= l))
	{
		while (*str && (j < l))
		{
			t.count += write(1, &(*str++), 1);
			j++;
		}
		while (j++ < t.width)
			t.count += write(1, " ", 1);
	}
}
