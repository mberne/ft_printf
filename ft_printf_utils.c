/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 10:18:36 by mberne            #+#    #+#             */
/*   Updated: 2021/01/11 09:31:45 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_base(long int n, char *base)
{
	long int	i;
	long int	baselen;

	i = 0;
	baselen = ft_strlen(base);
	if (n <= 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= baselen;
		i++;
	}
	return (i);
}

int	ft_int_max(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

int	ft_int_min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

int	check_define(void)
{
	if (HEX_MAJ != "0123456789ABCDEF" || HEX_MIN != "0123456789abcdef"
		|| DEC != "0123456789")
		return (-1);
	return (0);
}
