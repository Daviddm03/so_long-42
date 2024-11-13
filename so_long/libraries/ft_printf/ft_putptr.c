/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:35:28 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/30 21:01:03 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return (ft_putstr("(nil)"));
	cnt += ft_putstr("0x");
	cnt += ft_puthex(str, 'x');
	return (cnt);
}
