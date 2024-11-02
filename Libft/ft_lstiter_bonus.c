/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:55:03 by litang            #+#    #+#             */
/*   Updated: 2024/11/02 16:08:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//applies a function f to each node's content in the list
//*lst pointer to the first node
//void (*f)(void *) pointer to a function
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
		{
			f(lst->content);//apply f to content of each node
			lst = lst->next;//move to next node
		}
}
