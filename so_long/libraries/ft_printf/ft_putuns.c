/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:58:23 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/30 21:09:59 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(unsigned int nb)
{
	int	cnt;

	cnt = 0;
	if (nb > 9)
	{
		cnt += ft_putnbr(nb / 10);
	}
	cnt += ft_putchar(nb % 10 + 48);
	return (cnt);
}
