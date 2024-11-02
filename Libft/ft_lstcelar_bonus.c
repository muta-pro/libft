/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcelar_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:54:23 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 16:13:39 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//deletes and frees all nodes from a list starting from a given node
void	ft_lstcelar(t_list **lst, void (*del)(void *));
{
	t_list	*store;

	while (*lst != NULL)
	{
		store = (*lst)->next;//store next node
		del(*head, del);//free content using del func
		free(*lst);//free node itself
		*lst = store;//move to next node
	}
	*lst = NULL;//set the list pointer to NULL
}
