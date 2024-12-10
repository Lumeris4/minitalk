/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:00:42 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/10 15:36:14 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	for_str(const char *str, pid_t pid)
{
	int	i;

	i = 31;
	while (*(str - 1) || i == 31)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(50);
		}
		str++;
	}
}

static void	for_int(unsigned int size, pid_t pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((size >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(50);
	}
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Congratulations,You wrote on the server\n");
	else if (signum == SIGUSR2)
		ft_printf("Error/n");
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t			pid;
	int				size;

	if (argc != 3)
	{
		ft_printf(KRED "ENTER THE SERVER PID AND A");
		ft_printf(" STRING TO SHARE\n" KRED);
		return (0);
	}
	if (!ft_isdigit_str(argv))
		ft_printf(KRED "BE CARREFUL ENTER A VALID PID\n" KRED);
	else
	{
		size = ft_isdigit_str(argv);
		pid = ft_atoi(argv[1]);
		for_int(getpid(), pid);
		for_int(size, pid);
		for_str(argv[2], pid);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while (1)
			pause();
	}
	return (0);
}
