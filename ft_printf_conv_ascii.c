/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:33:22 by mberne            #+#    #+#             */
/*   Updated: 2021/01/12 09:33:59 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_form *form)
{
	if (form->width)
	{
		form->width -= 1;
		if (form->minus == 1)
		{
			ft_putchar_pf(va_arg(*(form->ap), int), form);
			ft_putspace(form);
		}
		else if (form->minus == 0 && form->zero == 0)
		{
			ft_putspace(form);
			ft_putchar_pf(va_arg(*(form->ap), int), form);
		}
		else if (form->minus == 0 && form->zero == 1)
		{
			ft_putzero(form);
			ft_putchar_pf(va_arg(*(form->ap), int), form);
		}
	}
	else
		ft_putchar_pf(va_arg(*(form->ap), int), form);
}

void	ft_conv_percent(t_form *form)
{
	if (form->width)
	{
		form->width -= 1;
		if (form->minus == 1)
		{
			ft_putchar_pf('%', form);
			ft_putspace(form);
		}
		else if (form->minus == 0 && form->zero == 0)
		{
			ft_putspace(form);
			ft_putchar_pf('%', form);
		}
		else if (form->minus == 0 && form->zero == 1)
		{
			ft_putzero(form);
			ft_putchar_pf('%', form);
		}
	}
	else
		ft_putchar_pf('%', form);
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
		if (form->minus == 1)
		{
			ft_putstr_pf(str, form);
			ft_putspace(form);
		}
		else if (form->minus == 0 && form->zero == 0)
		{
			ft_putspace(form);
			ft_putstr_pf(str, form);
		}
		else if (form->minus == 0 && form->zero == 1)
		{
			ft_putzero(form);
			ft_putstr_pf(str, form);
		}
	}
	else
		ft_putstr_pf(str, form);
}
