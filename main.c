/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 15:28:25 by mberne            #+#    #+#             */
/*   Updated: 2021/01/12 09:52:48 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	pft(int result)
{
	printf("\033[31m -> %d\033[0m\n", result - 2);
}

int		main(void)
{
	char *p;

	pft(printf("|Bonjour !|"));
	pft(ft_printf("|Bonjour !|"));
	printf("-----\n");
	pft(printf("|Bonjour %c !|", 'u'));
	pft(ft_printf("|Bonjour %c !|", 'u'));
	printf("-----\n");
	pft(printf("|Bonjour %% !|"));
	pft(ft_printf("|Bonjour %% !|"));
	printf("-----\n");
	pft(printf("|Bonjour %s !|", "printf"));
	pft(ft_printf("|Bonjour %s !|", "printf"));
	printf("-----\n");
	pft(printf("|%d|", -55555));
	pft(ft_printf("|%d|", -55555));
	printf("-----\n");
	pft(printf("|%u|", UINT_MAX));
	pft(ft_printf("|%u|", UINT_MAX));
	printf("-----\n");
	pft(printf("|%#x|", 255));
	pft(ft_printf("|%#x|", 255));
	printf("-----\n");
	pft(printf("|%p|", p));
	pft(ft_printf("|%p|", p));
}
