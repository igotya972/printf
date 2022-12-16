/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:11:15 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/14 15:48:44 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_printf(const char *format, ...)
{
	int	i;
	int	len;
	va_list	args;
	char c;

	i = 0;
	len = 0;
	va_start(args, str);
	while (format[i++])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			len += ft_printf_arg(format, i, args);
			i++;
		}
		else 
		{
			ft_putchar(c);
			i++;
		}
	}
	return (len);
}
