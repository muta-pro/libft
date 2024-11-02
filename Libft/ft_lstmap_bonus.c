/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:55:45 by litang            #+#    #+#             */
/*   Updated: 2024/11/02 16:37:06 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//iterates over each node
//applies a specific funciton f to each content
//stores the result in new list of nodes
//creates transforemed versions of list not modifying the original
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;//pointer to new head
	t_list	*new_node;//pointer to each new node

	new_lst = NULL;//initialize as empty list
	while (lst! = NULL)//iterate each node in original list
	{
		new_node = ft_lstnew(f(lst->content));//f to create content for new node
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);//clear already created nodes
			return (NULL);//if allocation fails
		}
		ft_lstadd_back(&new_lst, new_node);//add new node to end of new_lst
		lst = lst->next;//move to next node in original list
	}
	return (new_lst);//the new list
}
