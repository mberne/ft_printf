/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:33:22 by mberne            #+#    #+#             */
/*   Updated: 2021/01/19 09:01:13 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_form *form)
{
	form->width -= 1;
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->zero == 1)
		ft_putzero(form);
	ft_putchar_pf(va_arg(*(form->ap), int), form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_percent(t_form *form)
{
	form->width -= 1;
	if (form->zero && form->minus == 0)
	{
		form->w_prec = form->width;
		form->width = 0;
	}
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->zero == 1)
		ft_putzero(form);
	ft_putchar_pf('%', form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_s(t_form *form)
{
	char *str;

	if (!(str = va_arg(*(form->ap), char *)))
		str = "(null)";
	if (form->width)
	{
		if (form->prec)
			form->width -= ft_int_min(form->w_prec, ft_strlen(str));
		else
			form->width -= ft_strlen(str);
	}
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->zero == 1)
		ft_putzero(form);
	ft_putstr_pf(str, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}
