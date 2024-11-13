/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:05:06 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/06/06 21:33:49 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char spec, va_list arg)
{
	int	cnt;

	cnt = 0;
	if (spec == 'c')
		cnt += ft_putchar(va_arg(arg, int));
	else if (spec == 's')
		cnt += ft_putstr(va_arg(arg, char *));
	else if (spec == 'p')
		cnt += ft_putptr(va_arg(arg, unsigned long));
	else if (spec == 'd' || spec == 'i')
		cnt += ft_putnbr(va_arg(arg, int));
	else if (spec == 'u')
		cnt += ft_putuns(va_arg(arg, unsigned int));
	else if (spec == 'X')
		cnt += ft_puthex((va_arg(arg, unsigned int)), 'X');
	else if (spec == 'x')
		cnt += ft_puthex((va_arg(arg, unsigned int)), 'x');
	else if (spec == '%')
		cnt += ft_putchar('%');
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		cnt;

	va_start(arg, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			cnt += ft_format(*format, arg);
		}
		else
			cnt += ft_putchar(*format);
		++format;
	}
	va_end(arg);
	return (cnt);
}
