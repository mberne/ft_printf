/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:56:25 by mberne            #+#    #+#             */
/*   Updated: 2021/01/25 08:54:23 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_di(t_form *form)
{
	long int	x;
	int			intlen;

	x = va_arg(*(form->ap), int);
	intlen = ft_intlen_base(x, DEC);
	intlen = ft_compare(x, intlen, form);
	if (form->width && form->minus == 0)
		ft_putspace(form);
	x = ft_putsign(x, form);
	if (form->prec)
		ft_putzero(form);
	if (intlen)
		ft_putnbr_pf(x, DEC, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_u(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, DEC);
	intlen = ft_compare(x, intlen, form);
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->prec)
		ft_putzero(form);
	if (intlen)
		ft_putnbr_pf(x, DEC, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_x_min(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, HEX_MIN);
	intlen = ft_compare(x, intlen, form);
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->hashtag && x != 0)
	{
		ft_putstr_fd("0x", 1);
		form->return_print += 2;
	}
	if (form->prec)
		ft_putzero(form);
	if (intlen)
		ft_putnbr_pf(x, HEX_MIN, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_x_maj(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, HEX_MAJ);
	intlen = ft_compare(x, intlen, form);
	if (form->width && form->minus == 0)
		ft_putspace(form);
	if (form->hashtag && x != 0)
	{
		ft_putstr_fd("0X", 1);
		form->return_print += 2;
	}
	if (form->prec)
		ft_putzero(form);
	if (intlen)
		ft_putnbr_pf(x, HEX_MAJ, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}

void	ft_conv_p(t_form *form)
{
	unsigned long long	x;
	int					intlen;

	x = (unsigned long long)va_arg(*(form->ap), void *);
	intlen = ft_intlen_pointer(x, HEX_MIN);
	intlen = ft_compare(x, intlen, form);
	if (form->width && form->minus == 0)
		ft_putspace(form);
	ft_putstr_fd("0x", 1);
	form->return_print += 2;
	if (form->prec)
		ft_putzero(form);
	if (intlen)
		ft_putpointer(x, form);
	if (form->width && form->minus == 1)
		ft_putspace(form);
}
