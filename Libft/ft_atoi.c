/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:17:16 by imutavdz          #+#    #+#             */
/*   Updated: 2024/11/04 17:42:08 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//converts a string(arr of char) to an integer.
//ARG Input string to convert
//RTRN int - converted integer subtracting '0' from each char
int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)//skip white pace
		i++;
	if (str[i] == '+' || str[i] == '-')//check for a sign
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')//convert chat to int
		result = result * 10 + (str[i++] - '0');//*10 to shift to left char
	return (result * sign);
}
