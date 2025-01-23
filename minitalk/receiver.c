/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imutavdz <imutavdz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:44 by imutavdz          #+#    #+#             */
/*   Updated: 2025/01/23 14:41:07 by imutavdz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "signal.h"

#define BUFFER_SIZE 1024

static char g_char = 0;
static int g_bits_received = 0;

// void handle_signal(int signal, siginfo_t *info, void *more in )//decide what happens when specific signal arrives
// {
// 	static char g_char;
// 	static int bit_count;

// 	g_char = 0;
// 	bit_count = 0;
// 	g_char = g_char << 1;
// 	if (signal == SIGUSR1)
// 	{
// 		g_char = g_char | 1;
// 		printf("received 1\n");
// 	}
// 	else
// 		printf("received 0\n");
// 	bit_count++;
// 	if (g_bits_received == 8)
// 	{
// 		if (g_char =='\0')
// 		{
// 			write(1, "\n", 1);
// 			printf("received complete message\n");
// 		}
// 		else
// 		{
// 			write(1, &g_char, 1);
// 			printf("received character: %c\n", g_char);
// 		}
// 		g_char = 0;
// 		bit_count = 0;

// 	}
// }

int main(void)
{
	struct sigaction sa;
	pid_t pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	// sa.sa_handler = handle_signal;
	// sa.sa_flags = 0;
	// sigemptyset(&sa.sa_mask);
	// if (sigaction(SIGUSR1, &sa, NULL) == -1)
	// {
	// 	write(2, "Error: no SIGUSR1 handler set up", 32);
	// 	return (1);
	// }
	// if (sigaction(SIGUSR2, &sa, NULL) == -1)
	// {
	// 	write(2, "Error: no SIGUSR2 handler set up", 32);
	// }
	while (1) //wait for signals indefinetly
		pause();
		printf("Signal received and handled/n"); 

	return (0);
}
