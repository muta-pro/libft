/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:53:57 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/02 12:46:40 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *));
{
	if (node = NULL)
		return (0);
	if (del != NULL)
		del (node->content);
	free(node);
}