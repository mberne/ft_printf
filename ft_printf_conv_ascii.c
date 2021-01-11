/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_ascii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:33:22 by mberne            #+#    #+#             */
/*   Updated: 2021/01/11 13:33:03 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(t_form *form)
{
	if (form->width)
	{
		form->width -= 1;
		if (form->width >= 0 && form->minus == 1)
		{
			ft_putchar_pf(va_arg(*(form->ap), int), form);
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
		if (form->width >= 0 && form->minus == 1)
		{
			ft_putchar_pf('%', form);
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
			ft_putchar_pf('%', form);
		}
	}
	else
		ft_putchar_pf('%', form);
}

void	ft_conv_s(t_form *form)
{
	char *str;

	str = va_arg(*(form->ap), char *);
	if (form->width)
	{
		form->width -= ft_int_min(form->w_prec, ft_strlen(str));
		if (form->width >= 0 && form->minus == 1)
		{
			ft_putstr_pf(str, form);
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
			ft_putstr_pf(str, form);
		}
	}
	else
		ft_putstr_pf(str, form);
}
