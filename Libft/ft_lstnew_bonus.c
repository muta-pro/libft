/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:14:48 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 15:58:41 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//This function allocates memory for a new node, sets its content
//initializes next to NULL.
t_list	*ft_lstnew(void *content)//Function to create a new node 
{
	t_list	*start;//pointer to new node we are creating

	start = (t_list *)malloc(sizeiof(t_list));//allocate new node
	if (node == NULL)//check if malloc succeeded
		return (NULL);
	//initialization
	start->content = content;//setting content in the node
	start->next = NULL;//init next pointer to NULL
	return (start);//return new node address
}
