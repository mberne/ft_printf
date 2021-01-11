/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:16:05 by mberne            #+#    #+#             */
/*   Updated: 2021/01/11 12:39:39 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_ascii(char c, t_form *form)
{
	if (c == 'c')
		ft_conv_c(form);
	else if (c == '%')
		ft_conv_percent(form);
	else if (c == 's')
		ft_conv_s(form);
}

void	ft_conv_int(char c, t_form *form)
{
	if (c == 'd' || c == 'i')
		ft_conv_di(form);
	else if (c == 'u')
		ft_conv_u(form);
	else if (c == 'x')
		ft_conv_x_min(form);
	else if (c == 'X')
		ft_conv_x_maj(form);
	else if (c == 'p')
		ft_conv_p(form);
}

int		ft_conv(const char *str, int i, t_form *form)
{
	if (ft_strchr("cs%", str[i]))
		ft_conv_ascii(str[i], form);
	else if (ft_strchr("pdiuxX", str[i]))
		ft_conv_int(str[i], form);
	return (i);
}
