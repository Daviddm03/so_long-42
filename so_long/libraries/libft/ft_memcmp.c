/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:34:43 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/17 19:02:12 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/* int main()
{
    unsigned char   buffer1[] = {"Hello Worlb"};
    unsigned char   buffer2[] = {"Hello World"};

    size_t size = sizeof(buffer1);

    printf("Original: %d\n", memcmp(buffer1, buffer2, size));
    printf("Libft: %d\n", ft_memcmp(buffer1, buffer2, size));
} */
