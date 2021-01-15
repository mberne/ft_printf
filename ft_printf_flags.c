/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:46:31 by mberne            #+#    #+#             */
/*   Updated: 2021/01/15 18:02:13 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putspace(t_form *form)
{
	while (form->width > 0)
	{
		ft_putchar_pf(' ', form);
		form->width--;
	}
}

void		ft_putzero(t_form *form)
{
	while (form->width > 0)
	{
		ft_putchar_pf('0', form);
		form->width--;
	}
}

long int	ft_putsign(long int x, t_form *form)
{
	if (x < 0)
	{
		ft_putchar_pf('-', form);
		x = -x;
	}
	if (x > 0 && form->plus == 1)
		ft_putchar_pf('+', form);
	return (x);
}

void		ft_putprec(int intlen, t_form *form)
{
	while (form->w_prec > intlen)
	{
		ft_putchar_pf('0', form);
		form->w_prec--;
	}
}

void		ft_puthashtag(char *str, t_form *form)
{
	ft_putstr_pf(str, form);
	form->width -= 2;
}
