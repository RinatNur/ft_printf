/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:21:52 by jheat             #+#    #+#             */
/*   Updated: 2020/07/25 20:32:35 by jheat            ###   ########.fr       */
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

// Integer (-)
	count = ft_printf("10.**%d %p %x %s**", -555, &st, 123, output);
	printf("     count = %i\n", count - 4);
	count = printf("10.**%d %p %x %s**", -555, &st, 123, output);
	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("11.**%10d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("11.**%10d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("12.**%-10d**", -555);
//	printf("     count = %i\n", count - 7);
//	count = printf("12.**%-10d**", -555);
//	printf("     count = %i\n", count - 7);
//
//	count = ft_printf("13.**%10.2d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("13.**%10.2d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("14.**%-10.2d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("14.**%-10.2d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("15.**%10.8d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("15.**%10.8d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("16.**%-10.5d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("16.**%-10.5d**", -555);
//	printf("     count = %i\n", count - 4);
////
//	count = ft_printf("17.**%.d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("17.**%.d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("18.**%.2d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("18.**%.2d**", -555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("19.**%.5d**", -555);
//	printf("     count = %i\n", count - 4);
//	count = printf("19.**%.5d**", -555);
//	printf("     count = %i\n", count - 4);

	//u
//	count = ft_printf("30.**%u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("30.**%u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("31.**%10u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("31.**%10u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("32.**%-10u**", 555);
//	printf("     count = %i\n", count - 7);
//	count = printf("32.**%-10u**", 555);
//	printf("     count = %i\n", count - 7);
//
//	count = ft_printf("33.**%10.2u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("33.**%10.2u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("34.**%-10.2u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("34.**%-10.2u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("35.**%10.8u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("35.**%10.8u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("36.**%-20.5u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("36.**%-20.5u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("37.**%.u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("37.**%.u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("38.**%.2u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("38.**%.2u**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("39.**%.5u**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("39.**%.5u**", 555);
//	printf("     count = %i\n", count - 4);
//X
//	count = ft_printf("21.**%10x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("21.**%10x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("22.**%-10x**", 555);
//	printf("     count = %i\n", count - 7);
//	count = printf("22.**%-10x**", 555);
//	printf("     count = %i\n", count - 7);
//
//	count = ft_printf("23.**%10.2x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("23.**%10.2x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("24.**%-10.2x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("24.**%-10.2x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("25.**%10.8x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("25.**%10.8x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("26.**%-20.5x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("26.**%-20.5x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("27.**%.x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("27.**%.x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("28.**%.2x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("28.**%.2x**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("29.**%.5x**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("29.**%.5x**", 555);
//	printf("     count = %i\n", count - 4);

//Integer
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
//
//	count = ft_printf("15.**%10.8d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("15.**%10.8d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("16.**%-20.5d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("16.**%-20.5d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("17.**%.d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("17.**%.d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("18.**%.2d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("18.**%.2d**", 555);
//	printf("     count = %i\n", count - 4);
//
//	count = ft_printf("19.**%.5d**", 555);
//	printf("     count = %i\n", count - 4);
//	count = printf("19.**%.5d**", 555);
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
