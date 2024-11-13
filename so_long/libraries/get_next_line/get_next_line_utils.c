/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:28:13 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/08/25 22:30:15 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strleng(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str && str[i] != (char)c)
	{
		if (!str[i])
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(char) * (ft_strleng((char *)s)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc(((ft_strleng((char *)s1) + ft_strleng((char *)s2))
				+ 1), sizeof(char));
	if (str == 0)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	free((void *)s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
