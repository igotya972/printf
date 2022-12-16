/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:37:16 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/16 16:31:45 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;
	char	*str;

	i = 0;
	while (str[i])
		i++;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (i)
}

int	ft_putnbr_unsint(unsigned int nb, char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	if (nb < 9)
	{
		ft_putnbr_unsint(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
	return (i);
}

int	ft_putconv(unsigned int p, char *s)
{
	int	len;

	len = 0;
	if (p > 15)
	{
		ft_putconv(p / 16, s);
		len++;
		ft_putchar(s[p]);
	}
	else
	{
		len++;
		ft_putchar(s[p]);
	}
	return (len);
}

int	ft_putlong(unsigned long long nb, int len, char *base)
{
	unsigned long long n;

	n = nb;
	len = 2;
	write (1, "0x", 1);
	if (nb == 0)
		len++;
	if (nb > 15)
	{
		ft_putlong(nb / 16, len, base);
		ft_putchar(base[nb % 16]);
	}
	else
		ft_putchar(base[nb % 16]);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
