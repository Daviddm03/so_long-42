/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:32:54 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/30 21:23:09 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		cnt += ft_putstr("(null)");
	else
	{
		while (str[cnt])
		{
			ft_putchar(str[cnt]);
			cnt++;
		}
	}
	return (cnt);
}
