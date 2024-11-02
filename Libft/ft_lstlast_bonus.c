/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:52:37 by litang            #+#    #+#             */
/*   Updated: 2024/11/02 16:03:02 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//returns the last node of the list
//*lst points to first node
//return last node
//traverse the list to find the last node
t_list	*ft_lstlast(t_list *lst)
{
	if (lst = NULL)
		return (NULL);
	while (lst->next != NULL)//traverse
		lst = lst->next;
	return (lst);//last node lst->next is NULL
}
