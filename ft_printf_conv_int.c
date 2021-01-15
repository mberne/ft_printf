/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 09:56:25 by mberne            #+#    #+#             */
/*   Updated: 2021/01/15 18:01:45 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_di(t_form *form)
{
	long int	x;
	int			intlen;

	x = va_arg(*(form->ap), int);
	intlen = ft_intlen_base(x, DEC);
	if (form->width)
	{
		ft_compare(x, intlen, form);
		if ((form->minus == 0 && form->zero == 0) || (form->w_prec >= intlen && form->minus == 0 && form->zero == 1))
			ft_putspace(form);
		x = ft_putsign(x, form);
		if (form->prec == 0 && form->minus == 0 && form->zero == 1)
			ft_putzero(form);
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, DEC, form);
		if (form->minus == 1)
			ft_putspace(form);
	}
	else
	{
		x = ft_putsign(x, form);
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, DEC, form);
	}
}

void	ft_conv_u(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, DEC);
	if (form->width)
	{
		form->width -= ft_int_max(form->w_prec, intlen);
		if ((form->minus == 0 && form->zero == 0) || (form->w_prec >= intlen && form->minus == 0 && form->zero == 1))
			ft_putspace(form);
		if (form->prec == 0 && form->minus == 0 && form->zero == 1)
			ft_putzero(form);
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, DEC, form);
		if (form->minus == 1)
			ft_putspace(form);
	}
	else
	{
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, DEC, form);
	}
}

void	ft_conv_x_min(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, HEX_MIN);
	if (form->width)
	{
		form->width -= ft_int_max(form->w_prec, intlen);
		if ((form->minus == 0 && form->zero == 0) || (form->w_prec >= intlen && form->minus == 0 && form->zero == 1))
			ft_putspace(form);
		if (form->hashtag)
			ft_puthashtag("0x", form);
		if (form->prec == 0 && form->minus == 0 && form->zero == 1)
			ft_putzero(form);
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, HEX_MIN, form);
		if (form->minus == 1)
			ft_putspace(form);
	}
	else
	{
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, HEX_MIN, form);
	}
}

void	ft_conv_x_maj(t_form *form)
{
	unsigned int	x;
	int				intlen;

	x = va_arg(*(form->ap), unsigned int);
	intlen = ft_intlen_base(x, HEX_MAJ);
	if (form->width)
	{
		form->width -= ft_int_max(form->w_prec, intlen);
		if ((form->minus == 0 && form->zero == 0) || (form->w_prec >= intlen && form->minus == 0 && form->zero == 1))
			ft_putspace(form);
		if (form->hashtag)
			ft_puthashtag("0X", form);
		if (form->prec == 0 && form->minus == 0 && form->zero == 1)
			ft_putzero(form);
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, HEX_MAJ, form);
		if (form->minus == 1)
			ft_putspace(form);
	}
	else
	{
		ft_putprec(intlen, form);
		ft_putnbr_pf(x, HEX_MAJ, form);
	}
}

void	ft_conv_p(t_form *form)
{
	unsigned long long	x;

	x = (unsigned long long)va_arg(*(form->ap), void *);
	if (form->width)
	{
		form->width -= ft_intlen_base(x, HEX_MIN) + 2;
		if (form->minus == 0 && form->zero == 0)
			ft_putspace(form);
		ft_putstr_pf("0x", form);
		if (form->minus == 0 && form->zero == 1)
			ft_putzero(form);
		ft_putpointer(x, form);
		if (form->minus == 1)
			ft_putspace(form);
	}
	else
	{
		ft_puthashtag("0x", form);
		ft_putpointer(x, form);
	}
}
