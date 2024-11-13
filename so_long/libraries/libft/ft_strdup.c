/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:30:24 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/17 19:14:57 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (new == NULL)
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

/* int main()
{
	char str_old[] = "gremio gigantesco";
	char *dup_str = strdup(str_old);
	printf("str old:%s\n", str_old);
	printf("str dup:%s\n", dup_str);
	free (dup_str);
	return (0);
} */