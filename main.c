/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:21:52 by jheat             #+#    #+#             */
/*   Updated: 2020/07/22 20:34:49 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char		*str = "str %c";
	char 		*s = "new";
	char 		c = 'Z';
	int 		i = 3456;

//	ft_printf("%--0*.566*c", 8, 15);
	printf("%.12*i", 80, 15);//
//	printf("**%.0123i**", 6);///
	return (0);
}