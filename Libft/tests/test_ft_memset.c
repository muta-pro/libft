/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:55:43 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/29 14:23:45 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <assert.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len);

void test_ft_memset()
{
	//basic test
	unsigned char buffer1[10] = {0};
	ft_memset(buffer1, 'A', 5);
	assert(buffer1[0] == 'A' && buffer1[4] == 'A' && buffer1[5] == 0);

	//entire buffer set
	unsigned char buffer2[10] = {0};
	ft_memset(buffer2, 'B', 10);
	for (int i = 0; i < 10; i++) assert(buffer2[i] == 'B');

	//Fill with null (0)
	unsigned char buffer3[10] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};
	ft_memset(buffer3, 0, 10);
	for (int i = 0; i < 10; i++) assert(buffer3[i] == 0);

	//non printeble
	unsigned char buffer4[10];
	ft_memset(buffer4, 127, 10); //DEL ASCII
	for (int i = 0; i < 10; i++) assert(buffer4[i] == 127);

	//zero lenght
	unsigned char buffer5[10] = {'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C'};
	ft_memset(buffer5, 'z', 0);
	for (int i = 0; i < 10; i++) assert(buffer5[i] == 'C');

	//fill negative byte
	unsigned char buffer6[10];
	ft_memset(buffer6, -1, 10);
	for (int i = 0; i < 10; i++)
	printf("buffer6[%d] = %d\n", i, buffer6[i]);
	for (int i = 0; i < 10; i++)
	assert(buffer6[i] == 0xFF);

	//one byte len
	unsigned char buffer7[10] = {0};
	ft_memset(buffer7, 'q', 1);
	for (int i = 0; i < 10; i++) 
		printf("buffer7[%d] = %d\n", i, buffer7[i]);
	assert(buffer7[0] == 'q' && buffer7[2] == 0);

	//large fill
	unsigned char XLbuffer[100] = {0};
	ft_memset(XLbuffer, 'A', 100);
	for (int i = 0; i < 100; i++) assert(XLbuffer[i] == 'A');

}
int main()
{
	test_ft_memset();
	printf("All tests passed!\n");
	return (0);
}
