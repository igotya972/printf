/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:11:15 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/16 17:02:17 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;
	char c;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			len += ft_flags(args, format[i + 1]);
			i += 2;
		}
		else 
		{
			ft_putchar(c);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
