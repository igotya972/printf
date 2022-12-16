/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:30 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/16 17:08:01 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_flags(va_list args, char flags)
{
	if (flags == '%')
		return (ft_putchar('%'));
	if (flags == 'c')
		return (ft_putchar('c'));
	if (flags == 's')
		return (ft_putstr(va_args(args, char *)));
	if (flags == 'd')
		return (ft_putnbr(va_args(args, int)));
	if (flags == 'i')
		return (ft_putnbr(va_args(args, int)));
	if (flags == 'u')
		ft_putnbr_unsint(va_args(args, unsigned int));
	if (flags == 'x')
		return (ft_conv(va_args(args, unsigned int), "0123456789abcdef", 0));
	if (flags == 'X')
		return (ft_putconv(va_args(args, unsigned int), "0123456789ABCDEF", 0));
	if (flags == 'c')
		return (ft_putchar(va_args(args, char)));
	if (flags == 'p')
		return (ft_putlong(va_args(args, unsigned long long)));
}
