/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:21:52 by jheat             #+#    #+#             */
/*   Updated: 2020/07/24 20:18:29 by jheat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main()
{
	char		*str = "**%5.2s**";
	char 		*output = "str";
	char 		*st = "strwr";
	int 		count;
	int 		i = 3456;

//	count = ft_printf("10.**%d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("10.**%d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("11.**%10d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("11.**%10d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("12.**%-10d**", 555);
//	printf("     count = %i\n", count - 7);
//	count = printf("12.**%-10d**", 555);
//	printf("     count = %i\n", count - 7);
//
//	count = ft_printf("13.**%10.2d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("13.**%10.2d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("14.**%-10.2d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("14.**%-10.2d**", 555);
//	printf("     count = %i\n", count - 4);

	count = ft_printf("15.**%10.8d**", 555);
	printf("     count = %i\n", count - 4);
	count = printf("15.**%10.8d**", 555);
	printf("     count = %i\n", count - 4);

	count = ft_printf("16.**%-10.5d**", 555);
	printf("     count = %i\n", count - 4);
	count = printf("16.**%-10.5d**", 555);
	printf("     count = %i\n", count - 4);

	count = ft_printf("17.**%.d**", 555);
	printf("     count = %i\n", count - 4);
	count = printf("17.**%.d**", 555);
	printf("     count = %i\n", count - 4);

	count = ft_printf("18.**%.2d**", 555);
	printf("     count = %i\n", count - 4);
	count = printf("18.**%.2d**", 555);
	printf("     count = %i\n", count - 4);

	count = ft_printf("19.**%.5d**", 555);
	printf("     count = %i\n", count - 4);
	count = printf("19.**%.5d**", 555);
	printf("     count = %i\n", count - 4);

//Integer
//	count = ft_printf("10.**%-10d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("10.**%-10d**", 555);///
//	printf("     count = %i\n", count - 4);
//Pointer
//	count = ft_printf("10.**%-32p**", &st);
//	printf("     count = %i\n", count - 4);
//	count = printf("10.**%-32p**", &st);///
//	printf("     count = %i\n", count - 4);

//	printf("String\n");
//	count = ft_printf("1.**%s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("1.**%s**", output);///
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("2.**%10s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("2.**%10s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("3.**%-10s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("3.**%-10s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("4.**%10.1s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("4.**%10.1s**", output);///
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("5.**%-10.1s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("5.**%-10.1s**", output);///
//	printf("     count = %i\n", count - 4);
////
//	count = ft_printf("6.**%10.4s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("6.**%10.4s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("7.**%-10.4s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("7.**%-10.4s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("8.**%.s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("8.**%.s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("9.**%.2s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("9.**%.2s**", output);///
//	printf("     count = %i\n", count - 4);

//	count = ft_printf("10.**%.4s**", output);
//	printf("     count = %i\n", count - 4);
//	count = printf("10.**%.4s**", output);///
//	printf("     count = %i\n", count - 4);
	return (0);
}
