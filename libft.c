/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <jheat@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 16:06:43 by jheat             #+#    #+#             */
/*   Updated: 2020/07/26 16:06:57 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i])
	{
		while ((str[i] == 32) || (str[i] > 8 && str[i] < 14))
			i++;
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			res = res * 10 + str[i] - '0';
			i++;
		}
		return (res == 0 ? 0 : (res * sign));
	}
	return (0);
}

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	return (('0' <= c) && (c <= '9'));
}

void		ft_putnbr(int n)
{
	char 	c;

	c = 0;
	if (n == INT_MIN)
		t.count += write(1, "-2147483648", 11);
	else if (n < 0)
		ft_putnbr(n * (-1));
	else
	{
		if (n > 9)
			ft_putnbr(n / 10);
		c = n % 10 + '0';
		t.count += write(1, &c, 1);
	}
}