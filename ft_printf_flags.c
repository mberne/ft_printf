/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:46:31 by mberne            #+#    #+#             */
/*   Updated: 2021/01/12 09:01:10 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putspace(t_form *form)
{
	while (form->width > 0)
	{
		ft_putchar_pf(' ', form);
		form->width--;
	}
}

void	ft_putzero(t_form *form)
{
	while (form->width > 0)
	{
		ft_putchar_pf('0', form);
		form->width--;
	}
}
