/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:06 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/02/02 12:24:08 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_format_s(int i, const char *str, va_list args, int *len)
{
	char	c;
	char	*s;
	void	*p;

	if (str[i] == 'c')
	{
		c = va_arg(args, int);
		if (ft_putchar(c, len) == -1)
			return (-1);
	}
	else if (str[i] == 's')
	{
		s = va_arg(args, char *);
		if (ft_putstr(s, len) == -1)
			return (-1);
	}
	else if (str[i] == 'p')
	{
		p = va_arg(args, void *);
		if (ft_puthex((unsigned long)p, 0, len, 1) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_format_m(int i, const char *str, va_list args, int *len)
{
	unsigned int	u;

	if (str[i] == 'u')
	{
		u = va_arg(args, unsigned int);
		if (ft_putunbr(u, len) == -1)
			return (-1);
	}
	else if (str[i] == 'x')
	{
		u = va_arg(args, unsigned int);
		if (ft_puthex(u, 0, len, 0) == -1)
			return (-1);
	}
	else if (str[i] == 'X')
	{
		u = va_arg(args, unsigned int);
		if (ft_puthex(u, 1, len, 0) == -1)
			return (-1);
	}
	return (0);
}

static int	ft_format_f(int i, const char *str, va_list args, int *len)
{
	int	d;

	if (str[i] == 'd' || str[i] == 'i')
	{
		d = va_arg(args, int);
		if (ft_putnbr(d, len) == -1)
			return (-1);
	}
	else if (str[i] == '%')
	{
		if (ft_putchar('%', len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (ft_format_s(i, str, args, &len) == -1 || ft_format_m(i, str,
					args, &len) == -1 || ft_format_f(i, str, args, &len) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(str[i], &len) == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>
#include <limits.h>

int main(void)
{   
	printf("hola mundo");
	ft_printf("hola mundo");
	printf("%c\n", 'a');
	ft_printf("%c\n", 'a');
	printf("%s\n", "hola");
	ft_printf("%s\n", "hola");
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
	printf("%p\n", "");
	ft_printf("%p\n", "");
	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
	printf("%d\n", 123);
	ft_printf("%d\n", 123);
	printf("%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
	printf("%i\n", 123);
	ft_printf("%i\n", 123);
	printf("%i\n", INT_MAX);
	ft_printf("%i\n", INT_MAX);
	printf("%i\n", INT_MIN);
	ft_printf("%i\n", INT_MIN);
	printf("%u\n", 2147483647);
	ft_printf("%u\n", 2147483647);
	printf("%u\n", 25);
	ft_printf("%u\n", 25);
	printf("%u\n", -1);
	ft_printf("%u\n", -1);
	printf("%x\n", 25);
	ft_printf("%x\n", 25);
	printf("%x\n", -77777);
	ft_printf("%x\n", -77777);
	printf("%X\n",255);
	ft_printf("%X\n",255);
	printf("%X\n",-77777);
	ft_printf("%X\n",-77777);
	printf("%%\n");
	ft_printf("%%\n");
	printf("hola %d %s\n", 2, "mundo");
	ft_printf("hola %d %s\n", 2, "mundo");

    return (0);
}
*/