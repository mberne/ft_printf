/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:46:31 by mberne            #+#    #+#             */
/*   Updated: 2021/01/20 15:39:26 by mberne           ###   ########lyon.fr   */
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
	while (form->w_prec > 0)
	{
		ft_putchar_pf('0', form);
		form->w_prec--;
	}
}

long int	ft_putsign(long int x, t_form *form)
{
	if (x < 0)
	{
		ft_putchar_pf('-', form);
		x = -x;
	}
	else if (x >= 0 && form->plus == 1)
		ft_putchar_pf('+', form);
	else if (x >= 0 && form->space == 1)
		ft_putchar_pf(' ', form);
	return (x);
}

int			ft_compare(long long x, int intlen, t_form *form)
{
	int tmp;

	tmp = form->width;
	if (form->width && ft_strchr("pxX", form->spec) && form->hashtag && x != 0)
		form->width -= ft_int_max(form->w_prec, intlen) + 2;
	else if (form->width && (x < 0 || form->plus || form->space))
		form->width -= ft_int_max(form->w_prec, intlen) + 1;
	else if (form->width)
		form->width -= ft_int_max(form->w_prec, intlen);
	if (x == 0 && form->prec && form->w_prec == 0)
	{
		if (form->width || tmp == 1)
			form->width++;
		intlen = 0;
	}
	else if (form->zero && form->width && form->prec == 0 && form->minus == 0)
	{
		form->prec = 1;
		form->w_prec = form->width;
		form->width = 0;
	}
	else if (form->prec)
		form->w_prec -= intlen;
	return (intlen);
}
