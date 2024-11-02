/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:47:34 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 15:58:33 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//This function inserts a new node at the start of the list, updating head
//lst is pointer to a pointer of head node
//new is pointer to new node to add
//no return value
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return (NULL);//to ensure there is node to add
	new->next = *head;//link the new node to current head
	*lst = new;//updates head to point to new, creating new head
}
