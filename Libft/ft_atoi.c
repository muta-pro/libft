/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:17:16 by imutavdz          #+#    #+#             */
/*   Updated: 2024/10/15 12:18:18 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;
	int	sign_count;

	result = 0;
	i = 0;
	sign = 1;
	sign_count = 0;

	while ((str[i] > 6 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign_count++;
		i++;
	}
	if (sign_count % 2 != 0)
		sign = -1;
	while(str[i] >= '0' && str[i] < '9')
		result = result * 10 + (str[i++] - '0');
	return result * sign;
}
