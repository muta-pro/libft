/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:03:49 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/02 18:51:00 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <assert.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int result = ft_printf("The answer is %s\n", "yes");
	int expected = printf("The answer is %s\n", "yes");
	assert(result == expected);
	return (0);
}