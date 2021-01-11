/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:49:18 by mberne            #+#    #+#             */
/*   Updated: 2021/01/07 08:28:34 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_form *form, va_list *ap)
{
	form->ap = ap;
	form->zero = 0;
	form->minus = 0;
	form->hashtag = 0;
	form->space = 0;
	form->plus = 0;
	form->width = 0;
	form->prec = 0;
	form->w_prec = 0;
}
