/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddias-mo <ddias-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:49:02 by ddias-mo          #+#    #+#             */
/*   Updated: 2024/05/17 17:24:29 by ddias-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}
/* int main(void)
{
	t_list *lst = NULL;
	t_list *node1 = ft_lstnew("Hello");
	t_list *node2 = ft_lstnew("World");
	
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	node2->next = NULL;
	while(lst)
	{
		printf("%s||\n", (char *)lst->content); // imprime o conteudo do no atual
		lst = lst->next; // avanca para o proximo no
	}
	free(node1);
	free(node2);
} */