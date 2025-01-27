/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/27 18:51:53 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "signal.h"

void handler(int sig, siginfo_t *data, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, '\n', 1);
			exit(0);
		}
		else
		{
			write(1, &c, 1);
			c == 0;
		}
		bit++;
	}
	kill(info->si_pid, SIGUSR1);
}



int main(void)
{
	struct sigaction sa;
	sa.sa_handler = &handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO
	sigaction(SIGUSR1, &sa, NULL);
	sigemptyset(&sa_mask);
	sigaddset(&sa_mask, SIGUSR1);
	sigaddset(&sa_mask, SIGUSR2);
	pid_t pid;

	pid = getpid();
	printf("SERVER PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}

