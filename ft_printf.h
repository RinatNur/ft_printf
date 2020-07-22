/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:22:10 by jheat             #+#    #+#             */
/*   Updated: 2020/07/22 19:53:40 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include "./libft/libft.h"
#include <stdarg.h>

struct		s_format
{
	int minus;
	int zero;
	int width;
	int prec;
	char type;
}					t;

int 	ft_printf(const char *format, ...);

#endif
