/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:34:43 by imutavdz          #+#    #+#             */
/*   Updated: 2024/12/09 15:00:26 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char *extract_line(t_list *list)
{
	int str_len;
	char *new_str;

	if (NULL == list) //check for NUL pointers
		return (NULL);
	str_len = len_line(list);
	new_str = malloc(str_len + 1);
	if (NULL == new_str)
		return (NULL);
	ft_strcpy(list, new_str);
	return (new_str);
}

void append(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last(*list);
	next_node = malloc(sizeof(t_list));//allocate in the heap
	if (NULL == new_node) //controll of malloc success
		return ;
	if (NULL == last_node)//if my list in GNL is none, assign to list
		*list = new_node;//value of list point -1st new node of LL
	else
		last_node->next = new_node;//poiner of last node to new node
	new_node->str_buf = buf;//value of buf into str_buf
	new_node->next = NULL;//pointer of new node to null list
}

void	create_list(t_list **list, int fd)
{
	int char_read;//neccessary to place '\0' end of the stirng
	char 	*buf;

	while (!found_newline(*list)) //search inside list for char '\n'-if not-loop
	{
		buf = malloc(BUFFER_SIZE + 1);//heap stock my string
		if (NULL == buf)//checks for malloc
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);//read from fd into heap-buffer B_S
		if (!char_read) //n chars read is zer0 - EOF control
		{
			free(buf);//free the buffer and return
			return ;//EOF
		}
		buf[char_read] = '\0'; //value control to append '\0' tnx to char_read
		append(list, buf);//append buffer to a list
	}
}

void	clear_list(t_list **list)//polish LL for next CALL
{
	t_list *last_node;
	t_list *clear_node;
	int i;
	int k;
	char *buf;

	buf = malloc(BUFFER_SIZE + 1); //here we will put the last chars of last node
	clear_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clear_node)
		return ;
	last_node = find_last_node(*list);//here we search for last node
	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\0' //skip all chars before the last char
		&& last_node->str_buf[i] != '\n')//which is '\n' or nul terminator
		i++;
	while (last_node->str_buf[i] ! '\0' //condition
		&& last_node->str_buf[i++])
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clear_node-> str_buf = buf //assign to a string new buffer
	clear_node->next = NULL; //to the next string NUL
	dealloc(list, clear_node, buf); //everything get deallocated - cleaned
}

char *get_next_line_ll(int fd)
{
	static t_list	*list; //behaves like a global variable with local scope
	char			*next_line; //stock the next line

	list = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL); //checks if file can be opned (-1) - permissions
	create_list(&list, fd); //create list until '\n'
	if (list == NULL)
		return (NULL); //check if list is empty
	next_line = extract_line(list); //fetch line included '\n'
	clear_list(&list);
	return (next_line);
}
