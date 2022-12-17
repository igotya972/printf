/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:30 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/17 15:06:31 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_flags(va_list args, char flags)
{
	if (flags == '%')
		return (ft_putchar('%'));
	if (flags == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flags == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flags == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (flags == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (flags == 'u')
		ft_putnbr_unsint(va_arg(args, unsigned int));
	if (flags == 'x')
		return (ft_putconv(va_arg(args, unsigned int), "0123456789abcdef"));
	if (flags == 'X')
		return (ft_putconv(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (flags == 'p')
		return (ft_pl(va_arg(args, unsigned long long), "0123456789abcdef"));
	return (0);
}
