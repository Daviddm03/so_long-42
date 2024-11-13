/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:03:05 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/17 19:37:25 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	cpy;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0 || dst == NULL)
		return (i);
	cpy = 0;
	while (src[cpy] != '\0' && cpy < size - 1)
	{
		dst[cpy] = src[cpy];
		cpy++;
	}
	dst[cpy] = '\0';
	return (i);
}

/* int	main(void)
{
	const char	src[]= "Hello";
	char		dest[100];

	ft_strlcpy(dest, src, 4);
	printf("before: %s\n", src);
	printf("after: %s\n", dest);
} */
