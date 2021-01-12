/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:17:10 by mberne            #+#    #+#             */
/*   Updated: 2021/01/12 09:20:10 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, t_form *form)
{
	write(1, &c, 1);
	form->return_print++;
}

void	ft_putstr_pf(char *s, t_form *form)
{
	int i;

	i = 0;
	if (form->w_prec == 0 && form->prec == 0)
		form->w_prec = ft_strlen(s);
	if (s)
		while (form->w_prec > 0 && s[i])
		{
			ft_putchar_pf(s[i], form);
			i++;
			form->w_prec--;
		}
}

void	ft_putnbr_pf(long int n, char *base, t_form *form)
{
	long int	i;
	int			baselen;

	i = n;
	baselen = ft_strlen(base);
	if (i >= baselen)
		ft_putnbr_pf(i / baselen, base, form);
	ft_putchar_pf(base[i % baselen], form);
}

void	ft_putpointer(unsigned long long p, t_form *form)
{
	unsigned long long int	i;
	char					*base;

	i = p;
	base = HEX_MIN;
	if (i >= 16)
		ft_putpointer(i / 16, form);
	ft_putchar_pf(base[i % 16], form);
}
