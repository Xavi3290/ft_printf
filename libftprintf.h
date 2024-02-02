/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xroca-pe <xroca-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:41 by xroca-pe          #+#    #+#             */
/*   Updated: 2024/02/02 15:44:00 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_putchar(char c, int *len);
int	ft_putstr(char *s, int *len);
int	ft_putnbr(int n, int *len);
int	ft_putunbr(unsigned int n, int *len);
int	ft_puthex(unsigned long n, int upper, int *len, int punt);

int	ft_printf(const char *format, ...);

#endif