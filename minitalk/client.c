/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:00:42 by lelanglo          #+#    #+#             */
/*   Updated: 2024/11/25 15:01:35 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	for_int(unsigned int size, pid_t pid)
{
	int	i;
	
	i = 31
	while (i >= 0)
	{
		if ((size >> 1) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

static void	for_str(const char *str, pid_t pid)
{
	int	i;
	
	i = 31
	while (*(str - 1) || i == 31)
	{
		i = 7
		while (i >= 0)
		{
			if ((*str >> 1) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(100);
		}
		str++;
	}
}


int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf(KRED "ENTER THE SERVER PID AND A");
		ft_printf(" STRING TO SHARE\n" KRED);
		return (0);
	}
	if (!ft_isdigit_str(argv[1]))
		ft_printf(KRED "BE CARREFUL ENTER A VALID PID\n" KRED);
	else
	{
		size = ft_isdigit_str(argv[1]);
		pid = ft_atoi(argv[1]);
		sent_int(size, pid);
		send_str(argv[2], pid);
		signal(SIGUSR1);
		signal(SIGUSR2);
		ft_printf("Waiting for response...\n");
		while(1)
			pause();
	}
	return (0);
}

