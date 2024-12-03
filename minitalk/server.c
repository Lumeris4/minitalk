/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:00:54 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/03 11:17:45 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_message = NULL;

static void	write_message(int *count, int *i, int *pid_client, int *s_size)
{
	if (*count == *s_size)
	{
		usleep(200);
		kill(*pid_client, SIGUSR1);
		ft_printf("%s\n", g_message);
		free(g_message);
		*count = 0;
		*i = 0;
		*pid_client = 0;
		*s_size = 0;
	}
}

static void	handler(int signum)
{
	static int	i = 0;
	static int	pid_client = 0;
	static int	s_size = 0;
	static int	count = 0;
	static int	byte = 0;

	if (count == 0 && i == 0)
		g_message = NULL;
	if (pid_client == 0)
		get_int(signum, &pid_client);
	else if (s_size == 0)
		get_int(signum, &s_size);
	else
	{
		str_alloc(s_size, pid_client);
		if (signum == SIGUSR2)
			byte += 1 << (7 - i);
		next_byte(&i, &count, &byte);
		write_message(&count, &i, &pid_client, &s_size);
	}
}

int	main(void)
{
	ft_printf("SERVER PID : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
