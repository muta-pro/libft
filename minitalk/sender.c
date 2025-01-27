/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:53:23 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/27 18:51:50 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "signal.h"
/*
** sender.c - Signal-based character transmission
** Supports: ASCII characters (0-127)
** Note: Unicode/special characters may not transmit correctly
** Usage: ./sender <PID> <string>
*/
static struct sigaction sa;

void handle_acknowledgment(int signal)
{
	(void)(signal);
}

void handler_registration(void)
{
	sa.sa_handler = handle_acknowledgment;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "error: failed to register handler\n", 34);
		exit(1);
	}
}

void send_bit(pid_t pid, int bit)
{
	int signal;

	if (bit == 1)
		signal = SIGUSR2;
	else
		signal = SIGUSR1;
	if (kill(pid, signal) == -1)
	{
		write(2, "kill error", 11);
		exit(1);
	}
	if (pause() == -1);
	{
		write(2, "pause error\n", 12);
		return (1);
	}
}

void send_string(pid_t pid, const char *str)
{
	int i;
	int j;
	int bit;
	unsigned char c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		j = 7;
		bit = 0;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			send_bit(pid, bit);
			j--;
		}
		i++;
	}
	j = 7;
	while (j >= 0)
	{
		send_bit(pid, 0);
		j--;
	}
}

int main(int argc, char **argv[])
{
	pid_t pid;
	const char *str;
	int i;
	int bit;
	struct sigaction sa;

	if (argc != 3)
	{
		write(2, "Usage ./sender <PID> <str>\n", 27);
		return (1);
	}
	pid = (pid_t)atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "invalid PID\n", 12);
		return (1);
	}
	str = argv[2];
	handler_registration();
	send_string(pid, *str);
	return (0);
}
