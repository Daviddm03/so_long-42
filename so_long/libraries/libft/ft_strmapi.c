/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:46:48 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/21 22:32:23 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* char	upper_case(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		*c -= 32;;
	return c;
}

int	main(void)
{
	const char *s = "hello";

	printf("before: %s\n", s);
	char *result = ft_strmapi(s, &upper_case);
	printf("after: %s\n", result);
	free(result);

	return (0);
} */
