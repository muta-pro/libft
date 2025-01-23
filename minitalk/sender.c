/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:53:23 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/23 14:37:43 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

void send_bit(int pid, char bit)
{
	if (bit)
	{
		printf("sedning 1 (SIGUSR1)\n");
		if (kill(pid, SIGUSR1) == -1)
		{
			write(2, "Error sending signal\n", 21);
			exit (1);
		}
	}
		else
		{
			printf("sedning 0 (SIGUSR\n");
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error sending signal\n", 21);
				exit (1);
			}
		}
		usleep (200);
	}

void send_char(int pid, char c)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		send_bit(pid, (c >> i) & 1);
		i--;
	}
	usleep(100);
}

int main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		write(2, "usage: ./client [pid] [message]\n", 38);
		return 1;
	}
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "error, invalid PID\n", 18);
		return (1);
	}
	printf("sedning to PID: %d\n", pid);
	message = argv[2];
	printf("Message to send: %s\n", message);
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
	printf("Message sent complitely\n");
	return (0);
}
