/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:28:03 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/17 18:17:47 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*cont;

	new = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		temp = ft_lstnew(cont);
		if (!temp)
		{
			del(cont);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}

/* void	*ft_lowercase(void *content)
{
	size_t	i;
	char	*str;

	str = (char *)content;
	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (content);
}

void	del(void *content)
{
	if (content)
		free(content);
}

int	main(void)
{
	t_list  *lst;
	t_list  *node1;
	t_list  *node2;
	t_list  *map_lst;

	lst = NULL;
	node1 = ft_lstnew(ft_strdup("TESTE1"));
	node2 = ft_lstnew(ft_strdup("TESTE2"));
	ft_lstadd_front(&lst, node1);
	ft_lstadd_back(&lst, node2);

	map_lst = ft_lstmap(lst, (void *)ft_lowercase, del);
	printf("%s\n", (char *)map_lst->content);
	map_lst = map_lst->next;
	printf("%s\n", (char *)map_lst->content);
}  */
