/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:50:34 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/09 15:00:29 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int len_line(t_list *list)//count all the chars in list until \n
{
	int i;
	int len;

	if (NULL == list)
		return (NULL);
	len = 0;
	while (list)
	{
		i = 0;//everytime start from zero count for the new node
		while (list->str_buf[i] != 0)//char inside string of node 
		{
			if (list->str_buf[i] == '\n')// if char is newline we increase len
			{
				++len;//we want to include the newline char
				return (len);
			}
			++i;//if it's not newline char - loop inside linklist we update i
			++len;
		}
		list = list->next;//go to final node
	}
	return (len);
}

void ft_strcpy(t_list *list, char *new_str)
{
	int i;
	int k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->str_buf[i]) //until I have a char
		{
			if (list->str_buf[i] == '\n') //check if char index is newline char
				{
					new_str[k++] = '\n'; //copy '\n' char at the stirng end
					new_str[k] = '\0'; //append nul terminator after newline
					return ;
				}
				new_str[k++] = list->str_buf[i++]; //simple cpy of string
		}
		list = list->next;// here we move to the next node
	}
	new_str[k] = '\0';
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int				i;
// 	unsigned char	uc;

// 	uc = (unsigned char)c;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == uc)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (uc == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
//}