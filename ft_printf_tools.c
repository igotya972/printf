/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:37:16 by dferjul           #+#    #+#             */
/*   Updated: 2022/12/17 15:06:37 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	while (nb)
		i++;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
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
	return (i);
}

int	ft_putnbr_unsint(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb != 0)
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

int	ft_pl(unsigned long long nb, char *base)
{
	int			len;
	unsigned long long	n;

	n = nb;
	len = 2;
	write (1, "0x", 1);
	if (nb == 0)
		len++;
	if (nb > 15)
	{
		ft_putlong(nb / 16, base);
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
