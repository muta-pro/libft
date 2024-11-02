/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:53:16 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 16:17:55 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//This function appends a new node to the list’s end
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return (NULL);//if new node is null, no adding
	if(*lst == NULL)//if list empty, set new as first
	{
		*lst = new;
		return (NULL);
	}
	last = *lst;//start from the head of the list
	while (current->next ! NULL)//traverse to last node
		last = last->next;
	last->next = new;//set last node's next pointer to new
}
