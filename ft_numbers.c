/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:57:22 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/02/01 17:01:38 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648", len) == -1)
			return (-1);
	}
	else
	{
		if (n < 0)
		{
			n = -n;
			if (ft_putchar('-', len) == -1)
				return (-1);
		}
		if (n >= 10)
			if (ft_putnbr(n / 10, len) == -1)
				return (-1);
		if (ft_putchar((n % 10) + '0', len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_putunbr(unsigned int n, int *len)
{
	if (n >= 10)
		if (ft_putunbr(n / 10, len) == -1)
			return (-1);
	if (ft_putchar((n % 10) + '0', len) == -1)
		return (-1);
	return (0);
}

int	ft_puthex(unsigned long n, int upper, int *len, int punt)
{
	char	*hex_digits;
	char	c;

	hex_digits = "0123456789abcdef";
	if (punt == 1)
	{
		if (ft_putstr("0x", len) == -1)
			return (-1);
	}
	punt = 0;
	if (n >= 16)
		if (ft_puthex(n / 16, upper, len, punt) == -1)
			return (-1);
	c = hex_digits[n % 16];
	if (upper == 1)
	{
		if (c >= 'a' && c <= 'f')
			c -= 32;
	}
	if (ft_putchar(c, len) == -1)
		return (-1);
	return (0);
}
