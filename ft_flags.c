/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:55:30 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/11 02:20:30 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_flags(va_list args, char flags)
{
	if (flags == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (flags == 'c')
	{
		write(1, &flags, 1);
		return (1);
	}
	if (flags == 's')
		return (ft_putstr(va_args(args, char *)));
	if (flags == 'd')
		return (ft_putnbr(va_args(args, int)));
	if (flags == 'i')
		return (ft_putnbr(va_args(args, int)));
	if (flags == 'u')
		return (ft_putnbr_unsint(va_args(args, unsigned int)));
	if (flags == 'x')
		return (ft_putnbr_unsint(va_args(args, unsigned int)));
	if (flags == 'c')
		return (ft_putchar(va_args(args, int)));
	
}
