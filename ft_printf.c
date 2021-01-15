/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:36:56 by mberne            #+#    #+#             */
/*   Updated: 2021/01/15 17:28:11 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv(char c, int i, t_form *form)
{
	if (c == 'c')
		ft_conv_c(form);
	else if (c == '%')
		ft_conv_percent(form);
	else if (c == 's')
		ft_conv_s(form);
	else if (c == 'd' || c == 'i')
		ft_conv_di(form);
	else if (c == 'u')
		ft_conv_u(form);
	else if (c == 'x')
		ft_conv_x_min(form);
	else if (c == 'X')
		ft_conv_x_maj(form);
	else if (c == 'p')
		ft_conv_p(form);
	return (i);
}

int		ft_prec(const char *str, int i, t_form *form)
{
	int x;

	x = 0;
	if (str[i] == '.')
	{
		form->prec = 1;
		i++;
		if (str[i] == '*')
		{
			if ((x = va_arg(*(form->ap), int)) < 0)
				form->prec = 0;
			else
				form->w_prec = x;
			i++;
		}
		else if (ft_isdigit(str[i]) == 1)
		{
			form->w_prec = ft_atoi(str + i);
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
	}
	i = ft_conv(str[i], i, form);
	return (i);
}

int		ft_width(const char *str, int i, t_form *form)
{
	int x;

	x = 0;
	if (str[i] == '*')
	{
		if ((x = va_arg(*(form->ap), int)) < 0)
		{
			x = -x;
			form->minus = 1;
		}
		form->width = x;
		i++;
	}
	else if (ft_isdigit(str[i]) == 1)
	{
		form->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	i = ft_prec(str, i, form);
	return (i);
}

int		ft_flags(const char *str, int i, t_form *form)
{
	while (ft_strchr("0-# +", str[i]))
	{
		if (str[i] == '0')
		{
			form->zero = 1;
			i++;
		}
		if (str[i] == '-')
		{
			form->minus = 1;
			i++;
		}
		if (str[i] == '#')
		{
			form->hashtag = 1;
			i++;
		}
		if (str[i] == ' ')
		{
			form->space = 1;
			i++;
		}
		if (str[i] == '+')
		{
			form->plus = 1;
			i++;
		}
	}
	i = ft_width(str, i, form);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	t_form	form;

	if (check_define() != 0)
		return (-1);
	if (!str)
		return (0);
	i = 0;
	form.return_print = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_pf(str[i], &form);
		else
		{
			init_struct(&form, &ap);
			i = ft_flags(str, i + 1, &form);
		}
		i++;
	}
	va_end(ap);
	return (form.return_print);
}
