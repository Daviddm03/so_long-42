/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:34:17 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/21 22:35:55 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
/* int	main(void)
{
	char	s[] = "Hello, World!";

	printf("%s\n", (char *)ft_memset(s, 'X', 5));
} */