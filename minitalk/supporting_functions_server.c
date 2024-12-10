/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supporting_functions_server.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelanglo <lelanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:01:49 by lelanglo          #+#    #+#             */
/*   Updated: 2024/12/10 16:01:53 by lelanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

extern char	*g_message;

void	get_int(int signum, int *value)
{
	static int	result = 0;
	static int	i = 0;

	if (signum == SIGUSR2)
		result += 1 << (31 - i);
	i++;
	if (i == 32)
	{
		*value = result;
		result = 0;
		i = 0;
	}
}

void	str_alloc(int s_size, int pid_client)
{
	if (g_message == NULL && s_size > 0)
	{
		g_message = malloc(s_size * sizeof(char));
		if (g_message == NULL)
		{
			kill(pid_client, SIGUSR2);
			free(g_message);
			exit(0);
		}
	}
}

void	next_byte(int *i, int *count, int *byte)
{
	if (++(*i) == 8)
	{
		*i = 0;
		g_message[*count] = *byte;
		(*count)++;
		*byte = 0;
	}
}
