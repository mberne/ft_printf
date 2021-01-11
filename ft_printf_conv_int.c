/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:56:25 by mberne            #+#    #+#             */
/*   Updated: 2021/01/11 14:35:09 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_di(t_form *form)
{
	int x;
	int intlen;

	x = va_arg(*(form->ap), int);
	intlen = ft_intlen_base(x, DEC);
	if (form->width)
		form->width -= ft_int_max(form->w_prec, intlen);
	if (form->w_prec > intlen)
		form->w_prec -= intlen;
	if (form->width >= 0 && form->minus == 1)
	{
		if (x < 0)
		{
			ft_putchar_pf('-', form);
			x = -x;
		}
		ft_putnbr_pf(x, DEC, form);
		while (form->width != 0)
		{
			ft_putchar_pf(' ', form);
			form->width--;
		}
	}
	else if (form->width >= 0 && form->minus == 0)
	{
		while (form->width != 0)
		{
			ft_putchar_pf(' ', form);
			form->width--;
		}
		if (x < 0)
		{
			ft_putchar_pf('-', form);
			x = -x;
		}
		ft_putnbr_pf(x, DEC, form);
	}
	else
		ft_putnbr_pf(x, DEC, form);
}

void	ft_conv_u(t_form *form)
{
	unsigned int x;

	x = va_arg(*(form->ap), unsigned int);
	if (form->width)
		form->width -= ft_int_max(form->w_prec, ft_intlen_base(x, DEC));
	ft_putnbr_pf(va_arg(*(form->ap), unsigned int), DEC, form);
}

void	ft_conv_x_min(t_form *form)
{
	int x;

	x = va_arg(*(form->ap), int);
	if (form->width)
		form->width -= ft_int_max(form->w_prec, ft_intlen_base(x, HEX_MIN));
	ft_putnbr_pf(va_arg(*(form->ap), int), HEX_MIN, form);
}

void	ft_conv_x_maj(t_form *form)
{
	int x;

	x = va_arg(*(form->ap), int);
	if (form->width)
		form->width -= ft_int_max(form->w_prec, ft_intlen_base(x, HEX_MAJ));
	ft_putnbr_pf(va_arg(*(form->ap), int), HEX_MAJ, form);
}

void	ft_conv_p(t_form *form)
{
	int x;

	x = va_arg(*(form->ap), int);
	if (form->width)
		form->width -= ft_int_max(form->w_prec, ft_intlen_base(x, HEX_MIN));
	ft_putpointer((unsigned long long)va_arg(*(form->ap), void *), form);
}
