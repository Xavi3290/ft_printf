/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:54:48 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/02/01 17:31:00 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		(*len)++;
	return (0);
}

int	ft_putstr(char *s, int *len)
{
	int	i;

	if (!s)
	{
		if (ft_putstr("(null)", len) == -1)
			return (-1);
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (ft_putchar(s[i], len) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
