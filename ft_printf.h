/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:38:05 by mberne            #+#    #+#             */
/*   Updated: 2021/01/20 13:48:59 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_MAJ "0123456789ABCDEF"
# define HEX_MIN "0123456789abcdef"
# define DEC "0123456789"

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_form
{
	va_list	*ap;
	int		zero;
	int		minus;
	int		hashtag;
	int		space;
	int		plus;
	int		width;
	int		prec;
	int		w_prec;
	int		return_print;
	char	spec;
}				t_form;

int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));
void			init_struct(t_form *form, va_list *ap);
int				ft_flags(const char *str, int i, t_form *form);
int				ft_width(const char *str, int i, t_form *form);
int				ft_prec(const char *str, int i, t_form *form);
int				ft_conv(char c, int i, t_form *form);
void			ft_conv_c(t_form *form);
void			ft_conv_percent(t_form *form);
void			ft_conv_s(t_form *form);
int				ft_compare(long long x, int intlen, t_form *form);
void			ft_conv_di(t_form *form);
void			ft_conv_u(t_form *form);
void			ft_conv_x_min(t_form *form);
void			ft_conv_x_maj(t_form *form);
void			ft_conv_p(t_form *form);
void			ft_putspace(t_form *form);
void			ft_putzero(t_form *form);
long int		ft_putsign(long int x, t_form *form);
void			ft_putchar_pf(char c, t_form *form);
void			ft_putstr_pf(char *s, t_form *form);
void			ft_putnbr_pf(long int n, char *base, t_form *form);
void			ft_putpointer(unsigned long long p, t_form *form);
int				ft_intlen_base(long int n, char *base);
int				ft_intlen_pointer(unsigned long long n, char *base);
int				ft_int_max(int i, int j);
int				ft_int_min(int i, int j);
int				check_define(void);

#endif
